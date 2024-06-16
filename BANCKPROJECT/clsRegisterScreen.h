#pragma once
#include "clsUsersBank.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsScreen.h"
class clsRegisterScreen : protected clsScreen
{

private:


	static void _PrintClientRecordLine(clsUsersBank::stLoginRegistreRecord LoginRegistreRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegistreRecord.Date_Time;
		cout << "| " << setw(20) << left << LoginRegistreRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegistreRecord.PassWord;
		cout << "| " << setw(10) << left << LoginRegistreRecord.Permission;

	}


public:

	static void ShowRegisterList()
	{
		vector<clsUsersBank::stLoginRegistreRecord> vStLoginRegistreRecord = clsUsersBank::GetRegisterDataList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t    (" + to_string(vStLoginRegistreRecord.size()) + ") Client(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vStLoginRegistreRecord.size() == 0)
			cout << "\t\t\t\t No Clint Available In System!\n ";
		for (clsUsersBank::stLoginRegistreRecord& LoginRegistreRecord : vStLoginRegistreRecord)
		{

			_PrintClientRecordLine(LoginRegistreRecord);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	};



};

