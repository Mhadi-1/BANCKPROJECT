#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{



	string _Value; 
	static string _convertletter(string S1, bool Machcase = true)
	{
		bool IsFristLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFristLetter)
			{
				Machcase ? S1[i] = toupper(S1[i]) : S1[i] = tolower(S1[i]);

			}
			IsFristLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	static string _convertstring(string S1, bool Machcase = true)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			Machcase ? S1[i] = toupper(S1[i]) : S1[i] = tolower(S1[i]);
		}
		return S1; 
	}
	static char _invertcase(char Char1)
	{
		
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}
	static void _CountStringLetters(string S1)
	{
		short CapitalLeeters = 0;
		short SmallLetters = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			!ispunct(S1[i]) && islower(S1[i]) ? SmallLetters++ : isupper(S1[i]) ? CapitalLeeters++ : false;
		}

		cout << " String length          : " << S1.length() << endl;
		cout << " String Capital Letters : " << CapitalLeeters << "\n";
		cout << " String Small Letters   : " << SmallLetters << "\n";
	}
	static bool _Vowel(char Character)
	{
		Character = tolower(Character);
		return (Character == 'a' || Character == 'e' || Character == 'o' || Character == 'i' || Character == 'u') ? true : false;
	}
	static short _CountVowel(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			_Vowel(S1[i]) ? Counter++ : false;
		}
		return Counter;
	}
	static void _VowelOnString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (_Vowel(S1[i]))
			{
				cout << S1[i] << endl;
			}

		}
	}
	static void _Str_Separate(string S1)
	{
		short Position = 0;
		string Delemter = " ";
		string Word = " ";
		while((Position = S1.find(Delemter)) != S1.npos)
		{
			Word = S1.substr(0, Position);
			if (Word != " ")
			{
				cout << Word << endl;
			}
			S1.erase(0, Position + Delemter.length());
		}
		if (S1.length() != 0)
		{
			cout << S1 << endl;
		}
	}
	static vector<string> _Spilt_str_to_Vector(string S1 , string Delemter = " ")
	{
		short Position = 0;
		string Word = " ";
		vector<string> vSpilt;
		while ((Position = S1.find(Delemter)) != S1.npos)
		{
			Word = S1.substr(0, Position);
			if (Word != " ")
			{
				vSpilt.push_back(Word);
			}
			S1.erase(0, Position + Delemter.length());
		}
		if (S1.length() != 0)
		{
			vSpilt.push_back(S1);

		}
		return vSpilt;
	}
	static string _Join_Str(vector<string> S1, string Separater)
	{
		string lineWord = " ";

		for (string &C : S1)
		{
		lineWord = lineWord + C + Separater;
		}


		return lineWord.substr(0, lineWord.length() - Separater.length());
	}
public:
	clsString()
	{
		_Value = " ";
	}
	clsString(string value)
	{
		_Value = value;
	}
	void setValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}

	_declspec(property(get = GetValue, put = setValue)) string Value;


	static short CountWords(string Words)
	{
		short Postion = 0; 
		string Delemter = " ";
		Postion = Words.find(Delemter);
		string Word = " ";
		short Counter = 0;
		while (Postion != Words.npos)
		{
			Word = Words.substr(0, Postion);
			if (Word != " ")
			{
				Counter++;
			}
			Words.erase(0, Postion + Delemter.length());
			Postion = Words.find(Delemter);

		}
		if (Words != " ")
		{
			Counter++;
		}
		return Counter; 
	}
	static void GetFristLetter(string S1)
	{
		short position = 0; 
		string Delimiter = " "; 
		string Word = " "; 
		while ((position = S1.find(Delimiter)) != S1.npos)
		{
			Word = S1.substr(0, position);
			if (Word != " ")
			{
				cout << Word[0] << endl;
			}
			S1.erase(0, position + Delimiter.length());
		}
		if (S1.length() != 0)
		{
			cout << S1[0] << endl;;
		}
	}
	static void Count_Str_Letter(string S1)
	{
		_CountStringLetters(S1);
	}

	static string Join_Str(string Array[], short ArrayLenght, string Separater)
	{
		string S1; 
		for (short i = 0; i < ArrayLenght; i++)
		{
			S1 = S1 + Array[i] + Separater;
		}
		return S1.substr(0, S1.length() - Separater.length());
	}
	static string Join_Str(vector<string> S1 ,string Separater)
	{
		return _Join_Str(S1, Separater);
	}
	static string Trim_Left(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
			return S1.substr(i, S1.length()-i);

			}

		}
		return " ";
	}
	static string Trim_right(string S1)
	{
		for (short i = S1.length() - 1 ; i >= 0 ; i--)
			if (S1[i] != ' ')
			{
			return S1.substr(0, i+1);
			}
		return " ";
	}
	static string Trim(string S1)
	{
		return (Trim_right(Trim_Left(S1)));
	}
	static short CountVowel(string S1)
	{
		return _CountVowel(S1);
	}
	static void Str_Vowels(string S1)
	{
		_VowelOnString(S1);
	}
	static string upperFristLetter(string S1)
	{
		return _convertletter(S1);
	}
	static string lowerFristLetter(string S1)
	{
		return _convertletter(S1, false);
	}
	static string st_toupper(string S1)
	{
		return _convertstring(S1);
	}
	static string st_tolower(string S1)
	{
		return _convertstring(S1, false);
	}
	static vector<string>Spilt_str_to_Vector(string S1 , string Delemter = " ")
	{
		return _Spilt_str_to_Vector(S1,Delemter);
	}
	static char invertcharacter(char C)
	{
		return _invertcase(C);
	}
	enum _enTypeLetters { capital = 0, samll = 1,  all =2 };
    static short _whatlettertocount(string S1, char LetterToCount , _enTypeLetters Typeletter = _enTypeLetters::all)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (Typeletter == _enTypeLetters::samll)
			{
				(S1[i] == LetterToCount) ? Counter++ : false;

			}
			else if (Typeletter == _enTypeLetters::capital)
			{
				(S1[i] == toupper(LetterToCount)) ? Counter++ : false;

			}
			else if (Typeletter == _enTypeLetters::all)
			{
				if (tolower(S1[i]) == tolower(LetterToCount))
					Counter++;
			}
		}
		return Counter;
	}
	static bool is_vowel(char character)
	{
		return _Vowel(character);
	}
	static void Separate_Str(string S1)
	{
		_Str_Separate(S1);
	}
	static string reverse_string(string S1)
	{
		string Word = " ";
		vector<string> vSpilt = _Spilt_str_to_Vector(S1);
		vector<string>::iterator iter = vSpilt.end();
		while (iter != vSpilt.begin())
		{
			--iter;
			Word = Word + *iter + " ";
		}
		return Word.substr(0, Word.length() -1 );

	}
	static string repalce_str(string S1, string StringToReplace, string sRepalceTo)
	{
		vector<string> vSplit = Spilt_str_to_Vector(S1); 
		for (string& cS : vSplit)
		{
			if (st_tolower(cS) == st_tolower(StringToReplace))
			{
				cS = sRepalceTo; 

			}
		}

		return Join_Str(vSplit, " ");

	}
	static string Remove_Puncution(string S1)
	{
		string Words = " ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				Words = Words + S1[i];
			}
		}
		return Words;
	}

	string Remove_Puncution() 
	{
		return Remove_Puncution(_Value);
	}
	string repalce_str(string StringToReplace, string sRepalceTo)
	{
		return repalce_str(_Value, StringToReplace, sRepalceTo);
	}
	string reverse_string()
	{
		return reverse_string(_Value);
	}
	string Trim_Left()
	{
		return Trim_Left(_Value);
	}
	string Trim_right()
	{
		return Trim_right(_Value);
	}
	string Trim()
	{
		return Trim(_Value);
	}
	vector <string> Spilt_str_to_Vector()
	{
		return _Spilt_str_to_Vector(_Value);
	}
	void Separate_Str()
	{
		_Str_Separate(_Value);
	}
	void Str_Vowels()
	{
		_VowelOnString(_Value);
	}
	short CountVowel()
	{
		return _CountVowel(_Value);
	}
	short _whatlettertocount(char LetterToCount, _enTypeLetters Typeletter = _enTypeLetters::all)
	{
		return _whatlettertocount(_Value, LetterToCount , Typeletter);
	}
	short CountWords()
	{
		return CountWords(_Value);
	}
	void Count_Str_Letter()
	{
		_CountStringLetters(_Value);
	}
	void GetFristLetter()
	{
		GetFristLetter(_Value);
	}
	string upperFristLetter()
	{
		return upperFristLetter(_Value);
	}
	string lowerFristLetter()
	{
		return lowerFristLetter(_Value);
	}
	string st_toupper()
	{
		return st_toupper(_Value);
	}
	string st_tolower()
	{
		return st_tolower(_Value);
	}
	static string Replace_string(string S1, string StringToReplace, string ReplaceTo)
	{
		short Pos = S1.find(StringToReplace); 
		while (Pos != S1.npos)
		{
			S1 = S1.replace(Pos, StringToReplace.length(), ReplaceTo);
			Pos = S1.find(StringToReplace);
		}
		return S1; 

	}
    

};

