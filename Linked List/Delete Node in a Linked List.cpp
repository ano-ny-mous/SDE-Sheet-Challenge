//Approach - 1
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=NULL;
        while(node&&node->next)
        {
            prev=node;
            swap(node->val,node->next->val);
            node=node->next;
        }
        prev->next=NULL;
    }
};

//Approach - 2
//Time Complexity: O(1)
//Space Complexity: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};