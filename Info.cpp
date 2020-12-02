#include "Info.h"
#include "Func.h"
#include <vector>

Data::Data() {
	personal_data.Name = "";
	personal_data.Surname = "";
	personal_data.Patronymic = "";

	date_of_birth.day = 1;
	date_of_birth.month = 1;
	date_of_birth.year = 1970;

	gender = "";
}

Data::Data(PersonalData personal_data, DateOfBirth date_of_birth, string gender) {
	this->personal_data.Name = personal_data.Name;
	this->personal_data.Surname = personal_data.Surname;
	this->personal_data.Patronymic = personal_data.Patronymic;

	this->date_of_birth.day = date_of_birth.day;
	this->date_of_birth.month = date_of_birth.month;
	this->date_of_birth.year = date_of_birth.year;

	this->gender = gender;
}

ostream& operator<<(ostream& os, const Data d) {
	os << "ФИО: " << d.personal_data.Surname << " " << d.personal_data.Name << " " << d.personal_data.Patronymic
		<< "\nДата рождения: " << d.date_of_birth.day << " " << d.date_of_birth.month << " " << d.date_of_birth.year
		<< "\nПол: " << d.gender;
	return os;
}
bool operator < (const DateOfBirth d1, const DateOfBirth d2) {
	return d1.year < d2.year ? true : d1.year > d2.year ? false : d1.month < d2.month ? true : d1.month > d2.month ? false : d1.day < d2.day;
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