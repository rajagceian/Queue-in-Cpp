class MyCircularQueue {
public:
    int front;
    int back;
    int cap;
    vector <int> arr;
    MyCircularQueue(int k) {
        front = -1;
        back = -1;
        cap = k;
        vector <int> temp(cap,0);
        arr=temp;
    }
    
    bool enQueue(int value) {
        if((back + 1)%cap == front){
            return false;
        }
        if(front == -1) front = 0;
        back = (back + 1) % cap;
        arr[back] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1) return false;
        
        if(front == back){
         front = back = -1;
        } else{
         front = (front + 1) % cap;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[back];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (back + 1)%cap == front;
    }
};

