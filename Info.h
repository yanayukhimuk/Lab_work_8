#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>
#include <vector>
#include <filesystem>

struct PersonalData {
	std::string Name;
	std::string Surname; 
	std::string Patronymic;
};

struct DateOfBirth {
	int day;
	int month;
	int year;
};

class Data {
protected: 
	PersonalData personal_data;
	DateOfBirth date_of_birth;
	std::string gender;

public:
	Data();
	Data(PersonalData personal_data, DateOfBirth date_of_birth, std::string gender);

	PersonalData getPersonalData(){
		return personal_data;
	}
	DateOfBirth getDateOfBirth(){
		return date_of_birth;
	}
	std::string getgender() {
		return gender;
	}

	friend std::ostream& operator << (std::ostream& os, const Data d);
	Data& operator=(Data d);
};
