#pragma once
#ifndef _PATH_GEN_H
#define _PATH_GEN_H
#include <vector>
#include <cmath>

//box_muller _transfer
double gaussian_box_muller() {
	double u1 = 0.0, u2 = 0.0;
	//gen u1,u2 uniform distribution within [0,1]
	do{
	u1 = rand() / static_cast<double>(RAND_MAX);
	u2 = rand() / static_cast<double>(RAND_MAX);
	} while(u1==0 || u2==0);
	double gauss_bm = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
	if (isnan(gauss_bm) || isinf(gauss_bm)) {
		cout << endl;
	};
	return gauss_bm;
};

void cal_path_spot_prices( //single MC path
	vector<double> & spot_prices,
	const double & r,
	const double& v,
	const double& T) {
	//get delta t`
	double dt = T / static_cast<double>(spot_prices.size());
	double drift = exp(dt * (r - 0.5 * v * v));
	double vol = sqrt(v * v * dt);
	// s1 = s0exp((r - 0.5*v^2)dt+v*sqrt(dt)N(0,1)
	double gauss_bm = 0.0;
	for (unsigned i = 1; i < spot_prices.size(); i++) {
		gauss_bm = gaussian_box_muller();
		spot_prices[i] = spot_prices[i - 1] * drift * exp(vol * gauss_bm);
	};
};
#endif
