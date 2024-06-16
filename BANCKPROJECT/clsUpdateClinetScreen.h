#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsInputValidedate.h"
#include "clsBanckClient.h"
#include "clsScreen.h"
class clsUpdateClinetScreen : protected clsScreen
{

private:
	static void _ReadClientInfo(clsBanckClient & Client)
    {
	   Client.FirstName     = clsInputValidedate::ReadString("\nEnter Frist Name : ");
	   Client.LastName      = clsInputValidedate::ReadString("Enter Last  Name : ");
	   Client.PhoneNumber   = clsInputValidedate::ReadString("Enter Phone      : ");
	   Client.PinCode       = clsInputValidedate::ReadString("Enter PinCode    : ");
	   Client.AcountBalance = clsInputValidedate::ReadNumber<short>("Enter Acount Balance : ");
    }
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

  static void ShowUpdateClient()
  {
	  _DrawScreenHeader("\t Update Client Screen ");
	 string AccountNumber = "";
	 AccountNumber = clsInputValidedate::ReadString(" Enter Client AccountNumber Please : ");
	 while (!clsBanckClient::IsClinentExist(AccountNumber))
	 {
	 	cout << "\n InValied Account Number !!\n";
	 	AccountNumber = clsInputValidedate::ReadString(" Enter Client AccountNumber Please : ");
	 
	 }
	 clsBanckClient Client = clsBanckClient::Find(AccountNumber);
	 _PrintClint(Client);
	 _ReadClientInfo(Client);
	 clsBanckClient::enSaveResult SaveResult = Client.Save();
	 switch (SaveResult)
	 {
	 case clsBanckClient::svfildEmptyObject:
	 	cout << "\n Error account was not saved because it's Empty";
	 	break;
	 case clsBanckClient::svSuccessful:
	 	cout << "\n Account Updated Successfully \n";
	    _PrintClint(Client);

	 	break;
	 default:
	 	break;
	 }

  }

};

