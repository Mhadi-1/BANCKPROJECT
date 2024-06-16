#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCuranncy.h"

class clsCurrenciesListScreen : protected clsScreen
{

private: 

	static void _PrintCurrencyRecordLine(clsCuranncy Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCurrencyCountry();
		cout << "| " << setw(10) << left << Currency.GetCurrencyCode();
		cout << "| " << setw(35) << left << Currency.GetCurrencyName();
		cout << "| " << setw(10) << left << Currency.GetRate();
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector<clsCuranncy> vCurrencies = clsCuranncy::GetCurrencyList();
		string Title = "\t Currency List Screen "; 
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currenies.";
		_DrawScreenHeader(Title,SubTitle); 


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(35) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Crunnecy Available Into the System!";
		else
	    for (clsCuranncy& C1 : vCurrencies)
		{
			_PrintCurrencyRecordLine(C1);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

