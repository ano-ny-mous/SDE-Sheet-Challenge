//Approach - 1
//Time Complexity: O(n1*n2)
//Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA)
        {
            ListNode *temp=headB;
            while(temp)
            {
                if(headA==temp)
                {
                    return headA;
                }
                temp=temp->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};

//Approach - 2
//Time Complexity: O(n1+n2)
//Space Complexity: O(n1+n2)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(s.find(headB)!=s.end())
            {
                return headB;
            }
            s.insert(headB);
            headB=headB->next;
        }
        return NULL;
    }
};

//Approach - 3
//Time Complexity: O(n1) + O(n1-n2) + (n2) ~ O(2*n1)
//Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        int count1=0;
        ListNode *temp2=headB;
        int count2=0;
        while(temp1)
        {
            count1++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            count2++;
            temp2=temp2->next;
        }
        int diff=abs(count1-count2);
        if(count1>count2)
        {
            while(diff--)
            {
                headA=headA->next;
            }
        }
        else
        {
            while(diff--)
            {
                headB=headB->next;
            }
        }
        while(headA&&headB)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};

//Approach - 4
//Time Complexity: O(2*n)
//Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL&&temp2==NULL)
            {
                return NULL;
            }
            if(temp1==NULL)
            {
                temp1=headB;
            }
            if(temp2==NULL)
            {
                temp2=headA;
            }
        }
        return temp1;
    }
};