#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUsersBank.h"
#include "clsString.h"
#include "clsInputValidedate.h"

class clsFindUserScreen : protected clsScreen
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

public:


	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t Find User Screen ");
		string UserAccount = clsInputValidedate::ReadString(" Enter User Account Pleaes : ");

		while (!clsUsersBank::IsAccountExist(UserAccount))
		{
			cout << " User Account " << UserAccount << " Is Not Found Enter Another Acc : ";
			UserAccount = clsInputValidedate::ReadString("");
		}
		clsUsersBank User = clsUsersBank::Find(UserAccount);

		if (!User.IsEmpty())
		{
			_Print(User);
		}
		else
		{
			cout << "\n User Is Not Found !!";
		}
	}


};

