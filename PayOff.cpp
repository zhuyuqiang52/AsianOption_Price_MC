#ifndef _PAYOFF_CPP_
#define _PAYOFF_CPP_
#include "PayOff.h"
#include <algorithm>
PayOff::PayOff() {};
PayOff::~PayOff() {};

PayOffCall::PayOffCall(const double& _K) { K = _K; };
double PayOffCall::operator()(const double& S) const {
	return std::max(S - K, 0.0);
};

PayOffPut::PayOffPut(const double& _K) { K = _K; };
double PayOffPut::operator()(const double& S) const {
	return std::max(K-S, 0.0);
};
#endif