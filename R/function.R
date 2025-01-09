#' Down-and-In Put Option Pricer
#' @param nSim Number of simulations
#' @param S0 Initial stock price
#' @param K Strike price
#' @param r Risk-free interest rate
#' @param sigma Volatility
#' @param T Time to maturity
#' @param B Barrier level
#' @return Option price
#' @export
#' @useDynLib downInPutPackage
#' @importFrom Rcpp sourceCpp
NULL

