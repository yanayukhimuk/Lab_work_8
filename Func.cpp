#include "Func.h"
#include "Info.h"

void dataLoad(vector<Data>& people, const string fileName) {
	people.clear();
	ifstream fin(fileName);

	if (!fin) {
		cout << "Не удалось открыть файл!" << fileName << endl;
		return;
	}
	PersonalData personal_data;
	DateOfBirth date_of_birth;
	string gender;

	string r;
	while (!fin.eof()) {
		fin >> r;
		fin >> personal_data.Surname >> personal_data.Name >> personal_data.Patronymic;

		fin >> r;
		fin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;

		fin >> r;
		fin >> gender;
		people.push_back(Data(personal_data, date_of_birth, gender));
	}
	cout << "Успешно считано:\n";
	fin.close();
}

void dataOutput(vector<Data>& people) {
	if (people.size() == 0) {
		cout << "Не удалось ввести данные!" << endl;
		return;
	}
	for (const auto& person : people)
		cout << person;
	cout << endl;
	char ch;
	cin >> ch;
}

void dataAppend(vector<Data>& people, const string fileName) {
	ofstream fout(fileName, ios_base::app);
	PersonalData personal_data;
	DateOfBirth date_of_birth;
	string gender;

	string a = "-1";
	while (a != "0") {
		cout << "ФИО(через пробел):\n> ";
		cin >> personal_data.Surname >> personal_data.Name >> personal_data.Patronymic;
		cout << "Дата рождения(ДД ММ ГГГГ):\n> ";
		cin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;
		cout << "Пол(м/ж):\n>";
		cin >> gender;
		people.push_back(Data(personal_data, date_of_birth, gender));
		cout << "\n\nВведите 0, чтобы закончить ввод данных\n> ";
		cin >> a;
	}
	for (const auto& person : people)
		fout << person;
	fout.close();
}

void sortDataBySurname(vector<Data>& people) {
	if (people.size() <= 0) {
		cout << "Ошибка\n";
		return;
	}
	for (int i = 0; i < people.size() - 1; i++, cout << "....\n")
		for (int j = i + 1; j < people.size(); j++)
			if (people[i].getPersonalData().Surname < people[j].getPersonalData().Surname)
				swap(people[i], people[j]);
}
void sortDataByAge(vector<Data>& people) {
	if (people.size() <= 0) {
		cout << "Ошибка\n";
		return;
	}
	for (int i = 0; i < people.size() - 1; ++i)
		for (int j = i + 1; j < people.size(); ++j)
			if (people[i].getDateOfBirth() < people[j].getDateOfBirth())
				swap(people[i], people[j]);
	cout << "Самый старший сотрудник : " << endl;
}

void printPeopleWithBirthMonth(vector<Data>& people, const int givenMonth) {
	bool suchPersonHas = false;
	for (int i = 0; i < people.size(); ++i)
		if (people[i].getDateOfBirth().month == givenMonth) {
			suchPersonHas = true;
			cout << people[i] << endl;
		}
	if (!suchPersonHas)
		cout << "Такого сотрудника нет" << endl;
}

void printOldestOf(vector<Data>& people) {
	auto getFirstManPerson = [&people]() mutable -> Data {
		for (int i = 0; i < people.size(); ++i)
			if (people[i].getgender() == "man")
				return people[i];
		Data people;
		return people;
	};
	Data man = getFirstManPerson();

	auto manExistsAtDataBase = [&man]() mutable -> bool {
		return man.getgender() == "man";
	};

	if (!manExistsAtDataBase()) {
		cout << "Такого сотрудника нет" << endl;
		return;
	}

	for (int i = 1; i < people.size(); ++i) {
		DateOfBirth dateOfSecondPerson = people[i].getDateOfBirth();
		if (man.getDateOfBirth().year > dateOfSecondPerson.year && people[i].getgender() == "man")
			man = people[i];
		else if (man.getDateOfBirth().month > dateOfSecondPerson.month && people[i].getgender() == "man")
			man = people[i];
		else if (man.getDateOfBirth().day > dateOfSecondPerson.day && people[i].getgender() == "man")
			man = people[i];
	}
	cout << man << endl;
}

void printGroupedBy(vector<Data>& people, char firstLetterOfLastsNames) {
	bool suchPersonsExists = false;
	for (int i = 0; i < people.size(); ++i)
		if (people[i].getPersonalData().Surname[0] == firstLetterOfLastsNames) {
			suchPersonsExists = true;
			cout << people[i] << endl;
		}

	if (!suchPersonsExists)
		cout << "Таких сотрудников нет\n";
}