#include<iostream>
using namespace std;
#define SIZE 10

void InsertNode(int);
void DelNode();
void Traverse();

int stack[SIZE], top = -1;

int main(){
    int value, choice;

    while (1) {
    	
        cout << "Stack Operations.\n\n";
        cout << "1. Insert into stack (Push operation).\n";
        cout << "2. Delete from stack (Pop operation).\n";
        cout << "3. Traverse stack.\n";
        cout << "4. Exit.\n\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1:
            cout << "\nEnter value: ";
            cin >> value;
            InsertNode(value);
            break;

        case 2:
            DelNode();
            break;

        case 3:
            Traverse();
            break;

        case 4:
            exit(0);
            break;
        default: cout << "\nEnter valid choice!\n\n";
        }
    }
}


void InsertNode(int value) {
    if (top == SIZE - 1)
        cout << "\nStack is Full!";
    else {
        top++;
        stack[top] = value;
        cout << "\nThe value has been added to the stack.\n\n";
    }
}

void DelNode() {
    if (top == -1)
        cout << "\nStack is Empty!\n";
    else {
        cout << "\nDeleted : " << stack[top] << "\n\n";
        top--;
    }
}

void Traverse() {
    if (top == -1)
        cout << "\nStack is Empty!\n";
    else {
        int i;
        cout << "\nThe Stack contain element/s:\n\n";
        for (i = top; i >= 0; i--)
            cout << stack[i] << "\n\n";
    }
}
