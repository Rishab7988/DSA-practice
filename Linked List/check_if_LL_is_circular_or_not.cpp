#include <bits/stdc++.h> 

// Following is the structure of class Node:
     
class Node{
public:
    int data;
    Node* next;
            
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
            
};


bool isCircular(Node* head){
    // Write your code here.
    if(head==NULL){
        return true;
    }

    Node *p=head;
    Node *q=head;
    
    while(q){
        q=q->next;
        if(q==NULL){
            break;
        }
        q=q->next;
        p=p->next;
        if(p==q){
            break;
        }
    }

    if(q==NULL){
        return false;
    }

    if(p==q){
        p=head;
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        if (p == head) {
            return true;
        }
        else{
            return false;
        }
    }
    
}


int main(){


    
    return 0;
}