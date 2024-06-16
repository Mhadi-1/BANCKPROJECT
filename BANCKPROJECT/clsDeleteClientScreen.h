#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsInputValidedate.h"
#include "clsBanckClient.h"
#include "clsScreen.h"


class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _PrintClint(clsBanckClient client)
	{

		cout << "\n Client Card:";
		cout << "\n ___________________";
		cout << "\n FirstName   : " << client.FirstName;
		cout << "\n LastName    : " << client.LastName;
		cout << "\n Full Name   : " << client.FullName();
		cout << "\n Phone       : " << client.Getphonenumber();
		cout << "\n Acc. Number : " << client.GetAcountNumber();
		cout << "\n Password    : " << client.PinCode;
		cout << "\n Balance     : " << client.AcountBalance;
		cout << "\n ___________________\n";

	}

public:

  static void ShowDeleteClient()
  {
	   _DrawScreenHeader("\t Delete Client Screen ");
	   string accountnumber = clsInputValidedate::ReadString(" Enter Client Accountnumber Please : ");

	   while (!clsBanckClient::IsClinentExist(accountnumber))
	   {
		  cout << "\n invalied account number !!\n";
		  accountnumber = clsInputValidedate::ReadString(" Enter Client Accountnumber Please : ");

	   }

	    clsBanckClient cleint1 = clsBanckClient::Find(accountnumber);
		_PrintClint(cleint1);
	    cout << "\nAre you sure you want to delete this client ?  : "; 
	    char askfordelete = 'Y';
	    cin >> askfordelete;

	   if (toupper(askfordelete) == 'Y')
	   {	
		   if (cleint1.Delete())
		   {
			cout << "\n client deleted successfully : \n";
			_PrintClint(cleint1);
		   }
		   else
		   {
			cout << "\n error account dosn't delete \n";
		   }
	   }

  }

};

