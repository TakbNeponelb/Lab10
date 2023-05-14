#include <windows.h>  // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h>    //printf , fgets
#include <conio.h>    // getch
#include <string.h>   // strcpy, strncmp, strchr
#include "Lab10Header.h"
//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int main()
{
	TElem* StackTop1 = NULL, * StackTop2 = NULL;
	char ch;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	do {

		printf("\nN - создать новый стек; V - вывод; D - решение; F - освободить; \
E - конец.\nВаш выбор?");
		ch = getchar();   fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------первая часть: создание стека из текстового
		case 'N': if (StackTop1) {
			printf("Error: сначала надо освободить память!"); break;
		}
				StackTop1 = CreateStack(StackTop1);
				break;
				//----------вторая часть: вывод стеков на экран ------
		case 'V': printf("Первый стек:\n"); OutputStack(StackTop1);
			printf("\nВторой стек (отличники):\n"); OutputStack(StackTop2);
			break;
			//----------третья часть: решение задачи -------------
		case 'D': StackTop2 = Decide(&StackTop1, StackTop2);
			break;
			//----------четвертая часть: освобождение памяти -----
		case 'F': StackTop1 = FreeStack(StackTop1);
			StackTop2 = FreeStack(StackTop2);
			printf("Вся память под стеки особождена\n");
			break;
			//-----------------------выход------------------------
		case 'E': return 0;
		default:
			printf("Нет такой команды\nPress any key");
			_getch();
		}

	} while (ch != 'E');

	return 0;
}
