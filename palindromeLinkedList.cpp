#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL||head->next==NULL) return true;
    LinkedListNode<int> *slow = head, *fast = head, *prev, *temp;
//     Searching middle node
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    prev = slow, slow = slow->next, prev->next = NULL;
//     Reversing after middle node
    while (slow)
        temp = slow->next, slow->next = prev, prev = slow, slow = temp;
    fast = head, slow = prev;
//     Checking for palindrome
    while (slow)
        if (fast->data != slow->data) return false;
    else fast = fast->next, slow = slow->next;
    return true;
}
