#include<iostream>
using namespace std;
struct node {
    int x;
    int y;
    node* next;
};
bool collisionCheck(node* head, int x, int y) {
    while (head != nullptr) {
        if (head->x == x && head->y == y) {
            return true;
        }
        head = head->next;
    }
    return false;
}
void printSnake(node* head) {
    if (head == nullptr) {
        cout << "Snake is empty" << endl;
        return;
    }
    cout << "Snake: ";
    while (head != nullptr) {
        cout << "(" << head->x << "," << head->y << ")";
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << " -> nullptr" << endl;
}
void grow(node*& head, int x, int y) {
    node* newnode = new node;
    newnode->x = x;
    newnode->y = y;
    newnode->next = head;
    head = newnode;
}
void move(node*& head, int x, int y, bool food) {
    if (collisionCheck(head, x, y)) {
        if (food == false && head->next == nullptr) {
            cout << "Self Collision Detected!" << endl;
            return;
        }
        if (food == true) {
            cout << "Self Collision Detected!" << endl;
            return;
        }
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        if (temp->next->x != x || temp->next->y != y) {
            cout << "Self Collision Detected!" << endl;
            return;
        }
    }
    grow(head, x, y);
    if (food == false) {
        if (head->next == nullptr) {
            return;
        }
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    printSnake(head);
}
void freeMemory(node*& head) {
    node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    node* head = nullptr;
    grow(head, 3, 3);
    grow(head, 2, 3);
    grow(head, 1, 3);
    cout << "Initial Snake:" << endl;
    printSnake(head);
    cout <<endl << "Move 1:" << endl;
    move(head, 0, 3, false);
    cout << endl << "Move 2:" << endl;
    move(head, 0, 2, false);
    cout << endl << "Move 3 (Food Eaten):" << endl;
    move(head, 0, 1, true);
    cout << endl << "Move 4:" << endl;
    move(head, 1, 1, false);
    cout << endl << "Move 5 (Self Collision):" << endl;
    move(head, 0, 2, false);
    freeMemory(head);
    return 0;
}
