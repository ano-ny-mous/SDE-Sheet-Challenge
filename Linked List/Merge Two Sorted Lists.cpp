//Approach - 1
//Time Complexity: O(n1+n2)
//Space Complexity: O(n1+n2)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        ListNode* list3=new ListNode();
        ListNode* newhead=list3;
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                list3->next=new ListNode(list1->val);
                list1=list1->next;
                list3=list3->next;
            }
            else
            {
                list3->next=new ListNode(list2->val);
                list2=list2->next;
                list3=list3->next;
            }
        }

        while(list1)
        {
            list3->next=new ListNode(list1->val);
            list1=list1->next;
            list3=list3->next;
        }
        while(list2)
        {
            list3->next=new ListNode(list2->val);
            list2=list2->next;
            list3=list3->next;
        }
        return newhead->next;
    }
};

//Approach - 2
//Time Complexity: O(n1+n2)
//Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val>list2->val)
        {
            ListNode* temp=list1;
            list1=list2;
            list2=temp;
        }
        ListNode* newhead=list1;
        ListNode* rhead=newhead;
        while(list1&&list2)
        { 
            while(list1&&list1->val<=list2->val)
            {
                newhead=list1;
                list1=list1->next;
            }
            newhead->next=list2;
            ListNode* temp=list1;
            list1=list2;
            list2=temp;
        }
        return rhead;
    }
};