#include<bits/stdc++.h>

double norm_cdf(double x);

double inter_d1(double S, double K, double T, double r, double sigma);

double inter_d2(double S, double K, double T, double r, double sigma);

double black_scholes_call(double S, double K, double T, double r, double sigma);

double black_scholes_put(double S, double K, double T, double r, double sigma);

double greeks_delta(double S, double K, double T, double r, double sigma);

double greeks_gamma(double S, double K, double T, double r, double sigma);

double greeks_theta(double S, double K, double T, double r, double sigma);

double greeks_vega(double S, double K, double T, double r, double sigma);