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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans;
        ListNode* tail = &ans;int carry =0;
        while(l1 || l2 || carry){
            
            int sum =0;
            int total = (l1 ? l1->val:0) + (l2 ? l2->val:0)+ carry;
            {
                carry = total/10;
            } sum = total %10;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail = tail->next;
            if(l1) l1 = l1->next;                  
            if(l2) l2 = l2->next;
        }
        return ans.next;
    }
};