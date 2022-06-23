class Queue {
    int *arr;
    int n;
    int qfront, back;
public:
    Queue() {
        // Implement the Constructor
        n = 100001;
        arr = new int[n];
        qfront = -1;
        back = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == -1 || qfront > back)
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(back == n-1)
            return;
        back++;
        arr[back] = data;

        if(qfront == -1)
            qfront++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == -1 || qfront > back)
            return -1;
        else {
            int ans = arr[qfront];
            qfront++;
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == -1 || qfront > back)
            return -1;
        return arr[qfront];
    }
};
