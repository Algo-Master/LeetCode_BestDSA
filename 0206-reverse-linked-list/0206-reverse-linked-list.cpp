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
    ListNode* reverse(ListNode* curr, ListNode* nextNode) {

        if (nextNode == nullptr) {
            return curr;
        }

        ListNode* temp = nextNode->next;
        nextNode->next = curr;

        return reverse(nextNode, temp);
    }

    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* curr = head;
        ListNode* nextNode = curr->next;

        head->next = nullptr;
        return reverse(curr, nextNode);
    }
};