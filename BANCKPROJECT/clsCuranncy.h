#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"

using namespace  std; 

class clsCuranncy
{


private:

	enum enMode{ UpdateMode = 1 , EmptyMode = 2 };
	enMode _Mode; 
	string _Country; 
	string _CurrencyCode;
	string _CurrencyName; 
	float  _Rate; 

	static string GetCurrencyFileName()
	{
		return "Currencies.txt"; 
	}
	static clsCuranncy _ConvertDataLineToCurrencyObject(string DataRecord , string Separetor = "#//#")
	{
		vector<string> vCurrencyRecord; 
		vCurrencyRecord = clsString::Spilt_str_to_Vector(DataRecord, Separetor);

		return clsCuranncy(enMode::UpdateMode , vCurrencyRecord[0], vCurrencyRecord[1], vCurrencyRecord[2], stof(vCurrencyRecord[3]));

	}
    static vector <clsCuranncy> _LoadDataCurrenciesFromFile()
	{
		fstream fcurrency; 

		vector<clsCuranncy> vCurrency; 

		fcurrency.open(GetCurrencyFileName(), ios::in | ios::app); 

		if (fcurrency.is_open())
		{
			string DataLine; 

			while (getline(fcurrency, DataLine))
			{
				vCurrency.push_back(_ConvertDataLineToCurrencyObject(DataLine));
			}
			fcurrency.close(); 
		}
		return vCurrency;
	}
    static clsCuranncy _GetEmptyCurrency()
	{
		return clsCuranncy(enMode::EmptyMode, "", "", "", 0); 
	}
	string _ConvertDataObjectToDataLineSt(clsCuranncy Currency , string Separetor = "#//#")
	{
		string DataLine = ""; 

		DataLine += Currency.GetCurrencyCountry() + Separetor;
		DataLine += Currency.GetCurrencyCode()    + Separetor;
		DataLine += Currency.GetCurrencyName()    + Separetor;
		DataLine += to_string(Currency.GetRate());

		return DataLine;
	}
	bool _SaveDataToFile(vector<clsCuranncy> vCurrency)
	{
		fstream Fcurenncy;
		string DataLine; 
		Fcurenncy.open(GetCurrencyFileName(), ios::out); 
		if (Fcurenncy.is_open())
		{
			for (clsCuranncy& C : vCurrency)
			{
				 DataLine = _ConvertDataObjectToDataLineSt(C);
				 Fcurenncy << DataLine << endl;
			}

			Fcurenncy.close();
			return true;
		}
		return false;


	}
	bool _Update()
	{
		vector<clsCuranncy> vCurrency = _LoadDataCurrenciesFromFile();

		for (clsCuranncy & C : vCurrency)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this; 
				break;
			}
		}
		return _SaveDataToFile(vCurrency);
	}

public:


	// Cunstactor 

	clsCuranncy( enMode CurrencyMode , string CurrencyCountry, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Country = CurrencyCountry; 
		_CurrencyCode = CurrencyCode; 
		_CurrencyName = CurrencyName; 
		_Mode = CurrencyMode; 
		_Rate = Rate; 
	}
	string GetCurrencyCountry()
	{
		return _Country; 

	}
	string GetCurrencyCode()
	{
		return _CurrencyCode; 
	}
	string GetCurrencyName()
	{
		return _CurrencyName; 
	}
	float GetRate()
	{
		return _Rate; 
	}
	bool UpdateRate(float NewRate)
	{
		_Rate = NewRate; 
		return _Update(); 
	}
	bool IsEmpty()
	{
		return (enMode::EmptyMode == _Mode);
	}
	static vector<clsCuranncy> GetCurrencyList()
	{
		return _LoadDataCurrenciesFromFile(); 
	}
	static clsCuranncy GetEmptyCurrency()
	{
		return _GetEmptyCurrency();
	}
	static clsCuranncy FindByCode(string CurrencyCode)
	{
		fstream fcurrency; 
		string DataLine; 
		CurrencyCode = clsString::st_toupper(CurrencyCode); 
		fcurrency.open(GetCurrencyFileName(), ios::in | ios::app); 

		if (fcurrency.is_open())
		{
			while (getline(fcurrency, DataLine))
			{
				clsCuranncy Currency = _ConvertDataLineToCurrencyObject(DataLine); 
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					fcurrency.close();
					return Currency; 
				}
			}
			fcurrency.close();
		}
		return _GetEmptyCurrency(); 
	}
	static clsCuranncy FindByCountry(string CurrencyName)
	{
		vector<clsCuranncy> vCurrency; 
		fstream fcurrency; 
		string DataLine; 
		CurrencyName = clsString::st_toupper(CurrencyName); 
		fcurrency.open(GetCurrencyFileName(), ios::in | ios::app); 

		if (fcurrency.is_open())
		{
			while (getline(fcurrency, DataLine))
			{
				clsCuranncy Currency = _ConvertDataLineToCurrencyObject(DataLine); 
				if (clsString::st_toupper(Currency.GetCurrencyName()) == CurrencyName)
				{
					fcurrency.close();
					return Currency; 
				}
			}
			fcurrency.close();

		}
		return _GetEmptyCurrency();
	}
	static bool  IsCurrencyExist(string CurrencyCode)
	{
		clsCuranncy C1 = clsCuranncy::FindByCode(CurrencyCode); 
		return (!C1.IsEmpty()); 
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToAnrotherCurrency(float Amount, clsCuranncy Currency2)
	{
		float AmountUSD = ConvertToUSD(Amount); 
		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountUSD; 
		}

		return (float)(AmountUSD * Currency2.GetRate());
	}
};

