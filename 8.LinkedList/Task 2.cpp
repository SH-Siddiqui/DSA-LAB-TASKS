#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void deletefromstart(node*& head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    display(head);
}
void deletefromend(node*& head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        display(head);
}
void deletefrompos(node*& head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1) {
        deletefromstart(head);
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }
    node* del = temp->next;
    temp->next = del->next;
    delete del;
    display(head);
}
void search(node* head, int value) {
    int pos = 1;
    while (head != nullptr) {
        if (head->data == value) {
            cout << "Element found at position: " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Element not found in the list" << endl;
}
void update(node* head, int pos, int newvalue) {
    if (pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }
    temp->data = newvalue;
    cout << "Node updated successfully!" << endl;
    display(head);
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
        cout << "1. Delete from Beginning" << endl;
        cout << "2. Delete from End" << endl;
        cout << "3. Delete from Specific Position" << endl;
        cout << "4. Search an Element" << endl;
        cout << "5. Update a Node Value" << endl;
        cout << "6. Display Linked List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            deletefromstart(head);
        }
        else if (choice == 2) {
            deletefromend(head);
        }
        else if (choice == 3) {
            cout << "Enter position: ";
            cin >> pos;
            deletefrompos(head, pos);
        }
        else if (choice == 4) {
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
        }
        else if (choice == 5) {
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter new value: ";
            cin >> value;
            update(head, pos, value);
        }
        else if (choice == 6) {
            display(head);
        }
        else if (choice == 7) {
            cout << "Program terminated!" << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
