#pragma once
#include<iostream>
#include<string>
#include"clsBanckClient.h"
#include"clsInputValidedate.h"
#include "clsScreen.h"

class clsDepositScreen : protected clsScreen
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
      static void ShowDeposit()
      {
         _DrawScreenHeader("\t Deposit Screen ");
         string AccountNumber = clsInputValidedate::ReadString(" Enter AccountNumber Please : ");
     
         while (!clsBanckClient::IsClinentExist(AccountNumber))
        {
            cout << "\n Client With AccountNumber Is Not Fount Try Agin : ";
            AccountNumber = clsInputValidedate::ReadString("");

        }
     
         clsBanckClient Clinet = clsBanckClient::Find(AccountNumber);
         _PrintClintCard(Clinet);
         _PrintBalance(Clinet.AcountBalance);
     
         short DepositAmount = 0;
         char AksUser = 'Y';
         DepositAmount = clsInputValidedate::ReadNumber<short>(" Enter Deposit Amount : ");
         cout << "\n Are You sure you want to depoist this amount " << DepositAmount << " y/n : ";
         cin >> AksUser;

         if (toupper(AksUser) == 'Y')
         {
            if (Clinet.Deposit(DepositAmount))
            {
                cout << "\n Balance Deposit Successsfully \n";
                _PrintBalance(Clinet.AcountBalance);
            }
            else
            {
                cout << "\n Fild AccountNumber Exist \n";

            }
         }
      }

};

