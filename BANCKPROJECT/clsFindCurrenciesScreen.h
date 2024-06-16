#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCuranncy.h"
#include "clsInputValidedate.h"
#include "clsString.h"

class clsFindCurrenciesScreen : protected clsScreen
{

private: 

	static void _PrintCurrencyCard(clsCuranncy Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n__________________________________\n";
		cout << "\nCountry    : " << Currency.GetCurrencyCountry(); 
		cout << "\nCode       : " << Currency.GetCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GetRate();
		cout << "\n__________________________________\n";
	}

	static void _ShowResult(clsCuranncy Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n Currency Found  :) \n";
			_PrintCurrencyCard(Currency);
		}
		else
		{

			cout << "\n Currency Not Found  :( \n";
			cout << "\n Invalid Currency Not Found !!\n ";
		}
	}

public:

	static void _ShowFindCurrenciesScreen()
	{
		_DrawScreenHeader("\t Find Currencies Screen "); 

		cout << "\nFind By [1] Code or [2] Country ? ";
		short Chooice = clsInputValidedate::ReadNumberBettween(1, 2);
		clsCuranncy Currency = clsCuranncy::GetEmptyCurrency();

		if (Chooice == 1)
		{
			Currency = clsCuranncy::FindByCode(clsInputValidedate::ReadString("\nPlease Enter Currency Code : "));
		}
		else if (Chooice == 2)
		{
			Currency = clsCuranncy::FindByCountry(clsInputValidedate::ReadString("\nPlease Enter Country Name : "));
		}

		_ShowResult(Currency);
	}

};

