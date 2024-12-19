#include "../include/currencyfactory.h"

CurrencyFactory::CurrencyFactory() {
    currencies_[0] = new Currency("USD", 1.0);
    currencies_[1] = new Currency("EUR", 0.85);
    currencies_[2] = new Currency("GBP", 0.75);
    currencies_[3] = new Currency("JPY", 110.0);
    currencies_[4] = new Currency("CAD", 1.25);
}

CurrencyFactory::~CurrencyFactory() {
    for (int i = 0; i < 5; ++i) {
        delete currencies_[i];
    }
}

Currency* CurrencyFactory::GetCurrency(int currencyType) {
    if (currencyType >= 0 && currencyType < 5) {
        return currencies_[currencyType];
    }
    return nullptr; // Return nullptr if invalid index
}