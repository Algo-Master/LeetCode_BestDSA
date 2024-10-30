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
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* curr = head;
        ListNode* nextNode = curr->next;

        while(nextNode != nullptr) {
            
            ListNode* temp = nextNode->next;
            nextNode->next = curr;

            curr = nextNode;
            nextNode = temp;
        }
        head->next = nullptr;

        return curr;
    }
};