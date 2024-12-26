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
    ListNode* merge_lists(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        if (l1->val < l2->val) {
            head = curr = l1;
            l1 = l1->next;
        } else {
            head = curr = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            curr->next = l1;
        } else if (l2) {
            curr->next = l2;
        }

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();

        if(n == 0) return nullptr;
        else if(n == 1) return lists[0];

        ListNode* curr_list = merge_lists(lists[0], lists[1]);
        for(int i = 2; i < n; i++) {
            curr_list = merge_lists(curr_list, lists[i]);
        }

        return curr_list;
    }
};