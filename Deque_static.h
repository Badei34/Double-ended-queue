#pragma once
#include <iostream>
using namespace std;

template<class T, int maxSize = 10>
class DequeStatic {
private:
    T elements[maxSize];
    int frontIndex;
    int backIndex;
    int size;

public:
    DequeStatic() : frontIndex(-1), backIndex(-1), size(0) {}

    void pushBack(const T& val) {
        if (size >= maxSize) {
            cout <<"Deque is full!" << endl;
            return;
        }

        if (empty()) {
            frontIndex = 0;
            backIndex = 0;
        }
        else {
            backIndex = (backIndex + 1) % maxSize;
        }

        elements[backIndex] = val;
        size++;
    }

    void pushFront(const T& val) {
        if (size >= maxSize) {
            cout << "Deque is full!" << endl;
            return;
        }

        if (empty()) {
            frontIndex = 0;
            backIndex = 0;
        }
        else {
            frontIndex = (frontIndex - 1 + maxSize) % maxSize;
        }

        elements[frontIndex] = val;
        size++;
    }

    void popFront() {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        frontIndex = (frontIndex + 1) % maxSize;
        size--;
    }

    void popBack() {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        backIndex = (backIndex - 1 + maxSize) % maxSize;
        size--;
    }

    const T& front() const {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            throw runtime_error("Empty deque");
        }

        return elements[frontIndex];
    }

    const T& back() const {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            throw runtime_error("Empty deque");
        }

        return elements[backIndex];
    }

    bool empty() const {
        return size == 0;
    }

    void print() const {
        if (empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        int currentIndex = frontIndex;
        for (int i = 0; i < size; ++i) {
            cout << elements[currentIndex] << " ";
            currentIndex = (currentIndex + 1) % maxSize;
        }

        cout << endl;
    }

    void clear() {
        frontIndex = -1;
        backIndex = -1;
        size = 0;
    }

    bool isFull() const {
        return size == maxSize;
    }

    int getSize() const {
        return size;
    }
};

