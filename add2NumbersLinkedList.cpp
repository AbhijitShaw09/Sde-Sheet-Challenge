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
Node* push(Node* head, int val) {
    Node* newP = new Node(0);
    newP->data = val;
    newP->next = head;
    head = newP;
    return head;
};

Node* reverseLL(Node* head) {
    if(head == NULL)
        return head;

    /* Create new nodes */
    Node* current = NULL, *next = head->next;
    head->next = NULL;

    /* Reverse LL */
    while(next != NULL){
        current = next;
        next = next->next;
        current->next = head;
        head = current;
    }
    return head;
};

Node *add(Node *head1, Node *head2)
{
    // Write your code here.
    Node *ptr1 = head1, *ptr2 = head2, *head3 = NULL;
    int carry = 0, sum;
    while(ptr1 || ptr2){
        sum = 0;
        if(ptr1)
            sum += ptr1->data;
        if(ptr2)
            sum += ptr2->data;
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        head3 = push(head3, sum);
        if(ptr1)
            ptr1 = ptr1->next;
        if(ptr2)
            ptr2 = ptr2->next;
    }
    if(carry)
        head3 = push(head3, carry);
    return head3;
}

// Driver Code
Node* addTwoNumbers(Node* head1, Node* head2){
    Node* head3 = NULL;
    head3 = add(head1, head2);
    head3 = reverseLL(head3);
    return head3;
}
