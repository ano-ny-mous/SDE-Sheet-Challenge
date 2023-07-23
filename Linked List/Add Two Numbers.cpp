//Time Complexity: O(n1+n2)
//Space Complexity: O(n1+n2)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode();
        ListNode* start=l3;
        int carry=0;
        int sum=0;
        while(l1||l2)
        {
            if(l1)
            {
                sum=sum+l1->val;
            }
            if(l2)
            {
                sum=sum+l2->val;
            }
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            l3->next=temp;
            l3=temp;
            sum=carry;
            carry=0;
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(sum>0)
        {
            ListNode* temp=new ListNode(sum);
            l3->next=temp;
        }
        return  start->next;
    }
};