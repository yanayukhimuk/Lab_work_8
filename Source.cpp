#include <Windows.h>
#include "Info.h"
#include "Func.h"

#define EXIT 0
using namespace std;

int userMenu()
{
	system("cls");
	std::cout << "¬ыберите действие: \n"
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
			cout << "¬ведите мес€ц: ";
			cin >> givenMonth;
			PeopleMonth(people, givenMonth);
			break;
		case 7:
			TheOldest(people);
			break;
		case 8:
			char givenLetter;
			cout << "¬ведите символ: ";
			cin >> givenLetter;
			SameLetter(people, givenLetter);
			break;
		default:
			cout << "¬ведите корректное число" << endl;
		}
	} while (menuState != EXIT);
}
