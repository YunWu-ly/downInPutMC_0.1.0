#include <Rcpp.h>  // Include the Rcpp library to enable the integration of C++ with R.
#include <cmath>   // Include cmath to access standard mathematical functions like sqrt.
using namespace Rcpp;  // Use the Rcpp namespace to simplify function calls.

// [[Rcpp::export]]  // Export the function to R so it can be called directly from R scripts.
double downInPutMC(int nSim, double S0, double K, double r, double sigma, double T, double B) {

  // Step 1: Define variables
  double dt = T / 252;  // Time step: Divide the time to maturity by 252 (assumes 252 trading days per year).
  double payoffSum = 0.0;  // Initialize the sum of discounted payoffs from all simulations to zero.

  // Step 2: Monte Carlo simulation loop over all paths
  for (int i = 0; i < nSim; ++i) {

    double S = S0;  // Reset the stock price to the initial price S0 for each simulation path.
    bool hitBarrier = false;  // Track whether the path hits the barrier (default is false).

    // Step 3: Simulate the stock price path over 252 trading days
    for (int t = 0; t < 252; ++t) {  // Loop through each day in the simulation (252 days).
      double z = R::rnorm(0, 1);  // Generate a random number from a standard normal distribution.
      S *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);  // Update the stock price using the GBM formula.

      // Step 4: Check if the stock price hits the barrier
      if (S <= B) {  // If the stock price is equal to or below the barrier, the option "knocks in".
        hitBarrier = true;  // Mark that the barrier was hit.
        break;  // Exit the daily loop as the barrier condition is met.
      }
    }

    // Step 5: If the barrier was hit, calculate the payoff at maturity
    if (hitBarrier) {
      double payoff = std::max(K - S, 0.0);  // Calculate the payoff as max(K - S_T, 0).
      payoffSum += payoff * exp(-r * T);  // Discount the payoff to present value and add it to the cumulative sum.
    }
  }

  // Step 6: Calculate the average of the discounted payoffs
  return payoffSum / nSim;  // Return the average discounted payoff as the estimated option price.
}
