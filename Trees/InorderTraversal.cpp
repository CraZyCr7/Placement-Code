#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void print(int x);
void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left);
    print(root->data);
    inorder(root->right);
}
void print(int x){
    cout<<x << " ";
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    inorder(root);
}