#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/

Node* rotate(Node* head)
{
    Node* prev = new Node(0);
    Node* curr = new Node(0);
    prev = head, curr = head;
    curr = head->next;

    while(curr->next != NULL){
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = NULL;
    curr->next = head;
    head = curr;

    return head;
}

Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    Node *p = new Node(0);
    p = head;
    int length=0;
    while(p->next) {
        length++;
        p = p->next;
    }
    length++;
    
    k = k % length;
    if(k == 0)
        return head;

    for(int i=0; i<k; i++)
        head = rotate(head);

    return head;
}
