#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "header.h"


struct spisok
{
	int nomer_studenta;
	char fio[40];
	int birth;
	int postup;
	int fiz;
	int mat;
	int inf;
};
static FILE* file;
static spisok data[20], k[20];
int kol_student;

extern void save()
{
	file = fopen("D:\\output.txt", "w");
	fprintf(file, "\n");
	fprintf(file, "#                ФИО     ГОД РОЖД.     ГОД ПОСТ.     ФИЗ.     МАТ.     ИНФ.'\n");
	fprintf(file, "*****************************************************************************\n");
	for (int i = 0; i < kol_student; i++)
	{
		fprintf(file, "\n");
		fprintf(file, "%d %18s %13d %13d %8d %8d %8d", data[i].nomer_studenta, data[i].fio, data[i].birth, data[i].postup, data[i].fiz, data[i].mat, data[i].inf);
		fprintf(file, "\n");
	}
	fclose(file);
}

extern bool checks(char s[40])
{
	register int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'а' && s[i] <= 'я') || (s[i] >= 'А' && s[i] <= 'Я') || s[i] == ' '  || s[i] == '.') i++;
		else
		{
			printf("Неверный формат ввода данных.\n");
			printf("Введите их снова.\n\n");
			return false;
		}
	}
	return true;
}

extern void enter()
{
	register int i;
	printf("Как много человек поступило: ");
	scanf_s("%d", &kol_student);
	for (i = 0; i < kol_student; i++)
	{
		printf("\nВвести номер студента: ");
		scanf_s("%d", &data[i].nomer_studenta);
		printf("Ввести ФИО: ");
		register char s[40];
		getchar();
		gets_s(data[i].fio, 20);
		while (!checks(data[i].fio))
		{
			gets_s(data[i].fio, 40);
		}
		printf("Ввести год рождения: ");
		scanf_s("%d", &data[i].birth);
		printf("Ввести год поступления: ");
		scanf_s("%d", &data[i].postup);
		printf("Ввести отметку за первый семестр по физике: ");
		scanf_s("%d", &data[i].fiz);
		printf("Ввести отметку за первый семестр по высшей математике: ");
		scanf_s("%d", &data[i].mat);
		printf("Ввести отметку за первый семестр по информатике: ");
		scanf_s("%d", &data[i].inf);
	}
	printf("\n");
}
extern void print()
{
	register int i;
	printf("\n");
	printf("#                ФИО     ГОД РОЖД.     ГОД ПОСТ.     ФИЗ.     МАТ.     ИНФ.'\n");
	printf("*****************************************************************************\n");
	for (i = 0; i < kol_student; i++)
	{
		if (data[i].nomer_studenta != -1)
		{
			printf("%d %18s %13d %13d %8d %8d %8d", data[i].nomer_studenta, data[i].fio, data[i].birth, data[i].postup, data[i].fiz, data[i].mat, data[i].inf);
			printf("\n");
		}
		
	}
	printf("\n");
}
extern int read()
{
	register int i;
	printf("Введите номер студента, чтобы прочитать информацию.\n");
	int choice;
	scanf_s("%d", &choice);
	for (i = 0; i < kol_student; i++)
	{
		if (choice == data[i].nomer_studenta)
		{
			printf("#               ФИО      ГОД РОЖД.     ГОД ПОСТ.     ФИЗ.     МАТ.     ИНФ.'\n");
			printf("*****************************************************************************\n");
			printf("%d %18s %13d %13d %8d %8d %8d", data[i].nomer_studenta, data[i].fio, data[i].birth, data[i].postup, data[i].fiz, data[i].mat, data[i].inf);
			printf("\n\n");
			return 0;
		}
	}
	printf("Нет студента с таким номером.\n\n");
}
extern void sort_nomer()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++) 
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].nomer_studenta > data[j].nomer_studenta)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
}
extern void sort_fio()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (strcmp(data[i].fio, data[j].fio) > 0)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новий список");
	print();
}
extern void sort_birth()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].birth > data[j].birth)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
}
extern void sort_post()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].postup > data[j].postup)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
	save();
}
extern void sort_fiz()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].fiz < data[j].fiz)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
	save();
}
extern void sort_mat()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].mat < data[j].mat)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
	save();
}
extern void sort_inf()
{
	register int i, j;
	printf("старый список");
	print();
	for (i = 0; i < kol_student - 1; i++)
		for (j = i + 1; j < kol_student; j++)
		{
			if (data[i].inf < data[j].inf)
			{
				k[j] = data[i];
				data[i] = data[j];
				data[j] = k[j];
			}
		}
	printf("новый список");
	print();
}
extern int del()
{
	register int i, j = 1;
	int choice;
	printf("Введите номер студента, информацию о котором хотите удалить.\n");
	scanf_s("%d", &choice);
	for (i = 0; i < kol_student; i++)
	{
		if (data[i].nomer_studenta == choice)
			data[i].nomer_studenta = -1;
	}
	printf("\n");
	return 0;
}
extern int vivodA()
{
	register int i, j = 1;
	for (i = 0; i < kol_student; i++)
	{
		if ((data[i].fio[0] == 'A' || data[i].fio[0] == 'a') && (data[i].nomer_studenta != -1))
		{
			if (j == 1)
			{
				printf("#                ФИО      ГОД РОЖД.     ГОД ПОСТ.     ФИЗ.     МАТ.     ИНФ.'\n");
				printf("*****************************************************************************\n");
			}
			printf("%d %18s %13d %13d %8d %8d %8d", j, data[i].fio, data[i].birth, data[i].postup, data[i].fiz, data[i].mat, data[i].inf);
			printf("\n");
			j++;
		}
	}
	if (j == 1) printf("Нет таких студентов.\n");
	printf("\n");
	return 0;
}
extern void add()
{
	printf("Введите информацию о новом студенте:\n");
	printf("\nВвести номер студента: ");
	scanf_s("%d", &data[kol_student].nomer_studenta);
	printf("Ввести ФИО: ");
	register char s[40];
	getchar();
	gets_s(data[kol_student].fio, 20);
	while (!checks(data[kol_student].fio))
	{
		gets_s(data[kol_student].fio, 40);
	}
	printf("Ввести год рождения: ");
	scanf_s("%d", &data[kol_student].birth);
	printf("Ввести год поступления: ");
	scanf_s("%d", &data[kol_student].postup);
	printf("Ввести отметку за первый семестр по физике: ");
	scanf_s("%d", &data[kol_student].fiz);
	printf("Ввести отметку за первый семестр по высшей математике: ");
	scanf_s("%d", &data[kol_student].mat);
	printf("Ввести отметку за первый семестр по информатике: ");
	scanf_s("%d", &data[kol_student].inf);
	printf("\n");
	kol_student++;
}
extern int sort()
{
	if (!data[0].nomer_studenta)
	{
		printf("Вы должны ввести информацию.\n\n");
		return 0;
	}
	int choice;
	do {
		printf("\t1. Сортировать по \"номеру студента\".\n");
		printf("\t2. Сортировать по \"ФИО студента\".\n");
		printf("\t3. Сортировать по \"году рождения\".\n");
		printf("\t4. Сортировать по \"году поступления\".\n");
		printf("\t5. Сортировать по \"отметке по физике\".\n");
		printf("\t6. Сортировать по \"отметке по высшей математике\".\n");
		printf("\t7. Сортировать по \"отметке по информатике\".\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: sort_nomer();
			break;
		case 2: sort_fio();
			break;
		case 3: sort_birth();
			break;
		case 4: sort_post();
			break;
		case 5: sort_fiz();
			break;
		case 6: sort_mat();
			break;
		case 7: sort_inf();
			break;
		}
	} while (choice > 8);
	printf("***СКОМПИЛИРОВАНО***\n");
	printf("\n");
	return 0;
}
