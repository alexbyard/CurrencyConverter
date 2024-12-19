#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include<string>
using std::string;

class Currency {
private:
	string symbol_;
	double exchange_rate_;

public:
	Currency(string symbol, double rate);
	~Currency();
	string GetSymbol();
	double GetExchangeRate();
	void SetExchangeRate(double exchange_rate);
	double ConvertTo(double amount, const Currency& targetCurrency) {
		return amount * (targetCurrency.exchange_rate_ / this->exchange_rate_);
	}
};

#endif