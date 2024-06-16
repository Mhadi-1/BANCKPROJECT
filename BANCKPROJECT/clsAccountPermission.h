#pragma once
#include <string>
#include <iostream>
#include "clsLoginScreen.h"
#include "clsMainScreen.h"
#include "clsUsersBank.h"

class clsAccountPermission 
{

private:

	static string _Account;
	static string _PassWord; 


public: 

	static void InFaildPermission()
	{
		cout << "\n Account Dose not Has Access to this Option ! ";
	}

	static bool _LoginTo_System_Permissions()
	{
		clsUsersBank User = clsUsersBank::Find(_Account, _PassWord); 
		if (User.Permissions >= clsUsersBank::enPermissions::pShoClinetList)
		{
			return true;
		}
		else if (User.Permissions >= clsUsersBank::enPermissions::pAddNewClinet)
		{
			return true;
		}
		return false; 
	}

};

