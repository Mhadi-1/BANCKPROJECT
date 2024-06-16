#pragma once
#include <string>
#include <iostream>
#include "clsScreen.h"
#include "clsBanckClient.h"
#include "clsInputValidedate.h"
#include "clsString.h"
#include "clsUsersBank.h"

class clsTransactScreen : protected clsScreen
{

private: 


	static void _PrintCard(clsBanckClient Client)
	{
		cout << "\nClient Card :"; 
		cout << "\n____________________________\n\n";
		cout << "Full Name : " << Client.FullName() << endl;
		cout << "Acc.Num   : " << Client.GetAcountNumber() << "\n";
		cout << "Balance   : " << Client.GetAcountBalance() << endl;
		cout << "\n____________________________\n\n";

	}
	static clsBanckClient _FindClient(string Message)
	{
		string AccountNumber;
		AccountNumber = clsInputValidedate::ReadString(Message);
		while (!clsBanckClient::IsClinentExist(AccountNumber))
		{
			cout << " Client With Account Numebr " << AccountNumber << " Is Not Found try Agin : ";
			AccountNumber = clsInputValidedate::ReadString("");
		}


		return clsBanckClient::Find(AccountNumber);
	}
	static short _SendTransfer(clsBanckClient &SoursClient , clsBanckClient &DestinationClient)
	{
		short TransferAmount = 0; 
		char AskUser = 'Y';
		cout << "Enter Transfer Amount ? ";
		cin >> TransferAmount;

		while (TransferAmount < 1 || TransferAmount > SoursClient.AcountBalance)
		{
			cout << "Amount Exceeds The available Balance , Enter another Amount ? ";
			cin >> TransferAmount;
		}
		cout << "Are You Sure You Want to Perform This Operation y/n ? ";
		cin >> AskUser;
		if (toupper(AskUser) == 'Y')
		{
			SoursClient.Transfer(TransferAmount, DestinationClient);
			return true;
		}
	    	return false;

	}
	
public:


	static void ShowTranseferScreen()
	{
		_DrawScreenHeader("\t Transfer Main Screen ");
		clsBanckClient SoursClient = _FindClient("Please Enter Account Number To Transfer From : ");
		_PrintCard(SoursClient);
		clsBanckClient DestinstionClient = _FindClient("Please Enter Account Number To Transfer To : ");
		_PrintCard(DestinstionClient);
		if (_SendTransfer(SoursClient, DestinstionClient))
		{
			
			cout << "\n Transfer Done SuccessFully : \n";
	         _PrintCard(SoursClient);
		     _PrintCard(DestinstionClient);
		}
	}


};

