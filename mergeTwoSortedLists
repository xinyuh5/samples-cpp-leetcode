/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }else if (l2 == NULL){
            return l1;
        }else if (l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
    }
};*/
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* prehead = new ListNode(-1);
        ListNode* prev = prehead;
        while (l1!=NULL and l2!=NULL){
            if (l1->val <= l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == NULL? l2 : l1;
        ListNode* r = prehead->next;
        delete prehead;
        return r;
    }
};
