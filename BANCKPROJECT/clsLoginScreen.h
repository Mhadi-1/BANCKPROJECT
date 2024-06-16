#pragma once
#include <string>
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidedate.h"
#include  "clsUsersBank.h"
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{

private:




public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login Screen ");
		
		bool LoginFild = false;
		short LoginTriales = 0; 
		string AccounNumber, PassWord; 
		do
		{
			if (LoginFild)
			{
				LoginTriales++;

				cout << "\n Invalid Username/PassWord \n";
				cout << " You Have  " << (3 - LoginTriales) << " Triale(s) to Login" << endl;
			}
		
			if (LoginTriales == 3)
			{
				cout << "\n You Are Blocked After 3 Failed Triales \n";
				return false;
			}
			AccounNumber = clsInputValidedate::ReadString("\n Enter Account Number Please : "); 
			PassWord = clsInputValidedate::ReadString(" Enter PassWord : ");
			CurrantUser =  clsUsersBank::Find(AccounNumber, PassWord);
			LoginFild = CurrantUser.IsEmpty();


		} while (LoginFild);

		CurrantUser.SaveRegisterLogin();
		clsMainScreen::ShowMainMenue();

		return true;
	}



};
