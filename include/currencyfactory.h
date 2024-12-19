#include "Currency.h"

class CurrencyFactory {
public:
    CurrencyFactory();
    ~CurrencyFactory();
    Currency* GetCurrency(int currencyType);

private:
    Currency* currencies_[5];
};