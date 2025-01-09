// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// downInPutMC
double downInPutMC(int nSim, double S0, double K, double r, double sigma, double T, double B);
RcppExport SEXP _downInPutMC_downInPutMC(SEXP nSimSEXP, SEXP S0SEXP, SEXP KSEXP, SEXP rSEXP, SEXP sigmaSEXP, SEXP TSEXP, SEXP BSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nSim(nSimSEXP);
    Rcpp::traits::input_parameter< double >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type T(TSEXP);
    Rcpp::traits::input_parameter< double >::type B(BSEXP);
    rcpp_result_gen = Rcpp::wrap(downInPutMC(nSim, S0, K, r, sigma, T, B));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_hello
List rcpp_hello();
RcppExport SEXP _downInPutMC_rcpp_hello() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpp_hello());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_downInPutMC_downInPutMC", (DL_FUNC) &_downInPutMC_downInPutMC, 7},
    {"_downInPutMC_rcpp_hello", (DL_FUNC) &_downInPutMC_rcpp_hello, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_downInPutMC(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}