#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:

    void func1(Node *root,vector<int> &ans){
        if(root){
            func1(root->left,ans);
            ans.push_back(root->data);
            func1(root->right,ans);
        }
    }
    void func2(Node *root,vector<int> &ans){
        if(root){
            ans.push_back(root->data);
            func2(root->left,ans);
            func2(root->right,ans);
        }
    }
    void func3(Node *root,vector<int> &ans){
        if(root){
            func3(root->left,ans);
            func3(root->right,ans);
            ans.push_back(root->data);
        }
    }
    vector<int> inorder(Node* root) {
        
        vector<int> ans;
        func1(root,ans);
        return ans;    
    }

    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        func2(root,ans);
        return ans;    
    }

    vector<int> postorder(Node* root) {
        
        vector<int> ans;
        func3(root,ans);
        return ans;    
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res1 = ob.inorder(root);
        cout<<"Inorder traversal: ";
        for (int i = 0; i < res1.size(); i++) cout << res1[i] << " ";
        cout << endl;

        vector<int> res2 = ob.preorder(root);
        cout<<"Preorder traversal: ";
        for (int i = 0; i < res2.size(); i++) cout << res2[i] << " ";
        cout << endl;

        vector<int> res3 = ob.postorder(root);
        cout<<"Postorder traversal: ";
        for (int i = 0; i < res3.size(); i++) cout << res3[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends