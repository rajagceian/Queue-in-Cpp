#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue using Linked List
class LinkedListQueue {
private:
    Node* front;
    Node* back;

public:
    LinkedListQueue() {
        front = NULL;
        back = NULL;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (back == NULL) {  // If queue is empty
            front = back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) back = NULL; // If queue becomes empty
        delete temp;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedListQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    q.enqueue(40);
    q.display();  // Output: 20 30 40

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
