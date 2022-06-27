#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
	// Write your code here.
	int mn;
    stack<int> s;
    stack<int> ss;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            mn = -1;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            s.push(num);
            if(ss.size() == 0 || num <= ss.top())
                ss.push(num);
            return;            
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(s.size() == 0)
                return -1;
            int ans = s.top();
            s.pop();
            if(ss.size() > 0 && ss.top() == ans)
                ss.pop();
            return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(s.size() == 0)
                return -1;
            return s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(ss.size() == 0)
                return -1;
            return ss.top();
		}
};
