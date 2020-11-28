#include "Func.h"
#include"Info.h"
using namespace std; 

//void OpenFile() {
//	string path = "LABA.txt";
//	ifstream fin;
//	fin.open(path);
//	if (!fin.is_open())
//		cout << "Ошибка открытия файла!" << endl;
//	else
//		cout << "Файл открыт!" << endl;
//}

void dataLoad(std::vector<Data>& people, const std::string fileName) {
	people.clear();
	std::ifstream fin(fileName);

	if (fin) {
		PersonalData personal_data; 
		DateOfBirth date_of_birth; 
		std::string gender; 

		std::string r; 
		while (!fin.eof()) {
			fin >> r;
			fin >> personal_data.Surname >> personal_data.Name >> personal_data.Patronymic;

			fin >> r; 
			fin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;

			fin >> r; 
			fin >> gender;
			people.push_back(Data(personal_data, date_of_birth, gender));
		}

		std::cout << "Файл окрыт: " << std::endl; 
	}
	else {
		std::cout << "Не удалось открыть файл!" << fileName << std::endl; 
	}
	fin.close(); 
}

void dataInput(std::vector<Data>& people) {
	if (people.size() != 0) {
		std::cout << "**************************************" << std::endl;
		for (const auto& person : people) {
			std::cout << person; 
		}
		std::cout << std::endl; 
	}
	else {
		std::cout << "Не удалось ввести данные!" << std::endl; 
	}
}

void dataAppend(std::vector<Data>& people, const std::string fileName) {
	std::ofstream fout(fileName, std::ios_base::app);

	PersonalData personal_data; 
	DateOfBirth date_of_birth; 
	std::string gender; 

	std::string a = "-1"; 
	while (a != "0") {
		std::cout << "ФИО: ";
		std::cin >> personal_data.Surname >> personal_data.Name >> personal_data.Patronymic;
		std::cout << "Дата рождения: ";
		std::cin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;
		std::cout << "Пол: ";
		std::cin >> gender; 
		people.push_back(Data(personal_data, date_of_birth, gender));

		std::cout << endl;
		std::cout << endl;
		std::cout << "Введите 0, чтобы закончить ввод данных.";
		std::cin >> a; 
	}

	for (const auto& person : people) {
		fout << person; 
	}

	fout.close();
}

void dataSortSurname(std::vector<Data>& people) {
	if (people.size() > 0) {
		for (int i = 0; i < people.size() - 1; ++i) {
			for (int j = i + 1; j < people.size(); ++j) {
				std::string SurnamePersonOne = people[i].getPersonalData().Surname;
				std::string SurnamePersonTwo = people[i].getPersonalData().Surname;
				if (SurnamePersonTwo < SurnamePersonOne) {
					Data temp = people[i];
					people[i] = people[j];
					people[j] = temp; 
				}
			}
		}
		std::cout << "...." << std::endl;
	}
	else {
		std::cout << "....." << std::endl; 
	}
}
void dataSortAge(std::vector<Data>& people) {
	auto swap = [&people](const int i, const int j) {
		Data temp = people[i];
		people[i] = people[j];
		people[j] = temp;
	};
	if (people.size() > 0) {
		for (int i = 0; i < people.size() - 1; ++i) {
			for (int j = i + 1; j < people.size(); ++j) {
				DateOfBirth date_of_b_first = people[i].getDateOfBirth();
				DateOfBirth date_of_b_second = people[j].getDateOfBirth();
				if (date_of_b_first.year != date_of_b_second.year) {
					if (date_of_b_first.year > date_of_b_second.year) {
						swap(i, j);
					}
				}
				else if (date_of_b_first.month != date_of_b_second.month) {
					if (date_of_b_first.month > date_of_b_second.month) {
						swap(i, j);
					}
				}
				else if (date_of_b_first.day > date_of_b_second.day) {
					swap(i, j);
				}
			}
		}
		std::cout << "Самый старший сотрудник : " << std::endl;
	}
	else {
		std::cout << "Младший: " << std::endl; 
	}
}

void PeopleMonth(std::vector<Data>& people, const int givenMonth) {
	bool suchPersonHas = false;
	for (int i = 0; i < people.size(); ++i) {
		if (people[i].getDateOfBirth().month == givenMonth) {
			suchPersonHas = true;
			std::cout << people[i] << std::endl;
		}
	}

	if (!suchPersonHas) {
		std::cout << "Такого сотрудника нет" << std::endl;
	}
}

void TheOldest(std::vector<Data>& people) {
	auto getFirstManPerson = [&people]() mutable -> Data {
		for (int i = 0; i < people.size(); ++i) {
			if (people[i].getgender() == "man") {
				return people[i];
			}
		}
		Data people;
		return people;
	};
	Data man = getFirstManPerson();

	auto manExistsAtDataBase = [&man]() mutable -> bool {
		return man.getgender() == "man";
	};

	if (manExistsAtDataBase()) {
		for (int i = 1; i < people.size(); ++i) {
			DateOfBirth dateOfSecondPerson = people[i].getDateOfBirth();
			if (man.getDateOfBirth().year > dateOfSecondPerson.year && people[i].getgender() == "man") {
				man = people[i];
			}
			else if (man.getDateOfBirth().month > dateOfSecondPerson.month && people[i].getgender() == "man") {
				man = people[i];
			}
			else if (man.getDateOfBirth().day > dateOfSecondPerson.day && people[i].getgender() == "man") {
				man = people[i];
			}
		}
		std::cout << man << std::endl;

	}
	else {
		std::cout << "Такого сотрудника нет" << std::endl;
	}
}

void SameLetter(std::vector<Data>& people, char firstLetterOfLastsNames) {
	bool suchPersonsExists = false;
	for (int i = 0; i < people.size(); ++i) {
		if (people[i].getPersonalData().Surname[0] == firstLetterOfLastsNames) {
			suchPersonsExists = true;
			std::cout << people[i] << std::endl;
		}
	}

	if (!suchPersonsExists) {
		std::cout << "Таких сотрудников нет" << std::endl;
	}
}