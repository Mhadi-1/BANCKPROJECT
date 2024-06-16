#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "clsInputValidedate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClinetScreen.h"
#include "clsFindClient.h"
#include "clsTransactionMainmenue.h"
#include "clsManageUsersMainMenue.h"
#include "clsUsersBank.h"
#include "clsAccountPermission.h"
#include "clsLoginScreen.h"
#include "clsRegisterScreen.h"
#include "clsEXchangeMainMenu.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen 
{


 private: 
     
    static string _AccountNumber;
    static string _AccountPassWord;

    enum enMainMenueOptions
     {
         eCLientsList  = 1,
         eAddNewClient = 2,
         eDeleteClient = 3,
         eUpdateClient = 4,
         eFindClient   = 5,
         eTransaction  = 6,
         eManageUsers  = 7,
         eRegisterist  = 8,
         EeXchange     = 9, 
         eLogout       = 10


     };

    static short _ReadMainMenueOptions()
    {
         short Choise = 0;
         cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
         Choise =  clsInputValidedate::ReadNumberBettween<short>(1, 10,"\t\t\t\t\tEnter Number between 1 to 10? : ");
         return Choise;
    }
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowClinetsListsScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pShoClinetList))
        {
            return;
        }
        clsClientsListScreen::ShowClientsList();
    }
    static void _AddNewClientsScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pAddNewClinet))
        {
            return;
        }
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _DeleteClinetsScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pDeleteClinet))
        {
            return;
        }
        clsDeleteClientScreen::ShowDeleteClient();
    }
    static void _UpdateClientsScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pUpdateClient))
        {
            return;
        }
        clsUpdateClinetScreen::ShowUpdateClient();

    }
    static void _FindClientsScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pFindClient))
        {
            return;
        }
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _TransactionScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pShowTransaction))
        {
            return;
        }
       clsTransactionMainmenueScreen::TransactionMainMenuScreen();
    }
    static void _ManageUsersScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pShowUsers))
        {
            return;
        }
        clsMainMenueUsersScreens::ShowMainMenueUsersScreen(); 
    }
    static void _ShowRegisterScreen()
    {
       /* cout << "\n Register Screen Will Be Here : ";*/
        if (!IsAccessToScreen(clsUsersBank::pLoginRegister))
        {
            return;
        }
        clsRegisterScreen::ShowRegisterList();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        if (!IsAccessToScreen(clsUsersBank::pExchange))
        {
            return; 
        }
        clsEXchangeMainScreen::_ShowCurrenciesMainMenu();
    }

    static void _LogOut()
    {
        CurrantUser = clsUsersBank::Find("", "");
    }
    static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOptions)
    {
         switch (MainMenueOptions)
         {
         case enMainMenueOptions::eCLientsList:
              system("cls"); 
             _ShowClinetsListsScreen();
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eAddNewClient:
               system("cls");
              _AddNewClientsScreen();
              _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eDeleteClient:
             system("cls"); 
             _DeleteClinetsScreen();
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eUpdateClient:
             system("cls"); 
             _UpdateClientsScreen(); 
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eFindClient:
             system("cls"); 
             _FindClientsScreen();
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eTransaction:
             system("cls"); 
             _TransactionScreen(); 
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eManageUsers:
             system("cls"); 
             _ManageUsersScreen(); 
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::eRegisterist:
              system("cls");
             _ShowRegisterScreen();
             _GoBackToMainMenue();
             break;
         case enMainMenueOptions::EeXchange: 
              system("cls"); 
             _ShowCurrencyExchangeScreen(); 
             _GoBackToMainMenue();
             break;

         case enMainMenueOptions::eLogout:
              system("cls");
             _LogOut();
             break;
         default:
             break;
         }
    }


 public: 

	 static void ShowMainMenue()
	 {
          system("cls");
         _DrawScreenHeader("\t\tMain Menue");
         cout << setw(37) << left << "" << "===========================================\n";
         cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
         cout << setw(37) << left << "" << "===========================================\n";
         cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
         cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
         cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
         cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
         cout << setw(37) << left << "" << "\t[5] Find Client.\n";
         cout << setw(37) << left << "" << "\t[6] Transactions.\n";
         cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
         cout << setw(37) << left << "" << "\t[8] Show Registers.\n";
         cout << setw(37) << left << "" << "\t[9] Currancy Exchange.\n";
         cout << setw(37) << left << "" << "\t[10] Logout.\n";
         cout << setw(37) << left << "" << "===========================================\n";
         _PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOptions());

	 }


};

