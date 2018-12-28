class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){return head;}
         
        ListNode * l_half = getHalfNode(head); //求出中间节点：快慢指针
        return merge(sortList(head),sortList(l_half));
    }
     
/*     ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    } */
    //合并
  
    ListNode *merge(ListNode* tl,ListNode* tr)
    {
        if(!tr) return tr;
        if(!tl) return tl;
 
        ListNode * dummy = new ListNode(-1);  //虚拟节点
        ListNode * tnext = dummy;
 
        while(tl && tr)
        {
            if(tl->val > tr->val){
                tnext->next = tr; tr=tr->next;
            }else{
                tnext->next = tl; tl=tl->next;
            }
            tnext = tnext->next;
        }
        //检查左右两个链表是否有剩余部分
        if(tl){
            tnext->next = tl;
        }
        if(tr){
            tnext->next = tr;
        }
        ListNode * ret = dummy->next;
        delete dummy;
        return ret;
    }
 
/* 
   ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    } */
 
 
    ListNode * getHalfNode(ListNode* head)
    {
        if(!head || !head->next) return head;
 
        ListNode * fast=head, *slow=head, *pre=slow;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow=slow->next;
        }
        pre->next = NULL;
        return slow;
    }
 
    void print(ListNode* head)
    {
        while(head){
            cout << head->val << endl;
            head = head->next;
        }
    }
};
