#pragma once
#ifndef _ASIAN_OPTION_H
#define _ASIAN_OPTION_H
#include <vector>
#include "PayOff.h"
using namespace std;

class AsianOption {
protected:
	PayOff* pay_off;
public:
	AsianOption( PayOff* _pay_off);
	virtual ~AsianOption() {};
	virtual double pay_off_price(const vector<double>& spot_price) const = 0;

};

class AsianOptionArithmetic :public AsianOption {
public:
	AsianOptionArithmetic(PayOff* _pay_off);
	virtual ~AsianOptionArithmetic();
	virtual double pay_off_price(const vector<double>& spot_prices) const;
};

class AsianOptionGeometric : public AsianOption {
public:
	AsianOptionGeometric(PayOff* _pay_off);
	virtual ~ AsianOptionGeometric();
	virtual double pay_off_price(const vector<double>& spot_prices) const;
};

#endif