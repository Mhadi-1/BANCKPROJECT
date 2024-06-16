#pragma once
#include <iostream>
#include <string>

using namespace std; 

class clsPerson 
{

private:

	string _fristname;
	string _lastname;
	string _phonenumber;

public:

	clsPerson()
	{
	}
	clsPerson(string fristname, string lastname, string phonenumber)
	{
		_fristname = fristname;
		_lastname = lastname;
		_phonenumber = phonenumber;
	}
	void setFirstname(string fristname)
	{
		_fristname = fristname;
	}
	string Getfisrname()
	{
		return _fristname;
	}
	_declspec(property(get = Getfisrname, put = setFirstname))  string FirstName;
	void setLastname(string lastname)
	{
		_lastname = lastname;
	}
	string Getlastname()
	{
		return _lastname;
	}
	_declspec(property(get = Getlastname, put = setLastname))  string LastName;
	string FullName()
	{
		return _fristname + " " + _lastname;
	}
	void setPhonenumber(string phonenumebr)
	{
		_phonenumber = phonenumebr;
	}
	string Getphonenumber()
	{
		return _phonenumber;
	}
	_declspec(property(get = Getphonenumber, put = setPhonenumber))  string PhoneNumber;

	
	
}; 

