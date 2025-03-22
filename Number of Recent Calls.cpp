class RecentCounter {
public:
    queue <int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        int lo = t - 3000;
        int hi = t;
        while(!q.empty() && q.front()<lo){
            q.pop();
        }
        return q.size();
    }
};
