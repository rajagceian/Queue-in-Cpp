#include <bits/stdc++.h>
using namespace std;
class PriorityQueue{
private:
    vector<pair<int,int>> pq; // {value , priority}
public:
    void enqueue(int val,int priority){
        pq.push_back({val , priority});
    }

    void dequeue(){
        if(pq.empty()){
            cout<<"Queue Underflow!"<<endl;
            return;
        }
        // find the element with the highest priority
        int maxIdx = 0;
        int n = pq.size();
        for(int i=1;i<n;i++){
            if(pq[i].second > pq[maxIdx].second){
                maxIdx = i;
            }
        }
        pq.erase(pq.begin()+maxIdx);
    }

    void display(){
        if(pq.empty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        for(auto &p : pq){
            cout<<"Value : "<<p.first<<" , Priority : "<<p.second<<endl;
        }
    }
};
int main() {
    PriorityQueue pq;
    pq.enqueue(10,2);
    pq.enqueue(20,5);
    pq.enqueue(30,1);
    pq.display();

    pq.dequeue();
    cout<<"After dequeue : - "<<endl;
    pq.display();
    return 0;
}
