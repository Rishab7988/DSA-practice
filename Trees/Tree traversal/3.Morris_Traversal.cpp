#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

class Solution
{
    public:
    Node *getPred(Node *curr){
        Node *p=curr->left;

        while(p->right && p->right!=curr){
            p=p->right;
        }

        return p;
    }

    vector<int> MorrisTraversal(Node *node){
        
        vector<int> ans;
        Node *curr=node;

        while(curr){
            if(curr->left){
                Node *pred=getPred(curr);
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                else if(pred->right==curr){
                    pred->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }

        return ans;
    }
};



int main()
{

        Node* root = NULL;
 
        root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
 
        root->left->left = newNode(4);
        root->left->right = newNode(5);
 
        root->right->right = newNode(6);
 
        root->left->left->right = newNode(7);
 
		
		Solution ob;
        vector <int> res = ob.MorrisTraversal(root);
        cout<<"Morris Traversal: ";
        for (int i : res) cout << i << " ";
        cout << endl;
  return 0;
}



