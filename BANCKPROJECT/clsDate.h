#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"
using namespace std;

class clsDate 
{
  private:

	static short  _DayOrderOnWeek(short day, short month, short year)
	{
		short a, y, m ,d ;
		a = ((14 - month) / 12);
		y = year - a;
		m = (month + 12 * a) - 2; 
		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	static string _MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", 
			"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return Months[MonthNumber - 1];
	}
	static enum  _enCompertDate { Befor = -1,Equal = 0, After = 1};
	short _Year;
	short _Month;
	short _Day;

  public: 

	 clsDate(string S1)
	 {
		 vector<string> vstring; 
		 vstring = clsString::Spilt_str_to_Vector(S1, "/");

		 _Day = stoi(vstring.at(0));
		 _Month = stoi(vstring.at(1));
		 _Year = stoi(vstring.at(2));


	 }
     clsDate(short Day, short Month, short Year)
	 {
		 _Year  = Year; 
		 _Month = Month; 
		 _Day   = Day;

	 }
	  void GetSystemDate()
	  {
		 time_t t = time(0);
		 tm* now = localtime(&t);
		 _Year = now->tm_year + 1900;
		 _Month = now->tm_mon + 1;
		 _Day = now->tm_mday;

	  };

	 clsDate()
	 {

		void GetSystemDate();
		{
			time_t t = time(0);
			tm* now = localtime(&t);
			_Year = now->tm_year + 1900;
			_Month = now->tm_mon + 1;
			_Day = now->tm_mday;
			
		};

	};

	void setYear(short Year)
	{
		_Year = Year; 
	}
	short Year()
	{
		return _Year; 
	}
	void setMonth(short Month)
	{
		_Month = Month;
	}
	short Month()
	{
		return _Month; 
	}
	void setDay(short Day)
	{
		_Day = Day; 
	}
	short Day()
	{
		return _Day;
	}



	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0 ) || ( Year % 4 == 0 && Year % 100 != 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}
	static short NumebrOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumebrOfDaysInYear()
	{
		return NumebrOfDaysInYear(_Year);
	}
	static short NumberOfHoursInYear(short Year)
	{
		return NumebrOfDaysInYear(Year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumebrOfDaysInYear(_Year) * 24;
	}
	static int NumebrOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60; 
	}
	int NumebrOfMinutesInYear()
	{
		return NumberOfHoursInYear(_Year) * 60;
	}
	static int NumebrOfSecondsInYear(short Year)
	{
		return NumebrOfMinutesInYear(Year) * 60;
	}
	int NumebrOfSecondsInYear()
	{
		return NumebrOfSecondsInYear(_Year);
	}
	static short NumebrOfDaysInMonth(short Year, short Month)
	{


		short arrayofmonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if(Month >= 1 && Month <= 12)
		return (IsLeapYear(Year) && Month == 2) ? 29 : arrayofmonth[Month - 1];


	}
	short NumebrOfDaysInMonth()
	{
		return NumebrOfDaysInMonth(_Year, _Month);
	}
	static int NumebrOfHoursInMonth(short Year, short Month)
	{
		return NumebrOfDaysInMonth(Year, Month) * 24;
	}
	int NumebrOfHoursInMonth()
	{
		return NumebrOfHoursInMonth(_Year, _Month);
	}
	static int NumberOfMinutesInMonth(short Year, short Month)
	{
		return NumebrOfHoursInMonth(Year, Month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Day);
	}
	static int NumberOfSecondsInMonth(short Year, short Month)
	{
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return  NumberOfSecondsInMonth(_Year, _Month);
	}
	static string daynameonweek(short Day, short Month, short Year)
	{
		short  DayOredr = _DayOrderOnWeek(Day, Month, Year);
		string arraydaynameofweek[7] = { "Sun","Mon","Tus","Wen","Thrs","Fri","Sat" };
		return arraydaynameofweek[DayOredr];
	}
	string daynameonweek()
	{
		return daynameonweek(_Day ,_Month , _Year);
	}
	static void PrintMonthCalendar(short Month ,short Year)
	{
		short IndexDay = _DayOrderOnWeek(1, Month, Year);
		short NumberOfDayInmonth = NumebrOfDaysInMonth(Year, Month);


		printf("\n_____________%s___________________\n\n", _MonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		short i; 
		for(i=0 ; i < IndexDay ; i++)
			printf("    ");
		for (int j = 1; j <= NumberOfDayInmonth; j++)
		{
			printf("%5d", j); 

			if (++i == 7) 
			{    
			  i = 0;    
			  printf("\n");
			}
		}
		printf("\n  _________________________________\n");

	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}
    static void PrintYearCalendar(int Year)
	{ 
		printf("\n  _________________________________\n\n");   
		printf("           Calendar - %d\n", Year);    
		printf("  _________________________________\n");
		for (int i = 1; i <= 12; i++)
		{ 
			PrintMonthCalendar(i, Year);
		} 
		return; 
	}
	void PrintYearCalendar()
	{
		 PrintYearCalendar(_Year);
	}
	static short NumberOfDaysFromBeggingOfYear(short Day, short Month, short Year)
	{
		short NumberOfDays = 0; 
		for (short i = 1; i < Month; i++)
		{
			NumberOfDays += NumebrOfDaysInMonth(Year, i);
		}
		NumberOfDays += Day; 
		return NumberOfDays; 
	}
	short NumberOfDaysFromBeggingOfYear()
	{
		return NumberOfDaysFromBeggingOfYear(_Day, _Month, _Year);
	}
	static bool IsLastDayOnMonth( short Day , short Month , short Year)
	{
		return (Day == NumebrOfDaysInMonth(Year,Month));
	}
	bool IsLastDayOnMonth()
	{
		return  IsLastDayOnMonth(this->_Day , this->_Month,this->_Year);
	}
	static bool IsLastMonthOnYear(short Month)
	{
		return (Month == 12);
	}
	bool  IsLastMonthOnYear()
	{
		return IsLastMonthOnYear(this->_Month);
	}
	static void IncreaseDateByOneday(short &Day , short &Month , short &Year)
	{ 


		if (IsLastDayOnMonth(Day, Month, Year))
		{
			IsLastMonthOnYear(Month) ? Month = 1, Year++ : Month++ , Day = 1;
		}
		else
		{
			Day++;
		}

	}
	static void IncreaseDateByXDays(short XDays ,short Day, short Month , short Year)
	{
		for (short i = 0; i < XDays; i++)
		{
			IncreaseDateByOneday(Day,Month,Year);
		}
	}
	void IncreaseDateByXDays(short XDays)
	{
		for (short i = 0; i < XDays; i++)
		{
			IncreaseDateByOneday(*this);
		}
	}
	static void IncreaseDateByOneday(clsDate& Date)
	{


		if (IsLastDayOnMonth(Date._Day, Date._Month, Date._Year))
		{
			IsLastMonthOnYear(Date._Month) ? Date._Month = 1, Date._Year++ : Date._Month++, Date._Day = 1;
		}
		else
		{
			Date._Day++;
		}

	}
	void IncreaseDateByOneMonth()
	{
		if (IsLastMonthOnYear())
		{
			_Month = 1; 
			_Year++; 

		}
		else
		{
			_Month++; 
		}
		short CurrnetNumebrOfDaysOnMonth = NumebrOfDaysInMonth(); 

		if (_Day > CurrnetNumebrOfDaysOnMonth)
		{
			_Day = CurrnetNumebrOfDaysOnMonth;

		}
	}
	void IncreaseDateByXMonth(short XMonth)
	{
		for (short i = 0; i < XMonth; i++)
		{
			IncreaseDateByOneMonth();
		}
	}
	void IncreaseDateByOneWeek()
	{
		for (short i = 1; i <= 7; i++)
		{
			IncreaseDateByOneday(*this); 
		}
	}
	void IncreaseDateByXWeeks(short XWeeks)
	{
		for (short i = 0; i < XWeeks; i++)
		{
			IncreaseDateByOneWeek();
		}
	}
	void IncreaseDateByOneYear()
	{
		_Year++; 

	}
	void IncreaseDateByXYears(short XYears)
	{
		_Year += XYears;
	}
	void IncreaseDateByOneDecade()
	{
		//Period of 10 
		_Year += 10;
	}
	void IncreaseDateByXDecadesFaster(short XDecade) 
	{ 
		_Year += XDecade * 10; 

	}
	void IncreaseDateByOneCentury()
	{ 
		//Period of 100
	  _Year += 100; 

	} 
	void IncreaseDateByOneMillennium() 
	{ 
		//Period of 1000 
		_Year += 1000;
	}

	void DecreaseDateByOneDay()
	{
		if (_Day == 1)
		{
			if (_Month == 1)
			{
				_Month = 12; 
				_Day = 31; 
				_Year--; 
			}
			else
			{
				_Month--; 
				_Day = NumebrOfDaysInMonth(_Year, _Month);
			}
		}
		else
		{
			_Day--; 
		}
	}
	void DecreaseDateByXDays(short Xdays)
	{
		for (short i = 0; i < Xdays; i++)
		{
			DecreaseDateByOneDay();
		}
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByXDays(7);
	}
	void DecreaseDateByXWeeks(short XWeeks)
	{
		for (short i = 0; i < XWeeks ; i++)
		{
			DecreaseDateByOneWeek();
		}
	}
	void DecreaseDateByOneMonth()
	{
		
		if (_Month == 1 )
		{
			_Month = 12; 
			_Year--; 
		}
		else
		{
			_Month--;
		}
		short NumberOfdaysOnMonth = 0; 
		NumberOfdaysOnMonth = NumebrOfDaysInMonth(_Year, _Month);
		if (_Day > NumberOfdaysOnMonth)
		{
			_Day = NumberOfdaysOnMonth; 
		}
	}
	void DecreaseDateByXMonth(short XMonth)
	{
		for (short i = 0; i < XMonth; i++)
		{
			DecreaseDateByOneMonth();
		}
	}
	void DecreaseDateBYOneYear()
	{
		_Year--; 

	}
	void DecreaseDateByXYears(short Years)
	{
		_Year -= Years; 
	}
	void DecreaseDateByOneDecade()
	{
		_Year -= 10; 
	}
	void DcreaseDateByXDecade(short XDecade)
	{
		_Year -= XDecade;
	}
	void DcreaseDateByOneCentury()
	{
		_Year -= 100;
	}
	void DecreasedDateByOneMillennium()
	{
		_Year -= 1000;
	}

	static bool IsWeekEnd(short &Day, short &Month, short &Year)
	{
		string DaysOrderOnWeek = " ";
		DaysOrderOnWeek = daynameonweek(Day, Month, Year);
		return (DaysOrderOnWeek == "Fri" || DaysOrderOnWeek == "Sat");
	}
	bool IsWeekEnd()
	{
		string DayOrderOnWeekIndex = daynameonweek();
		return (DayOrderOnWeekIndex == "Fri" || DayOrderOnWeekIndex == "Sat");
	}
	bool IsBussniseDay()
	{
		return (!IsWeekEnd());
	}
	short DaysUntillTheEndOfWeek()
	{
		short CountDaysUntillWeekEnd = 0; 
		while (!IsWeekEnd())
		{
			CountDaysUntillWeekEnd++;
			IncreaseDateByOneday(*this);
		}
		return CountDaysUntillWeekEnd;
	}
	short DaysUntillTheEndOfMonth()
	{
		short CurrentMonth = NumebrOfDaysInMonth(_Year, _Month); 
		short Counter = 0; 

		while (_Day != CurrentMonth)
		{
			Counter++; 
			IncreaseDateByOneday(*this);
		}
		return Counter;
	}
    short DaysUntillTheEndOfYear()
	{
		clsDate Date1; 
		Date1._Day = 31; 
		Date1._Month = 12; 
		return CalculateDiffernceInDays(Date1 , *this);
	}
	short VecationPeriod(clsDate Date)
	{
		short CounterDays = 0;
		while (IsDate1BeforeDate2(*this , Date))
		{
			if (IsBussniseDay())
			{
				CounterDays++;
			}
			IncreaseDateByOneday(*this);
		}
		return CounterDays;
	}

	static void AddMoreDaysToDate(short DaysToAdd , clsDate& Date)
	{
		short Remainder = DaysToAdd + NumberOfDaysFromBeggingOfYear(Date._Day, Date._Month, Date._Year);
		Date._Month = 1; 
		short NumberOfDaysOnMonth = 0;  

		while (true)
		{
			NumberOfDaysOnMonth = NumebrOfDaysInMonth(Date._Year, Date._Month);
			if (Remainder > NumberOfDaysOnMonth)
			{
				Remainder -= NumberOfDaysOnMonth; 
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Month++;
				}
			}
			else
			{
		     Date._Day = Remainder;
			 break;

			}
		}

	}
	void AddMoreDaysToDate(short DaysToAdd)
	{
		AddMoreDaysToDate(DaysToAdd,*this);
	}
    void CaculateVecationPeriod( short VecationDays)
	 {
		 short WeekendDays =0 ;
		
			while (IsWeekEnd())
			{
				IncreaseDateByOneday(*this);
				 
			}
			for (short i = 0; i < VecationDays + WeekendDays; i++)
			{
				if (IsWeekEnd())
				{
					WeekendDays++;

				}
				IncreaseDateByOneday(*this);

		    }
			while (IsWeekEnd())
			{
				IncreaseDateByOneday(*this);
			}
	 }
	static clsDate CaculateVecationPeriod(short Day, short Month, short Year, short VecationStarDays)
	{
		short WeekendDays = 0;
		clsDate Date; 


		while (IsWeekEnd(Day, Month, Year))
		{
			IncreaseDateByOneday(Day, Month, Year);
		}
		for (short i = 0; i <= VecationStarDays + WeekendDays; i++)
		{
			if (IsWeekEnd(Day, Month, Year))
			{
				WeekendDays++;
			}
			IncreaseDateByOneday(Day, Month, Year);
		}
		while (IsWeekEnd(Day, Month, Year))
		{
			IncreaseDateByOneday(Day, Month, Year);
		}

		Date._Day = Day; Date._Month = Month;  Date._Year = Year;

		return Date; 
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) 
	{ 
		return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}
	static void  SwapDates(clsDate & Date1, clsDate& Date2) 
	{
		clsDate TempDate;  
		TempDate = Date1; 
		Date1 = Date2; 
		Date2 = TempDate;
	}
	static short CalculateDiffernceInDays(clsDate Date1, clsDate Date2)
	{
		short CounterDiffrenceDays = 0; 
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			CounterDiffrenceDays++; 
			IncreaseDateByOneday(Date1._Day,Date1._Month,Date1._Year);
		}
		return CounterDiffrenceDays;
	}
	short CalculateDiffernceInDays(clsDate Date2)
	{
		return CalculateDiffernceInDays(*this, Date2);
	}
	short BrithDayDateToDays(clsDate BrithDaysDate)
	{
		return CalculateDiffernceInDays(*this , BrithDaysDate);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return(!IsDate1BeforeDate2(*this, Date2) && !IsDate1EqualDate2(*this, Date2));
	}
	static _enCompertDate CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return _enCompertDate::Befor; 
		}
		if (IsDate1AfterDate2(Date1, Date2))
		{
			return _enCompertDate::After; 
		}
		   return _enCompertDate::Equal; 
	}
	short CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}
	static bool IsOverLapPeriod(clsDate Pr1StartDate, clsDate Pr1EndDate, clsDate Pr2StartDate, clsDate Pr2EndDate)
	{
		return (CompareDates(Pr2EndDate, Pr1StartDate) == -1 || CompareDates(Pr2StartDate, Pr1EndDate) == 0);
	}
	static short PeriodLengthInDays(clsDate Date1 , clsDate Date2)
	{
		return CalculateDiffernceInDays(Date1, Date2);
	}
	short PeriodLengthInDays(clsDate Date2)
	{
		return PeriodLengthInDays(*this, Date2);
	}
	static bool IsDateInPeriod(clsDate StartDate, clsDate EndDate, clsDate Date)
	{

		return ( ( CompareDates(Date, StartDate) == _enCompertDate::Befor ) || ( CompareDates(Date, EndDate) == _enCompertDate::After) );
	}
	static short CountOverlapDays(clsDate Pr1StartDate, clsDate Pr1EndDate, clsDate Pr2StartDate, clsDate Pr2EndDate)
	{
		short Period1Length = PeriodLengthInDays(Pr1StartDate, Pr1EndDate);
		short Period2Length = PeriodLengthInDays(Pr2StartDate, Pr2EndDate);
		short OverLapDays = 0; 
		if (!IsOverLapPeriod(Pr1StartDate, Pr1EndDate, Pr2StartDate, Pr2EndDate))
			return 0;
		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Pr1StartDate, Pr1EndDate))
			{
				if (IsDateInPeriod(Pr1StartDate, Pr1StartDate, Pr2StartDate))
					OverLapDays++;
				IncreaseDateByOneday(Pr1StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Pr2StartDate, Pr2EndDate))
			{
				if (IsDateInPeriod(Pr2StartDate, Pr2StartDate, Pr1StartDate))
					OverLapDays++;
				IncreaseDateByOneday(Pr2StartDate);
			}
		}
		return OverLapDays;


	}
	static bool IsValidDate(short Day , short Month , short Year)
	{
		return(Day >= 1 && Day <= NumebrOfDaysInMonth(Year, Month) && Month >= 1 && Month <= 12);

	}
	static bool IsValidDate(clsDate Date )
	{
		return  IsValidDate(Date._Day, Date._Month, Date._Year);
	}
	bool IsValidDate()
	{
		return IsValidDate(this->_Day, this->_Month, this->_Year);
	}

	static string DateToString(short Day, short Month, short Year)
	{
		string DateToString = " "; 
		DateToString = to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
		return DateToString; 
	}
	static clsDate stringToDate(string Datestring)
	{
		vector<string> vstring;
		clsDate clsdate; 
		vstring = clsString::Spilt_str_to_Vector(Datestring, "/");

		clsdate._Day = stoi(vstring.at(0));
		clsdate._Month = stoi(vstring.at(1));
		clsdate._Year = stoi(vstring.at(2));
		return clsdate; 
	}
	void StringToDate(string Datestring)
	{

		vector<string> vstring;
		vstring = clsString::Spilt_str_to_Vector(Datestring, "/");

		this->_Day = stoi(vstring.at(0));
		this->_Month = stoi(vstring.at(1));
		this->_Year = stoi(vstring.at(2));

	}
	string DateToString()
	{
		if (IsValidDate())
		return  DateToString(this->_Day, this->_Month, this->_Year);
		return "Invalied Date !!";
	}
	static string FormatDate(short Day, short Month, short Year , string FormatType = "dd/mm/yy")
	{
		string DateFormat = " "; 
		DateFormat = clsString::Replace_string(FormatType, "dd", to_string(Day));
		DateFormat = clsString::Replace_string(DateFormat, "mm", to_string(Month));
		DateFormat = clsString::Replace_string(DateFormat, "yy", to_string(Year));
		return DateFormat; 
	}
	string FormatDate(string FormatType)
	{
		return FormatDate(this->_Day, this->_Month, this->_Year,FormatType);
	}
	string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		return  to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	}

    void Print()
	{
		cout << DateToString() << endl;
	}


};

