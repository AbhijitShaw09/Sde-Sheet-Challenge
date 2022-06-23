// Stack class.
class Stack {
    int *arr;
    int topp;
    int n;
public:
    
    Stack(int capacity) {
        // Write your code here.
        n = capacity;
        arr = new int[n];
        topp = -1;
    }

    void push(int num) {
        // Write your code here.
        if(topp < n-1) 
            arr[++topp] = num;
    }

    int pop() {
        // Write your code here.
        if(topp != -1)
            return arr[topp--];
        else 
            return -1;
    }
    
    int top() {
        // Write your code here.
        if(topp != -1 && topp < n)
            return arr[topp];
        else
            return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(topp == -1)
            return 1;
        else
            return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(topp >= n)
            return 1;
        else
            return 0;
    }
    
};
