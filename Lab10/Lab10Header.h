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
struct TElem {  // ������������� ����� �� ������ ������������ ������
	TInfo Info;   //  ��� struct TInfo Info;
	TElem* Next;  // ��� struct TElem *Next; ����� � �����
};

//-----------------------���������-------------------------------------------
TElem* PushStack(TElem* St, TInfo Info); // �������� ������� � ����
TInfo PopStack(TElem** PSt);  //������� ������� �� �����
// �������������� ��������� �������������� �������� �� ������ ����� (StTop) � ������(Dop)
void TopToTop(TElem** PSt1, TElem** PSt2); // ��� ��������� ������� ���������, ������ �����
//----------������ �����: �������� ����� �� ���������� �����
TElem* CreateStack(TElem* St);
//----------������ �����: ����� ����� �� ����� ------
void OutputStack(TElem*& St);
//----------������ �����: ������� ������ -------------
TElem* Decide(TElem** PSt1, TElem* St2);
//----------��������� �����: ������������ ������ -----
TElem* FreeStack(TElem* St);
//---------------------------------------------------------------------------

#endif