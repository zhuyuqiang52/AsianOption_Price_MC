
#include <iostream>
#include "Asian_Option.h"
#include "PayOff.h"
#include "Path_Gen.h"

int main()
{
    int a = -12 % 10;
    cout << a << endl;
    /*unsigned sims_num = 100000;
    unsigned num_interval = 250;
    double S = 30.0, K = 29.0, r = 0.08, v = 0.3, T = 1.0;
    vector<double> spot_prices(num_interval, S);

    PayOff* sample_payoff = new PayOffCall(K);
    AsianOption* sample_option = new AsianOptionGeometric(sample_payoff); // use operator() in PayOff to initialize
    double payoff_sum = 0.0;
    double tmp_payoff = 0.0;
    for (unsigned i = 0; i < sims_num; i++) {
        cal_path_spot_prices(spot_prices, r, v, T);
        tmp_payoff = sample_option->pay_off_price(spot_prices);
        payoff_sum += tmp_payoff;
        cout << "turn :" << i << " payoff: "<<tmp_payoff<< " payoff_sum : "<<payoff_sum<<endl;
    };
    double payoff_MC_mean = payoff_sum / static_cast<double>(sims_num);
    cout << sims_num << " times MC's average payoff: " << payoff_MC_mean << endl;*/
    return 1;
};