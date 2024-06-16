#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsUsersBank.h"
#include "clsScreen.h"


class clsListUsersScreen : protected clsScreen 
{


private: 

    static void _PrintUserRecordLine(clsUsersBank User)
    {

        cout << setw(10) << left << "" << "| " << setw(15) << left << User.GetUserName();
        cout << "| " << setw(10) << left << User.PassWord;
        cout << "| " << setw(15) << left << User.FullName();
        cout << "| " << setw(10) << left << User.Permissions;
        cout << "| " << setw(15) << left << User.PhoneNumber;

    }

public:

    static void ShowUsersListScreen()
   {
         vector<clsUsersBank> vUsers = clsUsersBank::GetUsersData();
         string Title = "\t  User List Screen";
         string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(10) << left << "" << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(15) << "FullName";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "| " << left << setw(15) << "PhoneNumber";
        cout << setw(8) << left << "" << "\n\t______________________________________________";
        cout << "______________________________________________\n" << endl;

        if(vUsers.empty())
            cout << "\t\t\t\tNo Users Available In the System!";

        for (clsUsersBank & User : vUsers)
        {
            _PrintUserRecordLine(User);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t______________________________________________";
        cout << "______________________________________________\n" << endl;
   }

};

