#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsInputValidedate.h"
#include "clsDate.h"
#include "Global.h"
#include "clsUtil.h"

// bussines Layer

class clsBanckClient : public clsPerson
{

private : 

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddnewMode = 2 , DeleteMode = 3 };
	enMode _Mode;
	string _AcountNumber; 
	string _Pincode; 
	float _AcountBalnce;
	static clsBanckClient _Client;

    void _setAccountNumber(string AccountNumber)
	{
		_AcountNumber = AccountNumber;
	};
	static clsBanckClient _ConvertLineRecordtoClientObject(string Record)
	{
		vector<string> vClinet; 

		vClinet = clsString::Spilt_str_to_Vector(Record, "#//#");

		return clsBanckClient(enMode::UpdateMode,vClinet[0], vClinet[1], vClinet[2], vClinet[3],clsUtil::decryptionwords(vClinet[4]), stof(vClinet[5]));
	}
	static string _ConvertClientObjectRecordToLineString(clsBanckClient Client , string Separetor = "#//#")
	{
		string LineString = "";
		LineString = LineString + Client.FirstName + Separetor;
		LineString += Client.LastName + Separetor;
		LineString += Client.PhoneNumber + Separetor;
		LineString += Client._AcountNumber + Separetor;
		LineString += clsUtil::encryptionwords(Client._Pincode) + Separetor;
		LineString += to_string(Client._AcountBalnce);
		return LineString;
	}
    static string _GetClientsFileName()
	{
		return "ClinetFile.txt";
	}
	static clsBanckClient _GetEmptyClinet()
	{
		return clsBanckClient(enMode::EmptyMode,"", "", "", "", "", 0);
	}
	void _AddDataLineToFile(string DataLine)
	{
		fstream ClientsFile; 
		ClientsFile.open(_GetClientsFileName(), ios::out | ios::app);
		if (ClientsFile.is_open())
		{
			ClientsFile << DataLine << endl;
			ClientsFile.close();
		}
	}
	static void _SaveClientsDataToFile(vector<clsBanckClient> vClients)
	{
		fstream ClientsFile; 
		string FileName = _GetClientsFileName();
		ClientsFile.open(FileName, ios::out);
		if (ClientsFile.is_open())
		{
			string Line = "";
			for (clsBanckClient &Client : vClients)
			{
				if (Client._Mode != enMode::DeleteMode)
				{
				  Line = _ConvertClientObjectRecordToLineString(Client, "#//#");
				  ClientsFile << Line << endl;

				}

				
			}
			ClientsFile.close();
		}
	}
	static vector<clsBanckClient> _LoadsClientsDataFromFile()
	{
		fstream ClinetsFile; 
		string LineRecord; 
		string ClientFileName = _GetClientsFileName();
		vector<clsBanckClient> vClinetBack;
		ClinetsFile.open(ClientFileName, std::ios::in);
		if (ClinetsFile.is_open())
		{
			while (getline(ClinetsFile,LineRecord))
			{
				clsBanckClient Client = _ConvertLineRecordtoClientObject(LineRecord);
				vClinetBack.push_back(Client);
			}
			ClinetsFile.close();
			return vClinetBack;
		}
	} 
	void _Update()
	{
		 vector<clsBanckClient> vClinets = _LoadsClientsDataFromFile();
		 for (clsBanckClient &Client : vClinets)
		 {
			 if (Client.GetAcountNumber() == this->_AcountNumber)
			 {
				 Client = *this;
				 break;
			 }
		 }
		 _SaveClientsDataToFile(vClinets);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectRecordToLineString(*this));
	}
	struct stTransferlogRegisterRecord;
	static stTransferlogRegisterRecord _ConvertDataLineTosClientRecord(string stDataline, string Separetor = "#//#")
	{
		vector<string> vDataRecord = clsString::Spilt_str_to_Vector(stDataline, Separetor);
		stTransferlogRegisterRecord TransferRegisterRecord; 
		TransferRegisterRecord.DateTime = vDataRecord[0];
		TransferRegisterRecord.SoursClinetAccountNum = vDataRecord[1];
		TransferRegisterRecord.DestinationClientAccountNum = vDataRecord[2];
		TransferRegisterRecord.Amount = stoi(vDataRecord[3]);
		TransferRegisterRecord.SoursClientBalance = stoi(vDataRecord[4]);
		TransferRegisterRecord.DestinationClientBalance = stoi(vDataRecord[5]);
		TransferRegisterRecord.UsreName = vDataRecord[6];
		return TransferRegisterRecord;
	}
	string _PerparteTransferLog(short Amount , clsBanckClient DestintionClient , string Separetor = "#//#")
	{
		clsDate Date; 
		string TransferDetalies; 
		TransferDetalies += Date.DateToString() + "-" + Date.GetSystemDateTimeString() + Separetor;
		TransferDetalies += _AcountNumber + Separetor + DestintionClient._AcountNumber + Separetor;
		TransferDetalies += to_string(Amount)   + Separetor + to_string(AcountBalance) + Separetor; 
		TransferDetalies += to_string(DestintionClient.AcountBalance) + Separetor;
		TransferDetalies += CurrantUser.FirstName;
		return TransferDetalies;
	}
	bool _RegisterTransferLog(short Amount, clsBanckClient& DestintionClient)
	{
		fstream fTransfer;
		string stDataLine = _PerparteTransferLog(Amount, DestintionClient);
		fTransfer.open("TransferRegisterLog.txt", ios::in | ios::app);
		if (fTransfer.is_open())
		{
			fTransfer << stDataLine << endl;
			fTransfer.close();
			return true;;
		}
		return false;
	}
	static vector<stTransferlogRegisterRecord> _LoadClientDataRecord()
	{
		fstream fTransfer;
		string stDataLine = " ";
		vector<stTransferlogRegisterRecord> vTransferlogRegisterRecord;
		fTransfer.open("TransferRegisterLog.txt", ios::in);
		if (fTransfer.is_open())
		{
			stTransferlogRegisterRecord TransferlogRegisterRecord;
			while (getline(fTransfer, stDataLine))
			{
				TransferlogRegisterRecord = _ConvertDataLineTosClientRecord(stDataLine);
				vTransferlogRegisterRecord.push_back(TransferlogRegisterRecord);
			}
			fTransfer.close();
		}
		return vTransferlogRegisterRecord;
	};
public:

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	};
	clsBanckClient(enMode Mode,string Fristname, string Lastname, string phonenumber,
    string AcountNumber, string Pincode, float AcountBalance) :
		clsPerson(Fristname, Lastname, phonenumber)
	{
		_AcountNumber = AcountNumber;
		_Pincode = Pincode;
		_AcountBalnce = AcountBalance;
		_Mode = Mode; 
	}; 
	string GetAcountNumber()
	{
		return _AcountNumber; 
	}
	void setPinCode(string pincode)
	{
		_Pincode = pincode; 
	}
	string GetPincode()
	{
		return _Pincode; 
	}
	_declspec(property(get = GetPincode, put = setPinCode)) string PinCode;
	void setAcountBalance(float AcountBalance)
	{
		_AcountBalnce = AcountBalance; 
	}
	float GetAcountBalance()
	{
		return _AcountBalnce; 
	}
	_declspec(property(get = GetAcountBalance, put = setAcountBalance)) float AcountBalance;
	static clsBanckClient Find(string AcountNumber)
	{
		vector<clsBanckClient> vClinets;
		vClinets = _LoadsClientsDataFromFile();
		for (clsBanckClient &Client : vClinets)
		{
			if (Client._AcountNumber == AcountNumber)
			{
				return Client; 
			}
		}
		return _GetEmptyClinet();
	}
	static clsBanckClient Find(string AcountNumber , string PindCode)
	{
		clsBanckClient Client = Find(AcountNumber);
		
		if (Client._Mode == enMode::EmptyMode)
		{
			return  _GetEmptyClinet();
		}
		if (Client.PinCode == PindCode)
			return Client; 
	}
	enum enSaveResult{svfildEmptyObject = 0 , svSuccessful = 1 , svFildAccounNumberExist = 2 };
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsBanckClient::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResult::svfildEmptyObject;

			}
		}
		case clsBanckClient::UpdateMode:
		{

			   _Update();
			   return enSaveResult::svSuccessful;

		}
		case clsBanckClient::AddnewMode:
		{

		    if (IsClinentExist(_AcountNumber))
			{
				return svFildAccounNumberExist;

			}
			else
			{

				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSuccessful;
			}
		}
		    default:
			break;
		}

	}
	bool Delete()
	{
		vector<clsBanckClient> vClients = _LoadsClientsDataFromFile();
		for (clsBanckClient& Clinet : vClients)
		{
			if (Clinet._AcountNumber == _AcountNumber)
			{
				Clinet._Mode = enMode::DeleteMode;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClinet();
		return true;

	}
	static bool IsClinentExist(string AcountNumber)
	{
		clsBanckClient Client = Find(AcountNumber); 
		return (!Client.IsEmpty());
	}
	static clsBanckClient GetAddNewClinet(string AccountNumber)
	{
		return clsBanckClient(enMode::AddnewMode, "", "", "",AccountNumber, "", 0);
	}    
	static vector<clsBanckClient> GetClientsData()
	{
		return _LoadsClientsDataFromFile();
	}
	static double GetTotalBalances()
	{
		vector <clsBanckClient> vClients = GetClientsData();
		double TotalBalnce = 0; 
		for (clsBanckClient& Client : vClients)
		{
			TotalBalnce += Client.AcountBalance;
		}
		return TotalBalnce; 
	}       
	bool Deposit(float Amount)
	{
		if (!IsEmpty())
		{
		   _AcountBalnce += Amount;
		   Save(); 
		   return true; 
		}
		return false; 

	}
	bool WithDraw(float Amount)
	{
		if (!IsEmpty() && Amount <= _AcountBalnce)
		{
			_AcountBalnce -= Amount;
			Save();
			return true;
		}
		  return false;
	}
	bool Transfer(short Amount, clsBanckClient &DestintionClient)
	{
		if (Amount > AcountBalance)
		{
			return false;
		}

		 WithDraw(Amount);
		 DestintionClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestintionClient);
		return true;
		
	}
    struct stTransferlogRegisterRecord
	{
		string DateTime;
		string SoursClinetAccountNum; 
		string DestinationClientAccountNum; 
		short Amount; 
		short SoursClientBalance; 
		short DestinationClientBalance; 
		string UsreName;
	};
	static vector <stTransferlogRegisterRecord> GetTransferDataRecord()
	{
		return _LoadClientDataRecord();
	}
};

