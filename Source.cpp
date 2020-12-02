#include "Info.h"
#include "Func.h"
#include <Windows.h>

int userMenu()
{
	system("cls");
	cout << "¬ыберите действие: \n"
		<< "1. загрузить данные из файла\n"
		<< "2. вывод данных на экран\n"
		<< "3. добавление данных\n"
		<< "4. сортировка базы данных по алфавиту(по фамилии)\n"
		<< "5. сортировка базы данных по возрасту\n"
		<< "6. вывод : список людей, родившихс€ в заданном мес€це\n"
		<< "7. вывод : фамилию самого старшего мужчины\n"
		<< "8. вывод : все фамилии, начинающиес€ с заданной буквы\n"
		<< "0. выход из программы\n"
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
			cout << "¬ведите мес€ц: ";
			cin >> givenMonth;
			printPeopleWithBirthMonth(people, givenMonth);
			break;
		case 7:
			printOldestOf(people);
			break;
		case 8:
			char givenLetter;
			cout << "¬ведите символ: ";
			cin >> givenLetter;
			printGroupedBy(people, givenLetter);
			break;
		default:
			cout << "¬ведите корректное число" << endl;
		}
	}
}