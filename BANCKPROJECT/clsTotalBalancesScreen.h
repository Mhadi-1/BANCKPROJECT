#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBanckClient.h"
#include "clsInputValidedate.h"
#include "clsScreen.h"
class clsTotalBalancesScreen : protected clsScreen
{

private:


    static void _PrintClientRecordBalanceLine(clsBanckClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAcountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AcountBalance;
    }

public:

    static void ShowTotalBalances()
    {
        vector <clsBanckClient> vClients = clsBanckClient::GetClientsData();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << 
        "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" <<

        "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBanckClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBanckClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t  ( " << clsInputValidedate::NumberToText(TotalBalances) << ")";
    }



};

