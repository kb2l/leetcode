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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!k) return head;
        
        ListNode* old_head = head;
        ListNode* current = head;
        int size = 0;
        while(current) {
            ++size;
            current = current->next;
        }
        cout << size << endl;
        if(k == size || size == 1) return head;
        
        k = k % size;
        if(!k) return head;
        
        int i = 1;
        current = old_head;
        while(i < size - k && current){
            current = current->next;
            i++;
        }
        ListNode* new_head = current->next;
        current->next = nullptr;
        current = new_head;
        if(!current) return old_head;
        
        while(current->next){
            current = current->next;
        }
        current->next = old_head;
        return new_head;
    }
};