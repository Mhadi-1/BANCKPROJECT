#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBanckClient.h"

class clsFindClientScreen : protected clsScreen
{

private: 

	static void _PrintClient(clsBanckClient client)
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

	static void ShowFindClientScreen()
	{

		_DrawScreenHeader("\t Find Client Screen ");
		string AccountNumber = "";
		AccountNumber = clsInputValidedate::ReadString(" Enter Acount Number Please : ");
		while (!clsBanckClient::IsClinentExist(AccountNumber))
		{
			cout << " Client Account Number Is Not Found Try Agin : ";
			AccountNumber = clsInputValidedate::ReadString("");
		}
		clsBanckClient Client = clsBanckClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'Y';
		cout << "\n Would You Like To Find Another Acount y/n ? : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			system("cls");
			ShowFindClientScreen();
		}
	}


};

