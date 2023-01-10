/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto root = head;
        stack<ListNode*> s;
        
        while(head) 
        {
            s.push(head);
            head = head->next;
        }
        
        ListNode * toremove = nullptr;
        while(n > 0)
        {
            toremove = s.top();
            s.pop();
            n--;
        }
        
        // manage root case
        if(toremove == root) return root->next;
        
        if(s.size() > 0)
        {
            auto tomodify = s.top();
            tomodify->next = toremove->next; 
            return root;
        }
        
        return nullptr;
    }
};