#pragma once
#include <iostream>
#include <string>
#include "clsBanckClient.h"
#include "clsInputValidedate.h"
#include "clsScreen.h"

class clsWithDrawScreen : protected clsScreen
{
	
private:

    static void _PrintClintCard(clsBanckClient client)
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
    static void _PrintBalance(short Balance)
    {
        cout << "\n Account balance is : " << Balance << endl;
    }

public:

    static void ShowWithDraw()
    {

        _DrawScreenHeader("\t WithDraw Screen ");
        string AccountNumber = clsInputValidedate::ReadString(" Enter AccountNumber Please : ");

        while (!clsBanckClient::IsClinentExist(AccountNumber))
        {
            cout << " Client With Account ( " << AccountNumber << ") Is not Exist Try Another : ";
            AccountNumber = clsInputValidedate::ReadString("");
        }

        clsBanckClient Client = clsBanckClient::Find(AccountNumber);
        _PrintClintCard(Client);
        _PrintBalance(Client.AcountBalance);


        float withdrawAmount = 0;
        char AksUser = 'n';


        cout << "\n Enter withdraw amount , must be a multiple of five : ";
        withdrawAmount = clsInputValidedate::ReadNumber<float>();

        cout << "\n Are You sure you want to withdraw this amount " << withdrawAmount << " y/n : ";
        cin >> AksUser;

        if (toupper(AksUser) == 'Y')
        {

            if (Client.WithDraw(withdrawAmount))
            {
                cout << "\n balance withdraw Successfully ";
                _PrintBalance(Client.AcountBalance);
            }
            else
            {
                cout << "\n Fild AccountNumber Exist ";
                _PrintBalance(Client.AcountBalance);
            }

        }

    }


};

