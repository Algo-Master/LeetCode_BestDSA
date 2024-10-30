/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == nullptr) return 0;

        ListNode* curr = head;
        unordered_map<ListNode*, bool> m;

        while(curr != nullptr) {

            if(m[curr]) return 1;
            else m[curr] = true;

            curr = curr->next;
        }
        return 0;
    }
};