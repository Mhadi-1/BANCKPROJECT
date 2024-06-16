#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime> 
#include "clsDate.h"

class clsInputValidedate
{

private : 


public:
	static string ReadString(string Message = "")
	{
		string S1; 
		cout << Message ;
		getline(cin>>ws, S1);
		return S1; 

	}
	static bool  IsNumberBettween(int Numb, int From, int To)
	{
		return (Numb >= From && Numb <= To);
	
	}
	static bool IsNumberBettween(double Numb, double From, double To)
	{
		 return (Numb >= From && Numb <= To);;
	}
	static bool IsDateBetween(clsDate dateincrunnet, clsDate DateFrom, clsDate DateTo)
	{
		// Date  >= From && Date <= To 
		if (clsDate::IsDate1AfterDate2(dateincrunnet, DateFrom)
			|| clsDate::IsDate1EqualDate2(dateincrunnet, DateFrom) &&
			clsDate::IsDate1BeforeDate2(dateincrunnet, DateTo) || 
			clsDate::IsDate1EqualDate2(dateincrunnet, DateTo))
		{
			return true; 

		}
		if (clsDate::IsDate1AfterDate2(dateincrunnet, DateTo)
			|| clsDate::IsDate1EqualDate2(dateincrunnet, DateTo) &&
			clsDate::IsDate1BeforeDate2(dateincrunnet, DateFrom) ||
			clsDate::IsDate1EqualDate2(dateincrunnet, DateFrom))
		{
			return true;
		}
		return false; 


	}
	template<typename T> static T ReadNumber(string message ="")
	{
		cout << message;;
		T numb = 0; 
		cin >> numb; 

		while (cin.fail())
		{
			cout << setw(37) << left << " Invalid input. Enter a valid integer : ";
			// Clear the error flag to allow further input
			std::cin.clear();
			// Discard any remaining characters in the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> numb; 
		}
		return numb; 
	}
	template<typename T> static T ReadNumberBettween(T From , T To , string message = "")
	{
		T numb = 0;
		bool Result = false;
		do
		{
			numb = ReadNumber<T>();
			Result = IsNumberBettween(numb, From, To);
			if (Result == false)
	        cout << message;;

		} while (!Result);
		return numb; 
	}
	static bool IsValidDate(clsDate Date)
	{
		return  clsDate::IsValidDate(Date); 
	}
	static string NumberToText(int Number)
	{
		if (Number == 0)
			return "";
		if (Number >= 1 && Number <= 19)
		{
			string ArrayText[] = { "One","Tow","Three","Four","Five","Six","Seven","Eight","Nine","Ten"
			, "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return ArrayText[Number - 1]; 
		}
	    if( Number >=20 && Number <= 99)
		{
			string ArrayText[] = {" " , "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" }; 
			return ArrayText[Number / 10 - 1] + " " + NumberToText(Number % 10);
		}
	    if (Number >= 100 && Number <= 199) 
		{ 
			return"One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
		}
	    if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{ 
			return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{ 
			return"One Million " + NumberToText(Number % 1000000);
		}
	}
	
};

