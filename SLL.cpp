#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
};

ListNode *head = NULL;

// Insert at Beginning
void insertAtBeg() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    ListNode *newNode = new ListNode;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    ListNode *newNode = new ListNode;
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        ListNode *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

// Insert at Position
void insertAtPos() {
    int val, pos;
    cout << "Enter value: ";
    cin >> val;
    cout << "Enter position (starting from 1): ";
    cin >> pos;

    ListNode *newNode = new ListNode;
    newNode->data = val;

    if (pos <= 0) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Position out of range!\n";
        delete newNode;
    } else {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// Deletion from Beginning
void deleteFromBeg() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    ListNode *temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

// Deletion from End
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }
    ListNode *ptr = head, *prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    cout << "Deleted: " << ptr->data << endl;
    prev->next = NULL;
    delete ptr;
}

// Deletion from Position
void deleteFromPos() {
    int pos;
    cout << "Enter position (starting from 1): ";
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        ListNode *temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }

    ListNode *ptr = head, *prev = NULL;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Position out of range!\n";
    } else {
        prev->next = ptr->next;
        cout << "Deleted: " << ptr->data << endl;
        delete ptr;
    }
}

// Display List
void displayList() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    ListNode *temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch;
    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insertion at Beginning\n";
        cout << "2. Insertion at Position\n";
        cout << "3. Insertion at End\n";
        cout << "4. Deletion from Beginning\n";
        cout << "5. Deletion from Position\n";
        cout << "6. Deletion from End\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: insertAtBeg(); break;
            case 2: insertAtPos(); break;
            case 3: insertAtEnd(); break;
            case 4: deleteFromBeg(); break;
            case 5: deleteFromPos(); break;
            case 6: deleteFromEnd(); break;
            case 7: displayList(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 8);

    return 0;
}
