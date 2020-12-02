#include "Info.h"
#include "Func.h"
#include <Windows.h>

int userMenu()
{
	system("cls");
	cout << "�������� ��������: \n"
		<< "1. ��������� ������ �� �����\n"
		<< "2. ����� ������ �� �����\n"
		<< "3. ���������� ������\n"
		<< "4. ���������� ���� ������ �� ��������(�� �������)\n"
		<< "5. ���������� ���� ������ �� ��������\n"
		<< "6. ����� : ������ �����, ���������� � �������� ������\n"
		<< "7. ����� : ������� ������ �������� �������\n"
		<< "8. ����� : ��� �������, ������������ � �������� �����\n"
		<< "0. ����� �� ���������\n"
		<< "> \n";

	int userChoice{ -1 };
	cin >> userChoice;
	system("cls");
	return userChoice;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string fileName = "LABA.txt";
	vector<Data> people;

	while (true) {
		switch (userMenu()) {
		case 0:
			return 0;
		case 1:
			dataLoad(people, fileName);
			break;
		case 2:
			dataOutput(people);
			break;
		case 3:
			dataAppend(people, fileName);
			break;
		case 4:
			sortDataBySurname(people);
			break;
		case 5:
			sortDataByAge(people);
			break;
		case 6:
			int givenMonth;
			cout << "������� �����: ";
			cin >> givenMonth;
			printPeopleWithBirthMonth(people, givenMonth);
			break;
		case 7:
			printOldestOf(people);
			break;
		case 8:
			char givenLetter;
			cout << "������� ������: ";
			cin >> givenLetter;
			printGroupedBy(people, givenLetter);
			break;
		default:
			cout << "������� ���������� �����" << endl;
		}
	}
}