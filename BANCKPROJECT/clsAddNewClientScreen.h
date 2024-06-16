#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsInputValidedate.h"
#include "clsBanckClient.h"
#include "clsScreen.h"

class clsAddNewClientScreen : protected clsScreen 
{

private: 

	static void _ReadClientInfo(clsBanckClient& Client)
	{
		Client.FirstName = clsInputValidedate::ReadString(" Enter Frist Name : ");
		Client.LastName = clsInputValidedate::ReadString(" Enter Last  Name : ");
		Client.PhoneNumber = clsInputValidedate::ReadString(" Enter Phone      : ");
		Client.PinCode = clsInputValidedate::ReadString(" Enter PinCode    : ");
		Client.AcountBalance = clsInputValidedate::ReadNumber<double>(" Enter Acount Balance : ");
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
	static void ShowAddNewClientScreen()
	{
		_DrawScreenHeader("\t Add New Client Screen"); 

    	string AccountNumber = ""; 

		AccountNumber = clsInputValidedate::ReadString(" Enetr Client Acount Number : ");
		while (clsBanckClient::IsClinentExist(AccountNumber))
		{
			cout << "  Clinet With Account Number " << AccountNumber << " Is Already Exist Enter Another Account : ";
			AccountNumber = clsInputValidedate::ReadString("");

		}

		clsBanckClient NewClient = clsBanckClient::GetAddNewClinet(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBanckClient::enSaveResult SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBanckClient::svfildEmptyObject:
			cout << "\n Error account was not saved because it's Empty";
			break;
		case clsBanckClient::svSuccessful:
			cout << "\n Account Added Successfully \n";
		     _PrintClint(NewClient);
			break;
		case clsBanckClient::svFildAccounNumberExist:
			cout << "\n Error account was already exist \n";
			break;
		default:
			break;
		}

	}

};

