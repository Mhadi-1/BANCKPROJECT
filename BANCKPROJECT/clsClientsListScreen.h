#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsBanckClient.h"
#include "clsScreen.h"

class clsClientsListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBanckClient Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAcountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AcountBalance;

	}

public: 
	 static void ShowClientsList()
	 {
		vector<clsBanckClient> vClients = clsBanckClient::GetClientsData();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

	
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\t No Clint Available In System!\n ";
		for (clsBanckClient& Client : vClients)
		{
			_PrintClientRecordLine(Client);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



	 }

};

