#include <iostream>
#include "Deque_dynamic.h"
#include "Deque_static.h"
using namespace std;


void dynamic_Deque() {
    Deque<int> deque;

    int choice, value;

    cout << "Deque Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Pop Front" << endl;
    cout << "4. Pop Back" << endl;
    cout << "5. Display Front" << endl;
    cout << "6. Display Back" << endl;
    cout << "7. Print Deque" << endl;
    cout << "8. Clear Deque" << endl;
    cout << "9. Check if Deque is empty" << endl;
    cout << "10. Print Deque size" << endl;
    cout << "11. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            deque.pushFront(value);
            cout << "Element pushed to the front." << endl;
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            deque.pushBack(value);
            cout << "Element pushed to the back." << endl;
            break;
        case 3:
            deque.popFront();
            cout << "Element popped from the front." << endl;
            break;
        case 4:
            deque.popBack();
            cout << "Element popped from the back." << endl;
            break;
        case 5:
            try {
                cout << "Front element: " << deque.front() << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 6:
            try {
                cout << "Back element: " << deque.back() << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 7:
            deque.print();
            break;
        case 8:
            deque.clear();
            cout << "Deque cleared." << endl;
            break;
        case 9:
            cout << (deque.empty() ? "Deque is empty." : "Deque is not empty.") << endl;
            break;
        case 10:
            cout << deque.getSize() << endl;
            break;
        case 11:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

}


void static_Deque() {

    DequeStatic<int, 10> deque;

    int choice, value;

    cout << "Deque Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Pop Front" << endl;
    cout << "4. Pop Back" << endl;
    cout << "5. Display Front" << endl;
    cout << "6. Display Back" << endl;
    cout << "7. Print Deque" << endl;
    cout << "8. Clear Deque" << endl;
    cout << "9. Check if Deque is empty" << endl;
    cout << "10. Print Deque size" << endl;
    cout << "11. Check if Deque is full" << endl;
    cout << "12. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            deque.pushFront(value);
            cout << "Element pushed to the front." << endl;
            if (deque.isFull()) {
                cout << "Deque is now full!" << endl;
            }
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            deque.pushBack(value);
            cout << "Element pushed to the back." << endl;
            if (deque.isFull()) {
                cout << "Deque is now full!" << endl;
            }
            break;
        case 3:
            deque.popFront();
            cout << "Element popped from the front." << endl;
            break;
        case 4:
            deque.popBack();
            cout << "Element popped from the back." << endl;
            break;
        case 5:
            try {
                cout << "Front element: " << deque.front() << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 6:
            try {
                cout << "Back element: " << deque.back() << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 7:
            deque.print();
            break;
        case 8:
            deque.clear();
            cout << "Deque cleared." << endl;
            break;
        case 9:
            cout << (deque.empty() ? "Deque is empty." : "Deque is not empty.") << endl;
            break;
        case 10:
            cout << deque.getSize() << endl;
            break;
        case 11:
            cout << (deque.isFull() ? "Deque is full." : "Deque is not full.") << endl;
            break;
        case 12:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } 

}


int main() {
    
    int choice;
    cout << "1. Use dynamic Deque" << endl;
    cout << "2. Use static Deque" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        dynamic_Deque();
        break;
    case 2:
        static_Deque();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

    return 0;
}
