class MinStack {
    
    stack<int>ms;
    stack<int>as;
public:

MinStack() {
    
}

void push(int val) {
    
    if(as.empty())
    {
        as.push(val);
        ms.push(val);
        
        return ;
    }
        
    
       ms.push(val);
    
    if(as.top() >= ms.top())
        as.push(val);
    
}

void pop() {
    
    if(as.top() == ms.top())
        as.pop();
    
       ms.pop();
}

int top() {
    
    return ms.top();
}

int getMin() {
    
    return as.top();
}

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */