 ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode prehead(0),*cur;
        cur = &prehead;
        priority_queue<P, vector<P>, mycmp> tmp;
        for(int i =0;i<lists.size();i++){
            if (lists[i]) tmp.push({lists[i]->val,i});
        }
        while(!tmp.empty()){
            auto it = tmp.top();
            tmp.pop();
            cur->next = lists[it.second];
            cur = cur->next;
            lists[it.second] = lists[it.second]->next;
            if(lists[it.second]) tmp.push({lists[it.second]->val,it.second});
        }
        return prehead.next;
    }
    struct mycmp{
        bool operator()(const P & a,const P & b){
            return a.first > b.first;
        }
    };
