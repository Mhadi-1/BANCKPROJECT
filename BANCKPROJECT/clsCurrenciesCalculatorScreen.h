#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCuranncy.h"
#include "clsInputValidedate.h"
#include "clsString.h"

class clsCurrenciesCalculatorScreen : protected clsScreen
{

private: 

	static void _PrintCurrencyCard(clsCuranncy Currency)
	{
		cout << "\Convert :";
		cout << "\n__________________________________\n";
		cout << "\nCountry    : " << Currency.GetCurrencyCountry();
		cout << "\nCode       : " << Currency.GetCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GetRate();
		cout << "\n__________________________________\n";
	}
	static clsCuranncy _ReadCurrencyScreen(string Message)
	{
		string CurrencyCode = clsInputValidedate::ReadString(Message);
		while (!clsCuranncy::IsCurrencyExist(CurrencyCode))
		{
			cout << "Invalied Currency Code \n";
			CurrencyCode = clsInputValidedate::ReadString(Message);
		}
		clsCuranncy Currency = clsCuranncy::FindByCode(CurrencyCode);
		if (Currency.IsEmpty())
		{
			cout << "\n Currency Is Not Found ";
			return clsCuranncy::GetEmptyCurrency();
		}
		return Currency;
	}
	static void CalculateExchange(clsCuranncy CurrontCurrency, clsCuranncy SecondCurrency, float Amount )
	{
		
		
		 float CalcualteRateExchange; 
	     CalcualteRateExchange = CurrontCurrency.ConvertToUSD(Amount);
		cout << Amount <<" "<< CurrontCurrency.GetCurrencyCode() << " = "
			<< CalcualteRateExchange << " " << "USD" << endl;

	    if(SecondCurrency.GetCurrencyCode() == "USD")
		{
			return ;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(SecondCurrency);

		float AmountInCurrrency2 = CurrontCurrency.ConvertToAnrotherCurrency(Amount, SecondCurrency);

		cout << Amount << " " << CurrontCurrency.GetCurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << SecondCurrency.GetCurrencyCode();


	}
public:

	static void _ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\t Caculator Currency Main Screen "); 
		
		clsCuranncy FristCurrency  = _ReadCurrencyScreen("Enter Currency 1 Code : ");
		clsCuranncy SecondCurrency = _ReadCurrencyScreen("\nEnter Currency 2 Code : ");
		float Amount = clsInputValidedate::ReadNumber<float>("\nEnter Amount To Exchange : "); 
		_PrintCurrencyCard(FristCurrency); 
		CalculateExchange(FristCurrency, SecondCurrency, Amount);
	}

};

