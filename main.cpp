// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>
int main() {
	int year;
	int year1;
	int month;
	int month1;
	int day;
	int day1;

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
	if (year > year1 || year == year1 && month > month1 || year == year1 && month == month1 && day > day1) {
		int a = year1;
		year1 = year;
		year = a;
		int b = month1;
		month1 = month;
		month = b;
		int c = day1;
		day1 = day;
		day = c;
	}
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 30) {
			break;
		}
	case 2:
		if (day < 29 && year % 4 != 0) {
			break;
		}
		if (day < 30 && year % 4 == 0) {
			break;
		}
	default:
		if (day < 31) {
			break;
		}
		std::cout << "You have entered invalid data, please start the program again" << std::endl;
		return 0;
	}
	while (year <= year1) {
		while (month <= 12) {
			int dayCounter;
			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dayCounter = 32;
				break;
			case 2:
				if (year % 4 == 0) {
					dayCounter = 30;
					break;
				}
				else {
					dayCounter = 29;
					break;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				dayCounter = 31;
			}
			while (day < dayCounter) {
				if (day == day1 && month == month1 && year == year1) {
					return 0;
				}
				std::cout << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setfill('0') << std::setw(2) << day << '\n';
				day++;
			}
			day = 1;
			month++;
		}
		month = 1;
		year++;
	}
	return 0;
}