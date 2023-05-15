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


void mergeStacks(stack* s1, stack* s2) {
    if ((*s1).isEmpty()) {
        s2->top = NULL;
        s1->top = s2->top;
        return;
    }
    if ((*s2).isEmpty()) {
        return;
    }
    node* temp1 = s1->top;
    node* temp2 = s2->top;
    node* prev = NULL;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data > temp2->data) {
            prev = temp1;
            temp1 = temp1->next;
        }
        else {
            node* next = temp2->next;
            
            temp2->next = temp1;
            
            if (prev == NULL) {
                s1->top = temp2;
                
            }
            else {
                
                prev->next = temp2;
                 
            }
            
            prev = temp2;
            temp2 = next;
            if (s2->top == NULL) {
                s2->top = temp2;
        }
    }
    if (temp1 == NULL) 
    
        prev->next = temp2;
        s2->top = NULL;
    }
}
