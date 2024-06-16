#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include "clsInputValidedate.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransact.h"
#include "clsTransferScreen.h"

// InterfaceLayer

class clsTransactionMainmenueScreen : protected clsScreen 
{

private: 

    enum enPerformTransactionOption
    {
        eDeposit = 1, 
        eWithDraw = 2, 
        eTotalBalances = 3, 
        eTransact = 4,
        eTranseferLog = 5,
        eMainMenue = 6
    };
    static int ReadTransactionMainMenueOpetions()
    {
        cout << setw(37) << left << "" << " Choose what do you want to do? [1 to6]? ";
        int Choose = clsInputValidedate::ReadNumberBettween(1,6, " Enter Number between 1 to6? :"); 
        return Choose;

    }
    static void _GobackToMenue()
    {
        cout << setw(37) << left << "" << "\n\n Press any key to go back to Menue...\n";
        system("pause>0");
        system("cls");
        TransactionMainMenuScreen(); 
    }
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDeposit();
    }
    static void _ShowWithDrawScreen()
    {
        clsWithDrawScreen::ShowWithDraw(); 
    }
    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransactScree()
    {
       // cout << "\n Transact Screen Will Be Here ! \n";
        clsTransactScreen::ShowTranseferScreen();
    }
    static void _ShowTransferListScreen()
    {
       /* cout << "\n Transfer List Screen Will Be Here .... \n";*/
        clsTransferScreen::ShowTransferLogScreen();
    }
    static void _PerformTransactionsOptions(enPerformTransactionOption TransactionOption)
    {
        switch (TransactionOption)
        {
        case enPerformTransactionOption::eDeposit:
             system("cls"); 
            _ShowDepositScreen(); 
            _GobackToMenue(); 
            break;
        case enPerformTransactionOption::eWithDraw:
            system("cls"); 
            _ShowWithDrawScreen(); 
            _GobackToMenue();
            break;
        case enPerformTransactionOption::eTotalBalances:
            system("cls");
            _ShowTotalBalanceScreen(); 
            _GobackToMenue();
            break;
        case enPerformTransactionOption::eTransact:
             system("cls");
            _ShowTransactScree();
            _GobackToMenue();
            break;
        case enPerformTransactionOption::eTranseferLog:
            system("cls");
            _ShowTransferListScreen();
            _GobackToMenue();
            break;
        case enPerformTransactionOption::eMainMenue:
                break;
        default:
            break;
        }
    }

public: 

	static void TransactionMainMenuScreen()
	{
		_DrawScreenHeader("\t Transaction Screen "); 
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transct.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionsOptions((enPerformTransactionOption)ReadTransactionMainMenueOpetions());
	}



};

