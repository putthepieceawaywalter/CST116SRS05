// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

// Date range is 1/1/1901 to 12/31/2099

// ISO format is YYYY-MM-DD

// assert if the date is outside the expected range

int main() {
	
	int year;
	int year1;
	int month;
	int month1;
	int day;
	int day1;

	// create an if assert if true run program if false assert
	std::cin >> year;
	std::cin.ignore();
	std::cin >> month;
	std::cin.ignore();
	std::cin >> day;

	std::cin >> year1;
	std::cin.ignore();
	std::cin >> month1;
	std::cin.ignore();
	std::cin >> day1;
	
	if (year < 1900 || year1 < 1900 ||year > 2099 || year1 > 2099 || month < 0 || month1 < 0 || month > 12 || month1 > 12 || day < 1 || day1 < 1) {
		std::cout << "You have entered invalid data please start the program again" << std::endl;
		return 0;
	}
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30) {
			std::cout << "You have entered invalid data please start the program again" << std::endl;
			return 0;
		}
	case 2:
		if (day > 29 && year % 4 != 0) {
			std::cout << "You have entered invalid data please start the program again" << std::endl;
			return 0;
		}
		if (day > 30 && year % 4 == 0) {
			std::cout << "You have entered invalid data please start the program again" << std::endl;
			return 0;
		}
	default:
		if (day > 31) {
			std::cout << "You have entered invalid data please start the program again" << std::endl;
			return 0;
		}

	}

	// 13578 10 12 this will stop the program if you enter an incorrect amount of days for the given month (ex. jan 32)


	if (year > year1) {
		int a = year1;
		year1 = year;
		year = a;
	}

	if (year == year1 && month > month1) {
		int a = month1;
		month1 = month;
		month = a;
	}
	if (year == year1 && month == month1 && day > day1) {
		int a = day1;
		day1 = day;
		day = a;
	}
	// 1976-06-21 2001-06-21
	// 1976-13-31 1976-4-15

	while (year <= year1) {
		while (month <= 12) {
			//months with 31 days
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				while (day < 32) {
					if (day == day1 && month == month1 && year == year1) {
						return 0;
					}
					std::cout <<  year << "-" << std::setfill('0') << std::setw(2) << month <<  "-" << std::setfill('0') << std::setw(2) << day << '\n';
					day++;
				}
				day = 1;
				month++;
			}
			// months with 30 days
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				while (day < 31) {

					if (day == day1 && month == month1 && year == year1) {
						return 0;
					}
					std::cout << year << "-" << std::setfill ('0') << std::setw(2) << month << "-" << std::setfill ('0') << std::setw(2) << day << '\n';
					day++;
				}
				day = 1;
				month++;
			}
			// 28 day February
			if (month == 2 && year % 4 != 0) {
				while (day < 29) {
					if (day == day1 && month == month1 && year == year1) {
						return 0;
					}
					std::cout << year << "-" << std::setfill ('0') << std::setw(2) << month << "-" << std::setfill ('0') << std::setw(2) << day << '\n';
					day++;
				}
				day = 1;
				month++;
			}
			// Leap year February
			if (month == 2 && year % 4 == 0) {
				while (day < 30) {
					if (day == day1 && month == month1 && year == year1) {
						return 0;
					}
					std::cout << year << "-" << std::setfill ('0') << std::setw(2) << month << "-" << std::setfill ('0') << std::setw(2) << day << '\n';
					day++;
				}
				day = 1;
				month++;
			}
		}
		month = 1;
		year++;
	}
	return 0;
}