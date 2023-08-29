#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// CREATING TREE AND BASIC TREE TRAVERSALS

//structure of the node

struct node{
    struct node *lchild;
    struct node *rchild;
    int val;
};

//initializing root node as NULL
struct node *root=NULL;

//function to insert node in the tree
void insert(int n){
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->val=n;
        root->lchild=root->rchild=NULL;
    }
    else{
        struct node *p=root;
        struct node *q=NULL;
        while(p){
            q=p;
            if(n>=p->val){
                p=p->rchild;
            }
            else{
                p=p->lchild;
            }
        }
        p=(struct node *)malloc(sizeof(struct node));
        p->val=n;
        p->rchild=NULL;
        p->lchild=NULL;
        if(n>=q->val){
            q->rchild=p;
        }
        else{
            q->lchild=p;
        }
    }
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->val<<" ";
        inorder(p->rchild);
    }
}

void preorder(struct node *p){
    if(p){
        cout<<p->val<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    int arr[5]={5,4,1,2,3};
    for(int i=0;i<5;i++){
        insert(arr[i]);
    }

    inorder(root);
    cout<<endl;
    preorder(root);
return 0;
}