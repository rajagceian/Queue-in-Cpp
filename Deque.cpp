#include <bits/stdc++.h>
using namespace std;
#define MAX 5

class Deque {
private:
    int arr[MAX];
    int front, back, size;

public:
    Deque() {
        front = -1;
        back = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = back = 0;
        } else {
            front = (front - 1 + MAX) % MAX;   // for circular
        }
        arr[front] = val;
        size++;
    }

    void insertBack(int val) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = back = 0;
        } else {
            back = (back + 1) % MAX;
        }
        arr[back] = val;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front = (front + 1) % MAX;
        size--;
        if (size == 0) {
            front = back = -1;
        }
    }

    void deleteBack() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        back = (back - 1 + MAX) % MAX;
        size--;
        if (size == 0) {
            front = back = -1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getBack() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[back];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Deque Elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertFront(40);
    dq.insertBack(70);
    dq.insertFront(50);
    dq.display();

    dq.deleteBack();
    dq.display();

    dq.deleteFront();
    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.getBack() << endl;

    dq.insertFront(60);
    dq.display();
    return 0;
}
