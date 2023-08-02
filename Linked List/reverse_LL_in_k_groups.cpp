#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
 


int countnodes(Node *head){
    int count=0;
    while(head){
        head=head->next;
        count++;
    }
    return count;
}

Node *head=NULL;

Node* kReverse(Node* head, int k) {
    // Write your code here.

    if(head==NULL || k==1){
        return head;
    }
    
    int c=countnodes(head);
    
    Node *dummy=new Node(0);
    dummy->next=head;
    Node *prev=dummy,*curr=dummy,*nex=dummy;
    
    while(c>=k){
        curr=prev->next;
        nex=curr->next;
        for(int i=1;i<k;i++){
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }

        prev=curr;
        c-=k;
    }

    return dummy->next;
    
}

void insert(int n){
    if(head==NULL){
        head=(struct Node *)malloc(sizeof(struct Node));
        head->data=n;
        head->next=NULL;
    }
    else{
        struct Node *q=(struct Node *)malloc(sizeof(struct Node));
        struct Node *p=head;
        while(p->next){
            p=p->next;
        }
        q->data=n;
        q->next=NULL;
        p->next=q;
    }
}

void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    Node *p=kReverse(head,2);

    display(p);
return 0;
}