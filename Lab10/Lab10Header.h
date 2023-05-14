#include <windows.h>  // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h>    //printf , fgets
#include <conio.h>    // getch
#include <string.h>   // strcpy, strncmp, strchr
//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#pragma once
#ifndef _MYHEADER_H_
#define _MYHEADER_H_

struct TInfo {
	char FamIO[31];
	int Ball;
};
struct TElem {  // моделирование стека на основе односвязного списка
	TInfo Info;   //  или struct TInfo Info;
	TElem* Next;  // или struct TElem *Next; здесь и далее
};

//-----------------------прототипы-------------------------------------------
TElem* PushStack(TElem* St, TInfo Info); // добавить элемент в стек
TInfo PopStack(TElem** PSt);  //извлечь элемент из стека
// дополнительная процедура перекладывания элемента из одного стека (StTop) в другой(Dop)
void TopToTop(TElem** PSt1, TElem** PSt2); // без изменения адресов элементов, только связи
//----------первая часть: создание стека из текстового файла
TElem* CreateStack(TElem* St);
//----------вторая часть: вывод стека на экран ------
void OutputStack(TElem*& St);
//----------третья часть: решение задачи -------------
TElem* Decide(TElem** PSt1, TElem* St2);
//----------четвертая часть: освобождение памяти -----
TElem* FreeStack(TElem* St);
//---------------------------------------------------------------------------

#endif