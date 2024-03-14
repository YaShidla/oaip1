#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include "header.h"


extern int kol_student;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	int choice;
	do {
		printf("1. Заполнить информацию.\n");
		printf("2. Прочитать информацию.\n");
		printf("3. Прочитать определённую информацию.\n");
		printf("4. Сортировать определённую информацию.\n");
		printf("5. Вывести информацию о студентах с фамилией на А.\n");
		printf("6. Удалить информацию о студенте.\n");
		printf("7. Добавить информацию о новом студенте.\n");
		printf("8. Выйти из программы.\n\n");
		printf("Сделайте свой выбор: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: enter();
			break;
		case 2: print();
			break;
		case 3: read();
			break;
		case 4: sort();
			break;
		case 5: vivodA();
			break;
		case 6: del();
			break;
		case 7: add();
			break;
		case 8: return 0;
		}
	} while (choice != 8);
	return 0;
}
