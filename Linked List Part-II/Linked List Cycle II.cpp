class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }

        if(slow!=fast)
        return NULL;

        ListNode *temp=head;
        while(temp!=slow)
        {
            temp=temp->next;
            slow=slow->next;
        }
        return slow;
    }
};