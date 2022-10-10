#ifndef _ASIAN_OPTION_CPP_
#define _ASIAN_OPTION_CPP_
#include "Asian_Option.h"
#include <numeric>
#include <iostream>
AsianOption::AsianOption(PayOff* _pay_off) :pay_off(_pay_off) {};

AsianOptionArithmetic::AsianOptionArithmetic(PayOff* _pay_off) : AsianOption(_pay_off){};

AsianOptionArithmetic::~AsianOptionArithmetic() {};
double AsianOptionArithmetic::pay_off_price(const vector<double>& spot_prices) const{
	unsigned num_times = static_cast<unsigned>(spot_prices.size());
	double sum = accumulate(spot_prices.begin(), spot_prices.end(), 0.0);
	double Arithmetic_mean = sum / static_cast<double> (num_times);
	return (*pay_off)(Arithmetic_mean); // payoff derivative class's operator() func
};

AsianOptionGeometric::AsianOptionGeometric(PayOff* _pay_off) : AsianOption(_pay_off) {};

AsianOptionGeometric::~AsianOptionGeometric() {};
double AsianOptionGeometric::pay_off_price(const vector<double>& spot_prices) const {
	unsigned num_times = static_cast<unsigned>(spot_prices.size());
	double log_spot_price_sum = 0.0;
	for (unsigned i = 0; i < num_times; i++) {
		if (spot_prices[i] < 1e-6) {
			cout << endl;
		};
		log_spot_price_sum += log(spot_prices[i]);
	};
	double Geometric_mean = exp(log_spot_price_sum / num_times);
	return (*pay_off)(Geometric_mean); // payoff derivative class's operator() func
};
#endif