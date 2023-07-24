//Approaach - 1
//Time Complexity: O(n) + O(n*k)
//Space Complexity: O(n)
class Solution {
public:
    int n;
    void rotatearray(vector<int> &res,int k)
    {
        for(int i=0;i<k;i++)
        {
            int temp=res[n-1];
            for(int j=n-1;j>0;j--)
            {
                res[j]=res[j-1];
            }
            res[0]=temp;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        vector<int> res;
        while(head)
        {
            res.push_back(head->val);
            head=head->next;
        }
        n=res.size();
        k=k%n;
        rotatearray(res,k);
        ListNode* newhead=new ListNode();
        ListNode* dummy=newhead;
        for(int j=0;j<n;j++)
        {
            newhead->next=new ListNode(res[j]);
            newhead=newhead->next;
        }
        return dummy->next;
    }
};

//Approaach - 2
//Time Complexity: O(n) + O(n*k)
//Space Complexity: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* end=head;
        ListNode* prev=NULL;
        int n=0;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        if(n==0||n==1)
        {
            return head;
        }
        if(k>n)
        {
            k=k%n;
        }
        for(int i=0;i<k;i++)
        {
            while(end&&end->next)
            {
                prev=end;
                end=end->next;
            }
            if(end)
            end->next=head;
            head=end;
            if(prev)
            prev->next=NULL;
        }
        return head;
    }
};

//Approaach - 3
//Time Complexity: O(n) + O(n-k)
//Space Complexity: O(1)
class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* link=head;
        int n=1;
        while(temp&&temp->next)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        k=n-k;
        temp->next=head;
        while(link&&--k)
        {
            link=link->next;
        }
        ListNode* newhead=link->next;
        link->next=NULL;
        return newhead;
    }
};