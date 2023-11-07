#pragma once
#include <iostream>
using namespace std;

template<class T>
class Deque {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;
    int size;

public:
    Deque() : frontNode(nullptr), backNode(nullptr), size(0) {}

    void pushBack(const T& val) {
        Node* newNode = new Node(val);

        if (empty()) {
            frontNode = newNode;
            backNode = newNode;
        }
        else {
            newNode->prev = backNode;
            backNode->next = newNode;
            backNode = newNode;
        }

        size++;
    }

    void pushFront(const T& val) {
        Node* newNode = new Node(val);

        if (empty()) {
            frontNode = newNode;
            backNode = newNode;
        }
        else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }

        size++;
    }

    void popFront() {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* nodeToRemove = frontNode;

        if (frontNode == backNode) {
            frontNode = nullptr;
            backNode = nullptr;
        }
        else {
            frontNode = frontNode->next;
            if (frontNode != nullptr) {
                frontNode->prev = nullptr;
            }
        }

        delete nodeToRemove;
        size--;
    }

    void popBack() {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* nodeToRemove = backNode;

        if (frontNode == backNode) {
            frontNode = nullptr;
            backNode = nullptr;
        }
        else {
            backNode = backNode->prev;
            if (backNode != nullptr) {
                backNode->next = nullptr;
            }
        }

        delete nodeToRemove;
        size--;
    }

    const T& front() const {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            throw runtime_error("Empty deque");
        }

        return frontNode->value;
    }

    const T& back() const {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            throw runtime_error("Empty deque");
        }

        return backNode->value;
    }

    bool empty() const {
        return size == 0;
    }

    void print() const {
        Node* current = frontNode;
        cout << "Deque: ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        frontNode = nullptr;
        backNode = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }
};
