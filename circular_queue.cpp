#include <bits/stdc++.h>
using namespace std;
#define max 5  // Maximum queue size

class CircularQueue {
private:
    int arr[max];
    int front, back;

public:
    CircularQueue() {
        front = -1;
        back = -1;
    }

    // Enqueue (Insert an element)
    void enqueue(int val) {
        if ((back + 1) % max == front) {  // FIX: Correct full condition
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // If queue is empty, reset front

        back = (back + 1) % max;  // Move `back` circularly
        arr[back] = val;
    }

    // Dequeue (Remove an element)
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        if (front == back) {  // If only one element left
            front = back = -1;
        } else {
            front = (front + 1) % max; // Move `front` circularly
        }
    }
    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }
    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == back) break;  // Stop when we reach `back`
            i = (i + 1) % max; // Move `i` circularly
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();  // Output: 10 20 30 40 50

    cq.enqueue(60);  // Should print "Queue Overflow!"

    cq.dequeue();
    cq.display();  // Output: 20 30 40 50

    return 0;
}
