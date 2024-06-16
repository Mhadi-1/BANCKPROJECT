#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUsersBank.h"
#include "clsString.h"
#include "clsInputValidedate.h"
#include "clsPermissions.h"

class clsUpdateUserScreen : protected clsScreen
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
	static void _ReadInfo(clsUsersBank& User)
	{
		cout << endl;
		User.FirstName    = clsInputValidedate::ReadString(" Enter User Frist Name  : ");
		User.LastName     = clsInputValidedate::ReadString(" Enter User Last Name   : ");
		User.PassWord     = clsInputValidedate::ReadString(" Enter User PassWord    : ");
		User.PhoneNumber  = clsInputValidedate::ReadString(" Enter User PhoneNumber : ");
		User.Permissions  = clsPermissions::ReadPermissionsToSet();
		cout << endl;

	}
	static void _ChickFroUpdate(clsUsersBank& User)
	{
	    char AskUser = 'Y';
		cout << "\n Are You Sure You Want to Save This Update y/n ? : ";
		cin >> AskUser;

		if (toupper(AskUser) == 'Y')
		{
			clsUsersBank::enSaveRseult Result;
			Result = User.Save();
			switch (Result)
			{

			case clsUsersBank::eSaveSuccessfully:
			{
				cout << "\n Update Saved Successfully \n";
				break;
			};
			case clsUsersBank::eSavefildEmptyObject:
			{
				cout << "\n fild Empty Object \n";
				break;
			};
			case clsUsersBank::eFildAccounNumberExist:
			{
				cout << "\n fild AcccountNumber \n";
				break;
			};
			default:
				break;
			}
		}
		else
			cout << "\n Update Not Saved it ";
	}

public: 

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen ");
		string UserAccount = clsInputValidedate::ReadString(" Enter User Account Pleaes : ");
		while (!clsUsersBank::IsAccountExist(UserAccount))
		{
			cout << " User Account " << UserAccount << " Is Not Exist Enter Another One : ";
			UserAccount = clsInputValidedate::ReadString("");
		}
		
		 clsUsersBank User = clsUsersBank::Find(UserAccount);

		_Print(User);
		_ReadInfo(User);
		_ChickFroUpdate(User);

		 // After change Update
		_Print(User);

		
	}

};

