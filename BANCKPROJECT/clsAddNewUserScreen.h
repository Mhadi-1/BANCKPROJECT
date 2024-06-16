#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUsersBank.h"
#include "clsString.h"
#include "clsInputValidedate.h"
#include "clsPermissions.h"

class clsAddNewUserScreen : protected clsScreen
{
	
private:

	   static void  _Print(clsUsersBank User)
	   {
		   cout << "\n User Card:";
		   cout << "\n ___________________";
		   cout << "\n FirstName   : " << User.FirstName;
		   cout << "\n LastName    : " << User.LastName;
		   cout << "\n Full Name   : " << User.FullName();
		   cout << "\n Phone       : " << User.Getphonenumber();
		   cout << "\n Acc. Number : " << User.GetUserName();
		   cout << "\n Password    : " << User.PassWord;
		   cout << "\n Permission  : " << User.Permissions;
		   cout << "\n ___________________\n";

	   }
	   static void  _ReadInfo(clsUsersBank& NewUser)
	   {
		   NewUser.FirstName   = clsInputValidedate::ReadString(" Enter User Frist Name  : ");
		   NewUser.LastName    = clsInputValidedate::ReadString(" Enter User Last Name   : ");
		   NewUser.PassWord    = clsInputValidedate::ReadString(" Enter User PassWord    : "); 
		   NewUser.PhoneNumber = clsInputValidedate::ReadString(" Enter User PhoneNumber : ");
		   NewUser.Permissions = clsPermissions::ReadPermissionsToSet();
	   }
	   static void  _SaveInfo(clsUsersBank NewUser)
	   {
		   clsUsersBank::enSaveRseult SaveResult = NewUser.Save();

		   switch (SaveResult)
		   {
		   case clsUsersBank::eSaveSuccessfully:
			   cout<< "\n User Saved Successfully";
			   break;
		   case clsUsersBank::eSavefildEmptyObject:
			   cout << "\n Save fild Empty Object";
			   break;
		   case clsUsersBank::eFildAccounNumberExist:
			   cout << "\n Fild AccounNumber Already Exist";
			   break;
		   default:
			   break;
		   }
	   }
public: 

	     static void ShowAddNewUserScreen()
	     {
		    system("cls"); 
		   _DrawScreenHeader("\t Add New User Screen ");
		    string UserName = clsInputValidedate::ReadString(" Enter User AccountNumber Please :");
		   
		   while (clsUsersBank::IsAccountExist(UserName))
		   {
		   	   cout << "\n AccountNumber Is ( "<<UserName<<" ) Already Exist try Agian : "; 
		   	   UserName = clsInputValidedate::ReadString("");
		   }
		   
		    clsUsersBank NewUser = clsUsersBank::GetAddNewUser(UserName);
		    _ReadInfo(NewUser); 
		    
		    _SaveInfo(NewUser);
		    _Print(NewUser);
		

	     }


};

