#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *h1 = first, *h2 = second;
    if(!first)
        return second;
    else if(!second)
        return first;
    if(first->data < second->data) {
        first->next = sortTwoLists(first->next, second);
        return first;
    }
    else {
        second->next = sortTwoLists(first, second->next);
        return second;
    }
}
