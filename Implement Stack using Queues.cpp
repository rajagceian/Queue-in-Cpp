class MyStack {
public:
    queue <int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int top = q1.back();
        
        while(q1.size()>1){
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        swap(q1,q2);
        while (!q2.empty()) {
         q2.pop();
        }
        return top;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};
