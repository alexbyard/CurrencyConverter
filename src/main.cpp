#include <iostream>
#include <limits>
#include "../include/currency.h"
#include "../include/currencyfactory.h"

using namespace std;


bool readInt(int& value) {
    // Checks if given an integer, otherwise returns false
    cin >> value;
    if (cin.fail()) {
        cin.clear(); // Clear the error state of the cin object
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the current line
        return false;
    }
    return true;
}

int main() {
    CurrencyFactory factory;

	int choice;
	do {
		cout << "\nCurrency Converter" << endl;
		cout << "1. Convert Currency" << endl;
		cout << "2. Update Exchange Rate" << endl;
        cout << "3. View Exchange Rates" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		
        if (!readInt(choice) || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            continue;
        }

        if (choice == 1) {
            int from, to;
            double amount;
            cout << "Choose the base currency (0: USD, 1: EUR, 2: GBP, 3: JPY, 4: CAD): ";
            if (!readInt(from) || from < 0 || from >= 5) { // Adjust the range based on your actual currencies
                cout << "Invalid currency index. Please try again." << endl;
                continue;
            }

            cout << "Choose the target currency (0: USD, 1: EUR, 2: GBP, 3: JPY, 4: CAD): ";
            if (!readInt(to) || to < 0 || to >= 5) { // Adjust the range based on your actual currencies
                cout << "Invalid currency index. Please try again." << endl;
                continue;
            }

            if (from == to) {
                cout << "Both currencies are the same. No conversion is necessary." << endl;
                continue;
            }

            Currency* baseCurrency = factory.GetCurrency(from);
            Currency* targetCurrency = factory.GetCurrency(to);
            if (baseCurrency && targetCurrency) {
                cout << "Enter amount in " << baseCurrency->GetSymbol() << ": ";
                cin >> amount;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a numerical amount." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                double convertedAmount = baseCurrency->ConvertTo(amount, *targetCurrency);
                cout << amount << " " << baseCurrency->GetSymbol() << " = "
                    << convertedAmount << " " << targetCurrency->GetSymbol() << endl;
            }
            else {
                cout << "Error: Invalid currency selection." << endl;
            }
        }
        else if (choice == 2) {
            int currencyIndex;
            double newRate;
            cout << "Enter currency index to update (0: USD, 1: EUR, 2: GBP, 3: JPY, 4: CAD): ";
            if (!readInt(currencyIndex) || currencyIndex < 0 || currencyIndex >= 5) { // Ensure this matches your currency count
                cout << "Invalid currency index. Please try again." << endl;
                continue;
            }

            Currency* currencyToUpdate = factory.GetCurrency(currencyIndex);
            if (currencyToUpdate == nullptr) {
                cout << "Invalid currency selection." << endl;
                continue;
            }

            cout << "Current exchange rate for " << currencyToUpdate->GetSymbol() << " is " << currencyToUpdate->GetExchangeRate() << endl;
            cout << "Enter new exchange rate against USD for " << currencyToUpdate->GetSymbol() << ": ";
            cin >> newRate;
            if (cin.fail() || newRate <= 0) { // Adding a simple check for positive rates
                cout << "Invalid input. Please enter a positive numerical exchange rate." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            currencyToUpdate->SetExchangeRate(newRate);
            cout << "Updated exchange rate for " << currencyToUpdate->GetSymbol() << " is now " << newRate << endl;
        }
        else if (choice == 3) {
            Currency* currencyZero = factory.GetCurrency(0);
            Currency* currencyOne = factory.GetCurrency(1);
            Currency* currencyTwo = factory.GetCurrency(2);
            Currency* currencyThree = factory.GetCurrency(3);
            Currency* currencyFour = factory.GetCurrency(4);
            cout << "  1. USD/" << currencyZero->GetSymbol() << "=" << currencyZero->GetExchangeRate() << endl;
            cout << "  2. USD/" << currencyOne->GetSymbol() << "=" << currencyOne->GetExchangeRate() << endl;
            cout << "  3. USD/" << currencyTwo->GetSymbol() << "=" << currencyTwo->GetExchangeRate() << endl;
            cout << "  4. USD/" << currencyThree->GetSymbol() << "=" << currencyThree->GetExchangeRate() << endl;
            cout << "  5. USD/" << currencyFour->GetSymbol() << "=" << currencyFour->GetExchangeRate() << endl;
        }
	} while (choice != 4);

	cout << "Exiting Currency Converter." << endl;
}   