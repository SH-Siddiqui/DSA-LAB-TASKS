#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
void insertatstart(node*& head, int value) {
	node* newnode = new node;
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}
void insertatend(node*& head, int value) {
	node* newnode = new node;
	newnode->data = value;
	newnode->next = nullptr;
	if (head == nullptr) {
		head = newnode;
	}
	node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newnode;
}
void insertatpos(node*& head, int value, int pos) {
	node* newnode = new node;
	if (pos < 1) {
		cout << "Invalid position";
		return;
	}
	if (pos==1) {
		insertatstart(head, value);
		return;
	}
	node* temp = head;
	for (int i = 0; i < pos - 1; i++) {
		temp = temp->next;
	}
	newnode->data = value;
	temp->next = newnode->next;
	temp->next = newnode;
}
void display(node* head) {
	if (head == nullptr) {
		cout << "Linked list is empty" << endl;
		return;
	}
	node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "Nullptr" << endl;
}
int main() {
	node* head = nullptr;
	int choice;
	int value;
	int pos;
	while (true) {
	cout << "Enter choice";
	cin >> choice;
	if (choice == 1) {
		cout << "Enter value: ";
		cin >> value;
		insertatstart(head, value);
		cout << "Node inserted successfully!" <<endl;
	}
	else if (choice == 2) {
		cout << "Enter value: ";
		cin >> value;
		insertatend(head, value);
		cout << "Node inserted successfully!" <<endl;
	}
	else if (choice == 3) {
		cout << "Enter value: ";
		cin >> value;
		cout << "Enter position: ";
		cin >> pos;
		insertatpos(head, value, pos);
	}
	else if (choice == 4) {
		display(head);
	}
	else if (choice == 5) {
		cout << "Program terminated!" <<endl;
		break;
	}
}
	return 0;
}