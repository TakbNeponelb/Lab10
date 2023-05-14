#include <windows.h>  // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h>    //printf , fgets
#include <conio.h>    // getch
#include <string.h>   // strcpy, strncmp, strchr
#include "Lab10Header.h"
//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


//---------------------------------------------------------------------------
TElem* PushStack(TElem* St, TInfo Info) { // �������� ������� � ����
	TElem* Elem = new TElem;
	Elem->Info.Ball = Info.Ball;
	strcpy(Elem->Info.FamIO, Info.FamIO);
	Elem->Next = St;
	return Elem; // ����� ����� �������
}
TInfo PopStack(TElem** PSt) { //������� ������� �� �����
	TElem* Elem = *PSt;
	TInfo Info = Elem->Info;
	*PSt = Elem->Next;
	delete Elem;
	return Info;
}
// �������������� ��������� �������������� �������� �� ������ ����� (StTop) � ������(Dop)
void TopToTop(TElem** PSt1, TElem** PSt2) {
	TElem* Elem, * StTop = *PSt1, * Dop = *PSt2;
	Elem = StTop;
	StTop = StTop->Next;  // ��� StTop=(*StTop).Next;
	Elem->Next = Dop;
	Dop = Elem;
	*PSt1 = StTop; *PSt2 = Dop;  // ��������� ����� ������ ������ �� ������� PSt1 � PSt2
	return;
}
//----------������ �����: �������� ����� �� ����������
TElem* CreateStack(TElem* St) {
	int kol = 0;
	char* n, * r;
	TInfo Info;
	char Balls[5];

	while (1) {
		printf("FamIO (��� **)=?");
		fgets(Info.FamIO, 30, stdin);  fflush(stdin);
		n = strchr(Info.FamIO, '\n'); if (n) Info.FamIO[n - Info.FamIO] = '\0';
		if (strncmp(Info.FamIO, "**", 2) == 0) break; // ������� ��������� ����� - ��� ������ ������� **
		printf("Ball =?");
		fgets(Balls, 4, stdin); fflush(stdin);
		Info.Ball = atoi(Balls);

		St = PushStack(St, Info);
		kol++;
	}
	printf("������ ���� �� %d ���������\n", kol);
	printf("Press any key to continue");
	_getch();
	return St;
}
//----------������ �����: ����� ����� �� ����� ------
void OutputStack(TElem*& St) {
	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("������\n");
	while (St) {
		inf = PopStack(&St);
		printf("%30s %3d\n", inf.FamIO, inf.Ball);
		Dop = PushStack(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);

	printf("Press any key to continue");
	_getch();
	return;
}
//----------������ �����: ������� ������ -------------
TElem* Decide(TElem** PSt1, TElem* St2) {
	TElem* St1 = *PSt1, * Dop = NULL;
	St2 = FreeStack(St2);

	int Sum = 0, N = 0;
	while (St1) {
		Sum += St1->Info.Ball;
		N++;
		if (St1->Info.Ball >= 85) St2 = PushStack(St2, St1->Info); // ���������
		TopToTop(&St1, &Dop);
	}
	while (Dop) TopToTop(&Dop, &St1);

	if (N) printf("������� ���� = %6.2f\n", (float)Sum / N);
	else printf("���� ����\n");

	printf("Press any key to continue");
	_getch();
	*PSt1 = St1; // ����� ����� ����� �������� (��������� �� ������)
	return St2;  // ����� ����� ����� ��������� ������� ��������
}
//----------��������� �����: ������������ ������ -----
TElem* FreeStack(TElem* St) {
	TInfo Info;
	while (St) {
		Info = PopStack(&St);
	}
	return St;
}
//---------------------------------------------------------------------------
