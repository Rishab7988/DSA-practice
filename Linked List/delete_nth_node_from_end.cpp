#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {} 
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *p=head;
        ListNode *q=head;
        ListNode *prev=head;
        for(int i=0;i<n;i++){
            if(q){
                q=q->next;
            }
            
        }
        while(q){
            prev=p;
            p=p->next;
            q=q->next;
        }

        prev->next=p->next;
        if(p==head){
            return head->next;
        }
        
        return head;

    }
};
