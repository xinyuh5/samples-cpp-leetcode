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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0), *curr = dummyhead;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int x = l1? l1->val : 0;
            int y = l2? l2->val : 0;
            int sum = x + y + carry;
            carry = sum/10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 ->next : l2;
        }
        if (carry > 0) {
            curr -> next = new ListNode(carry);
        }
        curr = dummyhead->next;
        delete dummyhead;
        return curr;
    }
};
