#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtil.h"
#include "Global.h"
using namespace std; 

class clsUsersBank : public clsPerson 
{

 private:


    enum enMode {eUpdateMode = 1 , eEmptymode = 2 , eAddNew = 3 , eMarkForDelete = 4 };
	 string _UserName; 
	 string _PassWord; 
	 enMode  _Mode;
	 short _Permissions;

	static string _GetUsersFileName()
	 {
		 return "Users.txt";
	 }
	static clsUsersBank _ConverLineRecordToUserObject(string Line)
	{
		vector<string> vUsers = clsString::Spilt_str_to_Vector(Line,"#//#");
		return clsUsersBank(enMode::eUpdateMode, vUsers[0], vUsers[1], vUsers[2],vUsers[3], clsUtil::decryptionwords(vUsers[4]),stoi(vUsers[5]));

	}
	
	struct stLoginRegistreRecord;
    static stLoginRegistreRecord _ConverLineRecordToUserObjec(string Line)
	{
		stLoginRegistreRecord LoginRegisterRecord; 

		vector<string> vRegisterData = clsString::Spilt_str_to_Vector(Line, "#//#");

		LoginRegisterRecord.Date_Time = vRegisterData[0];
		LoginRegisterRecord.UserName = vRegisterData[1];
		LoginRegisterRecord.PassWord = clsUtil::decryptionwords(vRegisterData[2]);
		LoginRegisterRecord.Permission = stoi(vRegisterData[3]);

		return LoginRegisterRecord;
	}
	static string _ConverObjectDataRecordToDataLine(clsUsersBank User , string Seperator = "")
	{
		string DataLine = "";

		DataLine = User.GetUserName() + Seperator;
		DataLine += User.FirstName    + Seperator;
		DataLine += User.LastName     + Seperator;
		DataLine += User.PhoneNumber  + Seperator;
		DataLine += clsUtil::encryptionwords(User.PassWord) + Seperator;
		DataLine += to_string(User._Permissions);
		return DataLine; 

	}
	static vector <clsUsersBank> _LoadsUsersDataFromFile()
	{
		vector <clsUsersBank> vUsers; 
	    string Line; 

		fstream UsersFile; 
		UsersFile.open(_GetUsersFileName(), ios::in);

		if (UsersFile.is_open())
		{
			while (getline(UsersFile, Line))
			{
				clsUsersBank User = _ConverLineRecordToUserObject(Line);
				vUsers.push_back(User);
			}
			
			UsersFile.close();
		}
		return vUsers; 

	}
	static clsUsersBank GetEmptyObject()
	{
		return clsUsersBank(enMode::eEmptymode, "", "", "", "", "", 0);
	}
	static void _SaveDataToFile(vector <clsUsersBank> vUsers)
	{

		fstream UsersFile; 
		string DataLine; 
		UsersFile.open(_GetUsersFileName(), ios::out); 
		if (UsersFile.is_open())
		{
			for (clsUsersBank& User : vUsers)
			{
				if (User._Mode != enMode::eMarkForDelete)
				{
				  DataLine = _ConverObjectDataRecordToDataLine(User,"#//#");
				  UsersFile << DataLine << endl;

				}

			    
			}
			UsersFile.close();
		}

	}
	void _Update()
	{
		vector <clsUsersBank> vUsers = _LoadsUsersDataFromFile(); 

		for (clsUsersBank & User : vUsers)
		{
			if (User._UserName == _UserName)
			{
				User = *this; 
				break;
			}
		}

		_SaveDataToFile(vUsers); 

	}
	void _AddNew()
	{
		fstream UsersFile; 
		UsersFile.open(_GetUsersFileName(), ios::out | ios::app);
		if (UsersFile.is_open())
		{
			UsersFile << _ConverObjectDataRecordToDataLine(*this, "#//#") << endl;
			UsersFile.close();
		}
	}
	clsUsersBank _Delete()
	{
		vector <clsUsersBank> vUsers = _LoadsUsersDataFromFile(); 
		for (clsUsersBank & User : vUsers)
		{
			if (User.GetUserName() == _UserName && User.PassWord == _PassWord)
			{
				User._Mode = enMode::eMarkForDelete;
				break;
			}
		}
		_SaveDataToFile(vUsers);
		return GetEmptyObject(); 
	}
	string _PerpartLoginRegister(string Separetor = "#//#")
	{

		clsDate Date;
		string RegisterDate_Time = Date.DateToString() + "-" + Date.GetSystemDateTimeString() + Separetor +
			this->FirstName + Separetor +
			clsUtil::encryptionwords(this->PassWord) + Separetor +
			to_string(this->Permissions);
		return RegisterDate_Time;
	}

	static vector<stLoginRegistreRecord> _LoadRegisterData()
	{
		fstream fRegisterLogin;
		string StDataLine;
		vector<stLoginRegistreRecord> vstLoginRegisterRecord;
		stLoginRegistreRecord LoginRegisterRecord;

		fRegisterLogin.open("LoginRegister.txt", ios::in);

		if (fRegisterLogin.is_open())
		{
			while (getline(fRegisterLogin, StDataLine))
			{
				LoginRegisterRecord = _ConverLineRecordToUserObjec(StDataLine);
				vstLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			fRegisterLogin.close();
		}
		return vstLoginRegisterRecord;
	}

public:

	
	  clsUsersBank(enMode Mode, string UserName, string FristName, string LastName, string PhoneNumber, string PassWord
		, short Permissions) : clsPerson(FristName, LastName, PhoneNumber)
	  {
		 _Mode = Mode;
		 _UserName = UserName; 
		 _PassWord = PassWord;
		 _Permissions = Permissions; 
	  }
	  string GetUserName()
	  {
		 return _UserName;
	  }
	  void setPassWord(string PassWord)
	  {
		  _PassWord = PassWord; 
	  }
	  string GetPassWord()
	  {
		  return _PassWord; 
	  }
	  _declspec(property(get = GetPassWord, put = setPassWord)) string PassWord; 
	  void setPermissions(short Permissions)
	  {
		  _Permissions = Permissions; 
	  }
	  short GetPermissions()
	  {
		  return _Permissions;
	  }
	  _declspec(property(get = GetPermissions, put = setPermissions)) short Permissions; 
	  static clsUsersBank Find(string UserName , string PassWord)
	  {
		  vector<clsUsersBank> vUsers = _LoadsUsersDataFromFile(); 
		  for (clsUsersBank& User : vUsers)
		  {
			  if (User._UserName == UserName && User._PassWord == PassWord)
			  {
				  return User; 
			  }
		  }
		  return GetEmptyObject(); 
	  }
	  static clsUsersBank Find(string UserName)
	  {

		  vector<clsUsersBank> vUsers = _LoadsUsersDataFromFile();
		  for (clsUsersBank& User : vUsers)
		  {
			  if (User._UserName == UserName)
			  {
				  return User;
			  }
		  }
		  return GetEmptyObject(); 
	  }
	  static bool IsAccountExist(string UserName)

	  {
		  vector<clsUsersBank> vUsers = _LoadsUsersDataFromFile();
		  for (clsUsersBank& User : vUsers)
		  {
			  if (User.GetUserName() == UserName)
			  {
				  return true; 
			  }
		  }
		  return false; 
	  }
	  static bool IsAccountExist(string UserName, string PassWord)
	  {
		 clsUsersBank User =  Find(UserName, PassWord); 
		 return (!User.IsEmpty());
	  }
	  bool IsEmpty()
	  {
		  return (_Mode == enMode::eEmptymode);
	  }
	  bool IsUserExist()
	  {
		  clsUsersBank  User = Find(_UserName , _PassWord); 
		  return (!User.IsEmpty()) ? true : false;

	  }
	  enum enSaveRseult { eSaveSuccessfully = 1 , eSavefildEmptyObject ,eFildAccounNumberExist };
	  enSaveRseult Save()
	  {
		  switch (_Mode)
		  {

		  case clsUsersBank::eUpdateMode:
		  {
			  _Update(); 
			  *this = Find(_UserName,PassWord); 
			  return eSaveSuccessfully;
		  };

		  case clsUsersBank::eEmptymode:
		  {

			  return eSavefildEmptyObject;
		  };

		  case clsUsersBank::eAddNew:
		  {
			  if (!IsUserExist())
			  {

			     _AddNew(); 
			     _Mode = enMode::eUpdateMode;
			     return eSaveSuccessfully; 

			  }
				  return eFildAccounNumberExist;

		  };

		  default:
			  break;
		  }
	  }
	  static clsUsersBank GetAddNewUser(string UserName)
	  {
		 
			  return clsUsersBank(enMode::eAddNew,UserName,"","","","",-1);
	  }
	  static vector<clsUsersBank> GetUsersData()
	  {
		  return _LoadsUsersDataFromFile();
	  }
	  bool Delete()
	  {
		  if (!this->IsEmpty())
		  {
			*this = _Delete();
			  return true; 
		  }
		  return false; 
	  }
	  static enum enPermissions
	  {
		  pShoClinetList = 1,
		  pAddNewClinet = 2,
		  pDeleteClinet = 4,
		  pUpdateClient = 8,
		  pFindClient = 16,
		  pShowTransaction = 32,
		  pLoginRegister = 62,
		  pShowUsers = 128,
		  pExchange = 256, 
		  pAll = -1
	  };
	  bool CheckAccessPermissions(enPermissions Permission)
	  {
		  if (this->Permissions == pAll)
			  return true;

		  if ( (this->Permissions & Permission) == Permission)
			  return true;
	  }
	  void SaveRegisterLogin()
	  {
		  fstream RegisterLogin;
		  string DateLine = _PerpartLoginRegister();
		  RegisterLogin.open("LoginRegister.txt", ios::in | ios::app);
		  if (RegisterLogin.is_open())
		  {
			  RegisterLogin << DateLine << endl;
			  RegisterLogin.close();
		  }
	  }
	  struct stLoginRegistreRecord
	  {
		  string Date_Time;
		  string UserName;
		  string PassWord;
		  short Permission;
	  };
	  static vector<stLoginRegistreRecord> GetRegisterDataList()
	  {
		  return _LoadRegisterData();
	  }


};

