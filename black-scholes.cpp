#include "black-scholes.hpp"

/*
S spot price
K strike price
T time to expiration
r risk-free rate
sigma - volatility
*/

double norm_cdf(double x)
{
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double norm_pdf(double x)
{
    
}

double inter_d1(double S, double K, double T, double r, double sigma)
{
    double term1 = std::log(S / K);
    double term2 = (r + (std::pow(sigma, 2) / 2)) * T;
    double term3 = sigma * std::sqrt(T);

    return (term1 + term2) / term3;
}

double inter_d2(double S, double K, double T, double r, double sigma)
{
    double term1 = inter_d1(S, K, T, r, sigma);
    double term2 = sigma * std::sqrt(T);

    return term1 - term2;
}

double black_scholes_call(double S, double K, double T, double r, double sigma)
{
    double term1 = S * norm_cdf(inter_d1(S, K, T, r, sigma));
    double term2 = K * std::exp(-r * T) * norm_cdf(inter_d2(S, K, T, r, sigma));

    return term1 - term2;
}

double black_scholes_put(double S, double K, double T, double r, double sigma)
{
    double term1 = K * std::exp(-r * T) * norm_cdf(-inter_d2(S, K, T, r, sigma));
    double term2 = S * norm_cdf(-inter_d1(S, K, T, r, sigma));

    return term1 - term2;
}

// The Greeks

double greeks_delta(double S, double K, double T, double r, double sigma)
{
    
}

double greeks_gamma(double S, double K, double T, double r, double sigma)
{

}

double greeks_theta(double S, double K, double T, double r, double sigma)
{

}

double greeks_vega(double S, double K, double T, double r, double sigma)
{
    
}

int main()
{
    double S, K, T, r, sigma;
    std::cin >> S >> K >> T >> r >> sigma;

    std::cout << black_scholes_call(S, K, T, r, sigma) << "\n";
    std::cout << black_scholes_put(S, K, T, r, sigma);
}