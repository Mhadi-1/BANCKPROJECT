#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBanckClient.h"
#include "clsInputValidedate.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsMainMenueUsersScreens : protected clsScreen
{


private : 

    enum enManageUsersMenueOptions
    { 
       eListUsers  = 1 ,
       eAddNewUser = 2 , 
       eDeleteUser = 3 ,
       eUpdateUser = 4 ,
       eFindUser   = 5 , 
       MainMenue   = 6 
    };
    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidedate::ReadNumberBettween(1, 6, " Enter A Number Plase : "); 
        return Choice;
    }
    static void _BackToMainMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0"); 
        system("cls");
        ShowMainMenueUsersScreen();
    }
    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersListScreen();
    }
    static void _ShowAddNewUserScreen()
    {
     
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUsersScreen()
    {
       /* cout << "\n Delete Users Screen Will Be Here ";*/
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUsersScreen()
    {
        /*cout << "\n Update Users Screen Will Be Here ";*/ 
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUsersScreen()
    {
        /*cout << "\n Find Users Screen Will Be Here "; */
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions OptionType)
    {
        switch (OptionType)
        {
        case enManageUsersMenueOptions::eListUsers:
        {

             system("cls");
            _ShowListUsersScreen();
            _BackToMainMenue();
            break;
        };
        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _BackToMainMenue();
            break;
        };
        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUsersScreen();
            _BackToMainMenue();
            break;

        };
        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUsersScreen();
            _BackToMainMenue();
            break;
        };
        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUsersScreen();
            _BackToMainMenue();
            break;

        };
        case enManageUsersMenueOptions::MainMenue:
            break;
        default:
            break;
        };
   }

public :
	 
	static void ShowMainMenueUsersScreen()
	{ 
		_DrawScreenHeader("\t Manage Users Screen "); 
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}




};

