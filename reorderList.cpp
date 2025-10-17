
class Solution {
public:
ListNode* reverseList(ListNode* head) {
    // REcursion
        if(head == NULL || head->next== NULL) return head;
    //ITTERATION
       ListNode* prev = NULL;    
       ListNode* curr = head;    
       ListNode* Next = head;  
       while(curr){
        Next = Next->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
       }  

       head = prev;
       return head;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

        }
        // slow is at the left middle
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // for breaking list
        // merge two alternatively
        ListNode* c = new ListNode(415);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA && tempB){
             tempC->next = tempA;
             tempA = tempA->next;
             tempC = tempC->next;

             tempC->next = tempB;
             tempB = tempB->next;
             tempC = tempC->next;
        }
        tempC->next  =tempA;
        head = c->next;
    }
};
