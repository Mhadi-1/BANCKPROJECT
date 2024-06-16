#pragma once
#include <string>
#include <iostream>
#include "clsBanckClient.h"
#include "clsScreen.h"
#include <iomanip>
class clsTransferScreen : protected clsScreen 
{
private:

	static void PrintTransferLogRecordLine(clsBanckClient::stTransferlogRegisterRecord TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8)  << left  << TransferLogRecord.SoursClinetAccountNum;
		cout << "| " << setw(8)  << left  << TransferLogRecord.DestinationClientAccountNum;
		cout << "| " << setw(8)  << left  << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left  << TransferLogRecord.SoursClientBalance;
		cout << "| " << setw(10) << left  << TransferLogRecord.DestinationClientBalance;
		cout << "| " << setw(8)  << left  << TransferLogRecord.UsreName;


	}



public:

    static void ShowTransferLogScreen()
    {


        vector <clsBanckClient::stTransferlogRegisterRecord> vTransferLogRecord = clsBanckClient::GetTransferDataRecord();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBanckClient::stTransferlogRegisterRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    };

};




