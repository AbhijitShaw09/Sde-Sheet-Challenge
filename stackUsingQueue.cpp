#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    int siz;
    queue<int> q;
   public:
    Stack() {
        // Implement the Constructor.
        siz = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (q.empty());
    }

    void push(int element) {
        // Implement the push() function.
        siz++;
        q.push(element);
        for(int i=0;i<siz;i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(!q.empty()){
            int popped = q.front();
            q.pop();
            siz--;
            return popped;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q.empty())
           return q.front();
       return -1;
    }
};
