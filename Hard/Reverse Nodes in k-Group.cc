class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *prehead = new ListNode(1);
        prehead->next = head;
        ListNode *pre = prehead,*end =prehead,*start,*next;
        while(1){
            for(int i = 0; i < k && end != nullptr; i++) end = end->next;
            if(!end) break;
            start = pre->next;
            next = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return prehead->next;
    }
private:
    ListNode* reverse(ListNode *head){
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while(curr){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

};
