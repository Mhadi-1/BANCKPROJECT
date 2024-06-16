#pragma once
#include <string>
#include <iostream>
#include"Global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{ 

private:

	static void _ShowUserName_And_Date()
	{
		clsDate Date;
		cout << "\t\t\t\t\t User : " << CurrantUser.FullName() << endl;;
		cout << "\t\t\t\t\t Date : " << Date.DateToString() << endl << endl;;;
	}
	

protected:

	static void _DrawScreenHeader(string Title , string SubTitle ="")
	{
		
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		_ShowUserName_And_Date();

	}
	static bool IsAccessToScreen(clsUsersBank::enPermissions Permission)
	{
		if (!CurrantUser.CheckAccessPermissions(Permission))
		{
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			cout << "\t\t\t\t\tYou Don't Have Access Check Your Admin !";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		return true;
	}

};

