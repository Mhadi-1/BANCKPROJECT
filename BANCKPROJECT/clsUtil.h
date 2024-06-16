#pragma once
#include<iostream>
#include<string>
#include "clsDate.h"
#include <cstdlib>
using namespace std;
class clsUtil
{
	static string _ColumSperator(int i)
	{
		if (i < 10) return"   |";
		else return"  |";
	};
public:

	static short ReadNumber()
	{
		short numb = 0; 
		cin >> numb; 
		return numb;
	}
	static  string Tabs(short numb)
	{
		string tab = "\t";
		for (short i = 0; i < numb; i++)
		{
			return tab;
		}
	}
	static void Mulitplication(short from, short to)
	{
		cout << "\n\n\t\t\t Multipliaction Table From "<<from<<" to "<<to<<"\n\n";   
		cout << "\t";
		for (int i = from; i <= to; i++) 
		{ 
			cout << i << "\t"; 
		
		}     
		cout << "\n___________________________________________________________________________________\n";

		for (short i = from; i <= to; i++)
		{
		    cout << i << _ColumSperator(i);

			for (short j = from; j <= to; j++)
			{
				cout << "\t" << (j * i);
			}
			cout << endl;
		}
	}
	enum numberstyptoget { prim = 1 , notprim = 2 };
	static numberstyptoget chickNumber(short numb)
	{
		if (numb % 2 != 0)
		{
			return numberstyptoget::notprim;
		}
		return numberstyptoget::prim;
	}
	static void GetNumbersType(numberstyptoget  type , short numb)
	{
		for (short i = 1; i <= numb; i++)
		{

		 if (chickNumber(i) == type)
		 {
			 cout << i << endl;
		 }

		}
           
	}
	static bool IsPerfectNumber(short numb)
	{
		short divisorsSum = 0; 
		for (short i = 1; i < numb; i++)
		{
			(numb % i == 0) ?(divisorsSum += i) : false;

		}
		return (numb == divisorsSum);

	}
	static void allPerfecrNumberfrom1to_N(short numb)
	{
		for (short i = 1; i < numb; i++)
		{
			if (IsPerfectNumber(i))
			{
				cout << i << endl;
			}
		}
	}
	static void numberInreversed(short numb)
	{
		short reversedOrder = 0; 
		while (numb != 0)
		{
		  reversedOrder = numb % 10; 
		  cout << reversedOrder << endl;
		  numb = numb / 10; 

		}

	}
	static short sumofdigit(short digitnumb)
	{
		short digit = 0;
		while (digitnumb > 0)
		{
			digit += digitnumb % 10;
			digitnumb = digitnumb / 10; 
		}
		return digit;
	}
	static short numberInreversedOrder(short digitnumb)
	{
		short reminder = 0; 
		short sum = 0 ;
		while (digitnumb > 0)
		{
			reminder = digitnumb % 10; 
			digitnumb = digitnumb / 10; 
			sum = sum * 10 + reminder;
		}
		return sum;
	}
	static short countDigitFrequency(short digitToCount, int digitnumber)
	{
		short reminder = 0; 
		short counter = 0; 
		while (digitnumber > 0)
		{
			reminder = digitnumber % 10; 
			(reminder == digitToCount) ? counter++ : false;
			digitnumber = digitnumber / 10; 
		}
		return counter;
	}
	static void countalldigitFreqeuncy(int digitnumber)
	{
		short digitfreqeuncy = 0; 
		for (short i = 0; i <= 10; i++)
		{
			digitfreqeuncy = countDigitFrequency(i, digitnumber); 
			if (digitfreqeuncy > 0)
			{
				cout << " digit " << i << " Frequency " << digitfreqeuncy << endl;
			}
		}
	}
	static void numberInreversed_from_leftto_right(short digitnumb)
	{
		numberInreversed(numberInreversedOrder(digitnumb));
	}
	static bool IsPalendromNumb(short digitnumb)
	{
		return (numberInreversedOrder(digitnumb) == digitnumb);
	} 
	static void printinvertednumberpattern(short numb)
	{
		for (int i = numb; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{ 
				cout << i; 
			}
			cout << "\n";
		}
	}
	static void printinvertednourmalnumberpattern(short numb)
	{
		for (short i = 1; i <= numb; i++)
		{
			for (short j = 1; j <= i; j++)
			{
				cout << i ;
			}
			cout << endl;
		}
	}
	static void printinvertedletterpattern(short numb)
	{
		for (short i = 65 + numb - 1  ; i >= 65; i--)
		{
			for (short j = 1 ; j <= numb - (65 + numb - 1 - i); j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}
	static void printletterpattern(short numb)
	{
		for (short i = 65; i <= 65 + numb - 1; i++)
		{
			for (short j = 1; j <= i - 65 + 1; j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}
	static void printallwordsfromAAAtoZZZ()
	{
		string word = " ";
		for (short i = 65; i <= 90; i++)
		{
			for (short j = 65; j <= 90; j++)
			{
				for (short k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << word;
					word = " ";
					cout << "\n";
				}
			}
		}
	}
	static bool gussPassword(string password)
	{
		string word;
		short counter = 0; 
		for (short i = 65; i <= 90; i++)
		{
			for (short j = 65; j <= 90; j++)
			{
				for (short k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					counter++;
					cout << "Trail[" << counter << "] " << word << endl;
					if (word == password)
					{
						cout << "Password " << password << endl;
						cout << "found after " << counter;
						return true;
					}
					word ="";
				}
			}
		}
	}
	static string encryptionwords(string word , short EncryptionKey = 3 )
	{
		for (short s = 0 ; s < word.length(); s++)
		{
			word[s] = char((int)word[s] + EncryptionKey);
		}
		return word;
	}
	static string decryptionwords(string word, short DecryptionKey = 3 )
	{
		for (short s = 0; s < word.length(); s++)
		{
			word[s] = char((int)word[s] - DecryptionKey);
		}
		return word;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To) 
	{ 
		int randNum = rand() % (To - From + 1) + From; 
	    return randNum; 
	}
	enum enchartype { capitalLetter = 1, samallLetter = 2, spechaCahractar = 3, digit = 4 };
	static char getrandomcharactar(enchartype chartype)
	{
		switch (chartype)
		{
		case clsUtil::capitalLetter:
			return char(RandomNumber(65, 90));
		case clsUtil::samallLetter:
			return char(RandomNumber(97, 122));
		case clsUtil::spechaCahractar:
			return char(RandomNumber(33, 47));
		case clsUtil::digit:
			return char(RandomNumber(48, 57));
		default:
			break;
		}
	}
	static string genaretword(enchartype chartype)
	{
		string word;
		for (short i = 1; i < 5; i++)
		{
			word += getrandomcharactar(chartype);
		}
		return word;
	}
	static string genaretoneLineOfKey(enchartype chartype)
	{
		string key; 
		key = genaretword(chartype) + "-";
		key = key + genaretword(chartype) + "-";
		key = key + genaretword(chartype) + "-";
		key = key + genaretword(chartype);
		return key;
	}
	static void genaretkeys(short numbkeys)
	{

		for (short i = 1; i <= numbkeys; i++)
		{
			cout << "key[" << i << "]" << genaretoneLineOfKey(clsUtil::capitalLetter) << endl;
		}
	}
	static void genaretkeys(string array[], short numbkeys)
	{
		for (short i = 0; i < numbkeys; i++)
		{
			array[i] = genaretoneLineOfKey(clsUtil::capitalLetter);

			cout << "Array[" << i << "]" << array[i] << endl;
		}
	}
	static void fillarraywithelements(short array[], short numbelements)
	{
		for (short i = 0; i < numbelements; i++)
		{
			array[i] = ReadNumber();
		}
	}
	static short chickrepeatedelementsontarray(short array[],short length , short numbtochick)
	{
		short counter = 0; 
		for (short i = 0; i < length; i++)
		{
			(array[i] == numbtochick) ? counter++ : false;
		}
		return counter;
	}
	static void fillArraywithrandomnumbers(short array[100], short length)
	{
		for (short i = 0; i < length; i++)
		{
			array[i] = RandomNumber(1, 100);
		}
	}
	static short MaxNumbInArray(short array[], short length)
	{
		short Max; 
		Max = array[0];
		for (short i = 0; i < length; i++)
		{
			if (array[i] > Max)
			{
				Max = array[i];
			}
		}
		return Max;
	}
	static short MinmumNumbInArray(short array[], short length)
	{
		short Min = array[0];

		for (short i = 0; i < length; i++)
		{
			if (array[i] < Min)
			{
				Min = array[i];
			}
		}
		return Min;
	}
	static short sumelementsofarray(short array[], short length)
	{
		short sum = 0; 
		for (short i = 0; i < length; i++)
		{
			sum += array[i];
		}
		return sum;
	}
	static float ArrayAverage(short arr[100], short arrLength) 
	{ 
		return  (float) sumelementsofarray(arr, arrLength) / arrLength;
	}
	static void copyarray(short copyarrayp[], short orginalarray[], short arrLegth)
	{
		for (short i = 0; i < arrLegth; i++)
		{
			copyarrayp[i] = orginalarray[i];
		}
	}
	static void arraycopyOnlyPrimNumb(short copyarrayp[], short orginalarray[], short arrLegth , short &arracopylength)
	{
		short counter = 0;
		for (short i = 0; i < arrLegth; i++)
		{
			(chickNumber(orginalarray[i]) == numberstyptoget::prim) ?
				arracopylength++,copyarrayp[counter++] = orginalarray[i] : false;
		}
	}
	static void SwapNumbers(short& numb1, short& numb2)
	{
		short Temp = 0; 
		Temp = numb1; 
		numb1 = numb2;
		numb2 = Temp;
	}
	static void Shufflearray(short arra[], short lenght)
	{
		for (short i = 0; i < lenght; i++)
		{
			SwapNumbers(arra[RandomNumber(1, lenght) - 1], arra[RandomNumber(1, lenght) - 1]);
		}
	}
	static short findIndexOfNumbInarray(short array[], short length, short numbtochick)
	{
		short Index = -1;
		for (short i = 0; i < length; i++)
		{
			(array[i] == numbtochick) ? Index = i : false;
		}
		return Index;
	}
	static bool  IsNumbInArray(short array[], short length, short numbtochick)
	{
		return findIndexOfNumbInarray(array, length, numbtochick) != -1;

	}
	static void AddArrayElement(short numb, short arrar[], short& length)
	{
		length++;
		arrar[length -1 ] = numb;
	}
	static void CopyOddNumbers(short arrSource[100], short arrDestination[100], short arrLength, short& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
		if (arrSource[i] % 2 != 0)
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength); 
		} 
	}
	static void copydistinctnumbertoarra(short arrSource[100], short arrDestination[100], short arrLength, short& arrDestinationLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			if (!IsNumbInArray(arrDestination, arrDestinationLength, arrSource[i]))
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
		}
	}
	static void printarrayelemenrs(short arrSource[100], short arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			cout << arrSource[i] << " ";
		}
	}
	static bool Ispalindromarray(short arrSource[100], short arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			if (arrSource[i] != arrSource[arrLength - i - 1])
			{
				return false;
			};
		}
		return true;
	}
	static short countoddnumbInarray(short arrSource[100], short arrLength)
	{
		short counter = 0;
		for (short i = 0; i < arrLength; i++)
		{
			if (chickNumber(arrSource[i]) == numberstyptoget::notprim)
			{
				counter++;
			}
		}
		return counter;
	}
	static short countevennumbInarray(short arrSource[100], short arrLength)
	{
		short counter = 0;
		for (short i = 0; i < arrLength; i++)
		{
			if (chickNumber(arrSource[i]) == numberstyptoget::prim)
			{
				counter++;
			}
		}
		return counter;
	}
	static short countpositivenumberInarray(short arrSource[100], short arrLength)
	{
		short counter = 0;
		for (short i = 0; i < arrLength; i++)
		{
			if (arrSource[i] > 0)
			{
				counter++;
			}
		}
		return counter;
	}
	static short countnegativenumberInarray(short arrSource[100], short arrLength)
	{
		short counter = 0;
		for (short i = 0; i < arrLength; i++)
		{
			if (arrSource[i] < 0)
			{
				counter++;
			}
		}
		return counter;
	}
	static short myabs(short numb)
	{
		return (numb > 0) ? numb : numb * -1;
	}
	static float GetFractionPart(float Number) 
	{
		return Number - int(Number);
	}
	static short myround(float numb)
	{
		int IntPart;
		IntPart = int(numb);
		float Fraction = GetFractionPart(numb);
		if (myabs(Fraction) >= .5)
		{ 
			if (numb > 0) 
				return ++IntPart; 
			else 
				return --IntPart;
		}
		else 
		{ 
			return IntPart;
		}

	}
	static short myfloor(float numb)
	{
		return (numb > 0) ? short(numb) : short(numb) - 1;
	}
	static int MyCeil(float Number)
	{ 
		if (abs(GetFractionPart(Number)) > 0)
			if (Number > 0) 
				return int(Number) + 1;
		else 
				return int(Number);
		else 
			return Number;
	}
	static float MySqrt(float Number) 
	{ 
		return pow(Number, 0.5); 
	}


};

