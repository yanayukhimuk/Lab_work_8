#include "Info.h"
#include "Func.h"
#include <vector>

Data::Data() {
	personal_data.Name = "";
	personal_data.Surname = "";
	personal_data.Patronymic = "";

	date_of_birth.day = -1;
	date_of_birth.month = -1;
	date_of_birth.year = -1;

	gender = "";
}

Data::Data(PersonalData personal_data, DateOfBirth date_of_birth, std::string gender) {
	this->personal_data.Name = personal_data.Name;
	this->personal_data.Surname = personal_data.Surname;
	this->personal_data.Patronymic = personal_data.Patronymic;

	this->date_of_birth.day = date_of_birth.day;
	this->date_of_birth.month = date_of_birth.month;
	this->date_of_birth.year = date_of_birth.year;

	this->gender = gender;
}

std::ostream& operator<<(std::ostream& os, const Data d) {
	os << std::endl;
	os << "ФИО: " << d.personal_data.Surname << " " << d.personal_data.Name << " " << d.personal_data.Patronymic << std::endl;
	os << "Дата рождения: " << d.date_of_birth.day << " " << d.date_of_birth.month << " " << d.date_of_birth.year << std::endl;
	os << "Пол: " << d.gender;
	return os;
}

Data& Data::operator=(Data d) {
	this->personal_data.Name = personal_data.Name;
	this->personal_data.Surname = personal_data.Surname;
	this->personal_data.Patronymic = personal_data.Patronymic;

	this->date_of_birth.day = date_of_birth.day;
	this->date_of_birth.month = date_of_birth.month;
	this->date_of_birth.year = date_of_birth.year;

	this->gender = gender;
	return *this;
}