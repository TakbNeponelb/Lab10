/*#include <windows.h>  // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h>    //printf , fgets
#include <conio.h>    // getch
#include <string.h>   // strcpy, strncmp, strchr
#include "Lab10Header.h"
//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

*/

#include <iostream>
#include <cstdio>
#include "Lab10Header.h"
using namespace std;
#pragma warning(disable : 4996)

int main(int argc, char** argv) {
	stack s1, s2, s3;
	int ch, num;
	FILE* fp;
	while (1) {
		cout << "1. Push elements into stack1 from file\n";
		cout << "2. Push elements into stack2 from file\n";
		cout << "3. Display all stack elements\n";
		cout << "4. Merge stacks 1 and 2 into stack 3\n";
		cout << "5. Empty all stacks\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch) {
		case 1:
			fp = fopen(argv[1], "r");
			if (fp == NULL) {
				cout << "File Open Error\n";
				break;
			}
			while (fscanf(fp, "%d", &num) != EOF) {
				s1.push(num);
			}
			fclose(fp);
			break;
		case 2:
			fp = fopen(argv[2], "r");
			if (fp == NULL) {
				cout << "File Open Error\n";
				break;
			}
			while (fscanf(fp, "%d", &num) != EOF) {
				s2.push(num);
			}
			fclose(fp);
			break;
		case 3:
			cout << "Stack 1: ";
			s1.displayStack();
			cout << "Stack 2: ";
			s2.displayStack();
			cout << "Stack 3: ";
			s3.displayStack();
			break;
		case 4:
			mergeStacks(s1, s2, s3);
			cout << "Stack 3 after merge: ";
			s3.displayStack();
			break;
		case 5:
			while (!s1.isEmpty()) {
				s1.pop();
			}
			while (!s2.isEmpty()) {
				s2.pop();
			}
			while (!s3.isEmpty()) {
				s3.pop();
			}
			cout << "All stacks emptied\n";
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Invalid Choice\n";
			break;
		}
	}
	return 0;
}