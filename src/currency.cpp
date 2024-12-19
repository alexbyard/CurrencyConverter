#include "../include/currency.h"

Currency::Currency(string symbol, double exchange_rate)
	: symbol_(symbol),
	  exchange_rate_(exchange_rate)
{
}

Currency::~Currency()
{
}

string Currency::GetSymbol() {
	return symbol_;
}

double Currency::GetExchangeRate() {
	return exchange_rate_;
}

void Currency::SetExchangeRate(double exchange_rate) {
	exchange_rate_ = exchange_rate;
}