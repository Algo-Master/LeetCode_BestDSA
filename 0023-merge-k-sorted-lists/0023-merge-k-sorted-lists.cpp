/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */
class Solution {
public:
    ListNode* merge_lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        if (l1->val < l2->val) {
            head = tail = l1;
            l1 = l1->next;
        } else {
            head = tail = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            tail->next = l1;
        } else if (l2) {
            tail->next = l2;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0) return nullptr;
        if (n == 1) return lists[0];

        ListNode* mergedList = lists[0];
        for (int i = 1; i < n; ++i) {
            mergedList = merge_lists(mergedList, lists[i]);
        }
        return mergedList;
    }
};