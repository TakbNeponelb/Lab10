#include <iostream>
#include <cstdio>
#include "Lab10Header.h"
using namespace std;
#pragma warning(disable : 4996)

node* top;

void stack::push(int x){
	node* temp = new node;
	temp->data = x;
	temp->next = top;
	top = temp;
};
int stack::pop() {
	node* temp = top;
	int x = temp->data;
	top = top->next;
	delete temp;
	return x;
};
bool stack::isEmpty() {
	return (top == NULL);
};
void stack::displayStack() {
	node* p;
	if (isEmpty()) {
		cout << "Stack is Empty\n";
		return;
	}
	p = top;
	cout << "Stack elements are: ";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
};


void mergeStacks(stack& s1, stack& s2, stack& s3) {
	while (!s1.isEmpty() && !s2.isEmpty()) {
		s3.push(s1.pop());
		s3.push(s2.pop());
	}
	while (!s1.isEmpty()) {
		s3.push(s1.pop());
	}
	while (!s2.isEmpty()) {
		s3.push(s2.pop());
	}
}