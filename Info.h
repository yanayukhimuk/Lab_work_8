#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>
#include <vector>
#include <filesystem>
using namespace std;
struct PersonalData {
	string Name;
	string Surname;
	string Patronymic;
};

struct DateOfBirth {
	int day;
	int month;
	int year;
	friend bool operator < (const DateOfBirth d1, const DateOfBirth d2);
};

class Data {
	PersonalData personal_data;
	DateOfBirth date_of_birth;
	string gender;
public:
	Data();
	Data(PersonalData personal_data, DateOfBirth date_of_birth, string gender);

	PersonalData getPersonalData() {
		return personal_data;
	}
	DateOfBirth getDateOfBirth() {
		return date_of_birth;
	}
	string getgender() {
		return gender;
	}

	friend ostream& operator << (ostream& os, const Data d);
	Data& operator=(Data d);
};
