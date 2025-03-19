#include <bits/stdc++.h>
using namespace std;
#define max 5  // Maximum queue size

class Queue {
private:
    int arr[max];
    int front, back;

public:
    Queue() {
        front = -1;
        back = -1;
    }

    // Enqueue (Insert from back)
    void enqueue(int val) {
        if (back >= max - 1) {  // FIX: Correct queue overflow check
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++back] = val;
    }

    // Dequeue (Remove from front)
    void dequeue() {
        if (front == -1 || front > back) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front++;
        if (front > back) front = back = -1;  // FIX: Reset only when last element is removed
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Display elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30
    q.dequeue();
    q.display();  // Output: 20 30
    cout << (q.isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;  
    return 0;
}
