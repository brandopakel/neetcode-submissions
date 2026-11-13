#include <queue>

class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;
public:
    MyStack() {    
    }
    
    void push(int x) {
        while(!q1.empty()){
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(!q1.empty()){
            int val = q1.front();
            q1.pop();
            return val;
        }
    }
    
    int top() {
        if(!q1.empty()){
            int val = q1.front();
            return val;
        }
    }
    
    bool empty() {
        if(!q1.empty()){
            return false;
        } else{
            return true;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */