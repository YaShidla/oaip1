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
		printf("1. ��������� ����������.\n");
		printf("2. ��������� ����������.\n");
		printf("3. ��������� ����������� ����������.\n");
		printf("4. ����������� ����������� ����������.\n");
		printf("5. ������� ���������� � ��������� � �������� �� �.\n");
		printf("6. ������� ���������� � ��������.\n");
		printf("7. �������� ���������� � ����� ��������.\n");
		printf("8. ����� �� ���������.\n\n");
		printf("�������� ���� �����: ");
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
