#include <Windows.h>
#include "Info.h"
#include "Func.h"

#define EXIT 0
using namespace std;

int userMenu()
{
	system("cls");
	std::cout << "�������� ��������: \n"
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
	std::cin >> userChoice;
	std::cout << std::endl;
	return userChoice;
} 



int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
    string fileName = "LABA.txt";
	//OpenFile();
	int menuState; 

	std::vector<Data> people;
	

	do {
		userMenu();
		cin >> menuState;
		system("cls");

		switch (menuState) {
		case 0:
			exit(EXIT);
		case 1:
			dataLoad(people, fileName);
			break;
		case 2:
			dataInput(people);
			break;
		case 3:
			dataAppend(people, fileName);
			people.clear();
			dataLoad(people, fileName);
			break;
		case 4:
			dataSortSurname(people);
			break;
		case 5:
			dataSortAge(people);
			break;
		case 6:
			int givenMonth;
			cout << "������� �����: ";
			cin >> givenMonth;
			PeopleMonth(people, givenMonth);
			break;
		case 7:
			TheOldest(people);
			break;
		case 8:
			char givenLetter;
			cout << "������� ������: ";
			cin >> givenLetter;
			SameLetter(people, givenLetter);
			break;
		default:
			cout << "������� ���������� �����" << endl;
		}
	} while (menuState != EXIT);
}
