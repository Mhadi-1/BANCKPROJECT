#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUsersBank.h"
#include "clsString.h"
#include "clsInputValidedate.h"

class clsDeleteUserScreen : protected clsScreen
{

private: 

	static void _Print(clsUsersBank User)
	{
		cout << "\n User Card:";
		cout << "\n ___________________";
		cout << "\n FirstName   : " << User.FirstName;
		cout << "\n LastName    : " << User.LastName;
		cout << "\n Full Name   : " << User.FullName();
		cout << "\n Phone       : " << User.Getphonenumber();
		cout << "\n Acc. Number : " << User.GetUserName();
		cout << "\n Password    : " << User.PassWord;
		cout << "\n Permission  : " << User.Permissions;
		cout << "\n ___________________\n";
	}
	static bool ChickForDelete(clsUsersBank &User)
	{
		char AskUser = 'Y'; 
		cout << "\n Are You Sure You Want to delete This User ? : "; 
		cin >> AskUser;

		if (toupper(AskUser) == 'Y')
		{
			 User.Delete();

			return User.IsEmpty() ? true : false;

		}
	}

public: 


	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen ");
		string UserForDelete = clsInputValidedate::ReadString(" Enter User Name : "); 

		while (! clsUsersBank::IsAccountExist(UserForDelete))
		{
			cout << "\n User With AccountNumber " << UserForDelete << " Is Not Exist Try Agin : ";
			UserForDelete = clsInputValidedate::ReadString("");
		}

		clsUsersBank User = clsUsersBank::Find(UserForDelete);
		_Print(User);
		 
		if (ChickForDelete(User))
		{
			cout << "\n User Deleted Successfully : \n";

		}
		else
		{
			cout << "\n User Not Deleted Yet : \n";

		}
		
		_Print(User); 

	}

};

