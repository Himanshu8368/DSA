#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(0), left(nullptr), right(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Node {
     int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

void pre_order(Node* node){
    // root , left,right
    if(node == nullptr){
        return ;
    }
    cout<<node->data<<endl;
    pre_order(node->left);
    pre_order(node->right);

}

void in_order(Node* node){
    //  left, root,right
    if(node == nullptr){
        return ;
    }
    in_order(node->left);
    cout<<node->data<<endl;
    in_order(node->right);

}

void post_order(Node* node){
    //  left,right, root
    if(node == nullptr){
        return ;
    }
    post_order(node->left);
    post_order(node->right);
    cout<<node->data<<endl;

}

vector<vector<int>> levelorder(Node * root){
    vector<vector<int>> arr;
    if(root == NULL){
        return arr;
    }
    queue<Node* > q;
    q.push(root);
    while(! q.empty()){
        int size = q.size();
        vector<int> level ;
        for(int i=0;i<size;i++){
            Node * node = q.front();
            q.pop();
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        arr.push_back(level);
    }
    return arr;
    
}

void preorder_stack(vector<int>& arr ,Node* root){
        //root ,left,right
        if(root == nullptr){
            return ;
        }
        stack<Node *> s;
        s.push(root);
        while(!s.empty()){
            Node * node = s.top();
            s.pop();
            // we use stack ,thats why we use right before left.
            if(node->right !=NULL){
                s.push(node->right);
            }
            if(node->left !=NULL){
                s.push(node->left);
            }
            arr.push_back(node->data);
        }
}



int main(){
    cout<<"hello"<<endl;
    return 0;
}




