#include <bits/stdc++.h> 
/****************************************************************
 
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

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* p1 = firstHead, *p2 = secondHead;
    while(p1 != p2) {
        if(p1 == NULL)
            p1 = secondHead;
        else
            p1 = p1->next;
        if(p2 == NULL)
            p2 = firstHead;
        else
            p2 = p2->next;
    }
    if(p1 == NULL)
        return -1;
    return p1->data;
}
