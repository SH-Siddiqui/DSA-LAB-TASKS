#include<iostream>
using namespace std;
struct node {
    int rollNo;
    char name[50];
    float marks;
    node* next;
};
void insertatstart(node*& head) {
    node* newnode = new node;
    cout << "Enter Roll Number: ";
    cin >> newnode->rollNo;
    node* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == newnode->rollNo) {
            cout << "Roll number already exists" << endl;
            delete newnode;
            return;
        }
        temp = temp->next;
    }
    cout << "Enter Name: ";
    cin >> newnode->name;
    cout << "Enter Marks: ";
    cin >> newnode->marks;
    newnode->next = head;
    head = newnode;
    display(head);
}
void insertatend(node*& head) {
    node* newnode = new node;
    cout << "Enter Roll Number: ";
    cin >> newnode->rollNo;
    node* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == newnode->rollNo) {
            cout << "Roll number already exists" << endl;
            delete newnode;
            return;
        }
        temp = temp->next;
    }
    cout << "Enter Name: ";
    cin >> newnode->name;
    cout << "Enter Marks: ";
    cin >> newnode->marks;
    newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;
    }
    else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    display(head);
}
void insertafterpos(node*& head, int roll) {
    node* temp = head;
    while (temp != nullptr && temp->rollNo != roll) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Roll number not found" << endl;
        return;
    }
    node* newnode = new node;
    cout << "Enter Roll Number: ";
    cin >> newnode->rollNo;
    node* check = head;
    while (check != nullptr) {
        if (check->rollNo == newnode->rollNo) {
            cout << "Roll number already exists" << endl;
            delete newnode;
            return;
        }
        check = check->next;
    }
    cout << "Enter Name: ";
    cin >> newnode->name;
    cout << "Enter Marks: ";
    cin >> newnode->marks;
    newnode->next = temp->next;
    temp->next = newnode;
    display(head);
}
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
void deleteStudent(node*& head, int roll) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    node* temp = head;
    node* previous = nullptr;
    while (temp != nullptr && temp->rollNo != roll) {
        previous = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Student not found" << endl;
        return;
    }
    if (previous == nullptr) {
        head = head->next;
    }
    else {
        previous->next = temp->next;
    }
    delete temp;
    display(head);
}
void search(node* head, int roll) {
    while (head != nullptr) {
        if (head->rollNo == roll) {
            cout << "Student found!" << endl;
            cout << "Roll Number: " << head->rollNo << endl;
            cout << "Name: " << head->name << endl;
            cout << "Marks: " << head->marks << endl;
            return;
        }
        head = head->next;
    }
    cout << "Student not found in the list" << endl;
}
void update(node* head, int roll) {
    while (head != nullptr && head->rollNo != roll) {
        head = head->next;
    }
    if (head == nullptr) {
        cout << "Student not found" << endl;
        return;
    }
    int choice;
    cout << "1. Update Name" << endl;
    cout << "2. Update Marks" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter New Name: ";
        cin >> head->name;
    }
    else if (choice == 2) {
        cout << "Enter New Marks: ";
        cin >> head->marks;
    }
    else {
        cout << "Invalid choice!" << endl;
    }
    display(head);
}
void statistics(node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    float highest = head->marks;
    float lowest = head->marks;
    float total = 0;
    int count = 0;
    node* temp = head;
    while (temp != nullptr) {
        if (temp->marks > highest) {
            highest = temp->marks;
        }
        if (temp->marks < lowest) {
            lowest = temp->marks;
        }
        total = total + temp->marks;
        count++;
        temp = temp->next;
    }
    cout << "Total Students: " << count << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << total / count << endl;
}
void display(node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    cout << "\nRoll No\tName\tMarks" << endl;
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->rollNo << "\t" << temp->name << "\t" << temp->marks << endl;
        temp = temp->next;
    }
}
void freememory(node*& head) {
    node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    node* head = nullptr;
    int choice;
    int roll;
    while (true) {
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Specific Roll Number" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete Student by Roll Number" << endl;
        cout << "7. Search Student" << endl;
        cout << "8. Update Student" << endl;
        cout << "9. Display All Students" << endl;
        cout << "10. Student Statistics" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            insertatstart(head);
        }
        else if (choice == 2) {
            insertatend(head);
        }
        else if (choice == 3) {
            cout << "Enter Roll Number after which to insert: ";
            cin >> roll;
            insertafterpos(head, roll);
        }
        else if (choice == 4) {
            deletefromstart(head);
        }
        else if (choice == 5) {
            deletefromend(head);
        }
        else if (choice == 6) {
            cout << "Enter Roll Number to delete: ";
            cin >> roll;
            deleteStudent(head, roll);
        }
        else if (choice == 7) {
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            search(head, roll);
        }
        else if (choice == 8) {
            cout << "Enter Roll Number to update: ";
            cin >> roll;
            update(head, roll);
        }
        else if (choice == 9) {
            display(head);
        }
        else if (choice == 10) {
            statistics(head);
        }
        else if (choice == 11) {
            freememory(head);
            cout << "Program terminated!" << endl;
            break;
        }
    }
    return 0;
}
