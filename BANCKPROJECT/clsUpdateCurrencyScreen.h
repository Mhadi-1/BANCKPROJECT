#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCuranncy.h"
#include "clsInputValidedate.h"
#include "clsString.h"

class clsUpdateCurrencyScreen : protected clsScreen
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
	static void _ShowUpdateCurrencyRate(clsCuranncy Currency)
	{
		
		cout << "\n\tUpdate Currency Rate \n "; 
		cout << "_______________________________\n";
		float NewRate = clsInputValidedate::ReadNumber<float>("\n Enter New Rate : ");

		if (Currency.UpdateRate(NewRate))
		{
			cout << "\nNew Rate Update Succssfully\n";
		    _PrintCurrencyCard(Currency);
		}
	}

public:


	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen "); 
		string CurrencyCode = clsInputValidedate::ReadString("Please Enter Currency Code : "); 

		while (!clsCuranncy::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nInvalid Currency Code \n ";
			CurrencyCode = clsInputValidedate::ReadString("\nPlease Enter Another Currency Code : ");
		}

		clsCuranncy Currency = clsCuranncy::FindByCode(CurrencyCode); 
		
		if (!Currency.IsEmpty())
		{
			_PrintCurrencyCard(Currency); 
		}

		char AskUser;
		cout << "\nAre You Sure You Want To Update The Rate Of This Currency y/n ? ";
		cin >> AskUser;
		if (toupper(AskUser) == 'Y')
		{
			_ShowUpdateCurrencyRate(Currency);
		}
	}

};

