//Approach - 1
//Time Complexity: O(n) + O(n)
//Space Complexity: O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* ,Node*> mp;
        Node* nodes=head;
        Node* addr=head;
        while(nodes)
        {
            mp[nodes]=new Node(nodes->val);
            nodes=nodes->next;
        }

        for(auto &ele:mp)
        {
            if(ele.first)
            {
                ele.second->next=mp[ele.first->next];
            }
            if(ele.first)
            {
                ele.second->random=mp[ele.first->random];
            }
        }
        return mp[head];
    }
};

//Approach - 2
//Time Complexity: O(n) + O(n) + O(n) ~ O(n)
//Space Complexity: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        while(cur)
        {
            Node* dummy=new Node(cur->val);
            Node* addr=cur->next;
            cur->next=dummy;
            dummy->next=addr;
            cur=addr;
        }

        Node* ele=head;
        while(ele)
        {
            if(ele->random)
            ele->next->random=ele->random->next;
            ele=ele->next->next;
        }
        Node* dummy=new Node(0);
        Node* newhead=dummy;
        Node* item=head;
        Node* front=head;
        while(item)
        {
            if(front&&front->next)
            front=front->next->next;
            dummy->next=item->next;
            dummy=dummy->next;
            item->next=front;
            item=item->next;
        }
        return newhead->next;
    }
};