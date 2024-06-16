#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsInputValidedate.h"
#include "clsScreen.h"
#include "clsUsersBank.h"
class clsPermissions : clsScreen 
{

private:

	  
    static void _AddPermissions(short &Permission)
	{
		char AddPermission = 'Y';
		 
		cout << "\n Show Clinet List ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{

			Permission += clsUsersBank::enPermissions::pShoClinetList;
		}
		cout << "\n Add New Clinet ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pAddNewClinet;

		}
		cout << "\n Delete Client ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pDeleteClinet;

		}
		cout << "\n Update Client ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pUpdateClient;

		}
		cout << "\n Find client ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pFindClient;

		}
		cout << "\n Show Transaction Menu ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pShowTransaction;

		}
			cout << "\n Show Users Menu ? y/n : ";
		cin >> AddPermission;
		if (toupper(AddPermission) == 'Y')
		{
			Permission += clsUsersBank::enPermissions::pShowUsers;

		}

	}

public:

	static short ReadPermissionsToSet()
	{
		 char AskUser = 'Y';
		 short Permissions = 0; 
		_DrawScreenHeader("\t Permissions Main Menu Screen ");
		cout << "\n Would You Like To Give Full Access ? y/n : ";
		cin >> AskUser;
		if (toupper(AskUser) == 'Y')
		{
			Permissions = -1;
		}
		else
		{
			_AddPermissions(Permissions);
		}
		return Permissions;
	}


};

