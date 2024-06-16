#pragma once
 #include <iostream>
 #include <string>
 #include "clsScreen.h"
 #include"clsInputValidedate.h"
 #include "clsCurrencyListScreen.h"
 #include"clsFindCurrenciesScreen.h"
 #include "clsUpdateCurrencyScreen.h"
 #include "clsCurrenciesCalculatorScreen.h"


class clsEXchangeMainScreen : protected clsScreen
{


private: 

	static enum enPerformCurrencyOpetion
	{
		eListCurrencies     = 1,
	    eFindCurrency       = 2, 
		eUpdateCurrency     = 3, 
		eCurrencyCalculator = 4, 

	};
	static int _ReadMainMenuOpetion()
	{
		short Choise = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		Choise = clsInputValidedate::ReadNumberBettween(1, 5, "\t\t\t\t\ Enter Number between 1 to 5? : ");
		return Choise;

	}
	static void _BackToMenuScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		_ShowCurrenciesMainMenu();
	}
	static void _ShowCurrencyListScreen()
	{
		/*cout << "\n List Currencies Screen Will Be Here..\n";*/
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		/*cout << "\n Find Currencies Screen Will Be Here..\n";*/
		clsFindCurrenciesScreen::_ShowFindCurrenciesScreen();
	}
	static void _ShowUpdateCurrencyScreen()
	{
		/*cout << "\n Update Currencies Rate Screen Will Be Here..\n";*/
		clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		/*cout << "\n Calculator Currencies Screen Will Be Here..\n";*/
		clsCurrenciesCalculatorScreen::_ShowCurrencyCalculatorScreen();
	}
	static void _PerformCurrencyMainMenuOpetion(enPerformCurrencyOpetion CurrencyMenuOptions)
	{
		switch (CurrencyMenuOptions)
		{
		case enPerformCurrencyOpetion::eListCurrencies:
			 system("cls");
			_ShowCurrencyListScreen();
			_BackToMenuScreen();
			break;
		case enPerformCurrencyOpetion::eFindCurrency:
			 system("cls");
			_ShowFindCurrencyScreen();
			_BackToMenuScreen();
			break;
		case enPerformCurrencyOpetion::eUpdateCurrency:
			 system("cls");
			_ShowUpdateCurrencyScreen();
			_BackToMenuScreen();
			break;
		case enPerformCurrencyOpetion::eCurrencyCalculator:
			 system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToMenuScreen();
			break;
		default:
			break;
		}
	}

public: 

	static void _ShowCurrenciesMainMenu()
	{
		 system("cls");
		_DrawScreenHeader("\t Currencies Exchange Main Menu Screen "); 

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currencies Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyMainMenuOpetion((enPerformCurrencyOpetion)_ReadMainMenuOpetion());
	}

};

