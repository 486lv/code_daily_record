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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* first=new ListNode();
        ListNode* curr=first;
        int cnt=0;
        for(auto i=head;i!= nullptr;i=i->next){
            int x=i->val;
            if(x==0&&cnt==0){
               cnt=0;
                continue;
            }
            else if(x==0&&cnt!=0){
                curr->next=new ListNode(cnt);
                curr=curr->next;
                cnt=0;
            }
            else{
                cnt+=x;
            }
        }
        return first->next;
    }
};
