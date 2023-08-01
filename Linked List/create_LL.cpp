#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
    struct node *next;
    int data;
};

struct node *head=NULL;

void insert(int n){
    if(head==NULL){
        head=(struct node *)malloc(sizeof(struct node));
        head->data=n;
        head->next=NULL;
    }
    else{
        struct node *q=(struct node *)malloc(sizeof(struct node));
        struct node *p=head;
        while(p->next){
            p=p->next;
        }
        q->data=n;
        q->next=NULL;
        p->next=q;
    }
}

void display(struct node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    int arr[5]={3,2,1,4,5};
    for(int i=0;i<5;i++){
        insert(arr[i]);
    }
    display(head);
return 0;
}