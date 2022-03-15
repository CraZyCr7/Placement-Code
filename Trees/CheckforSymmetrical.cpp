#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

    // Recursion
bool isSymmetrictest(Node* p, Node* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if(p -> data != q -> data) return false;
    return isSymmetrictest(p -> left , q -> right) && isSymmetrictest(p -> right , q -> left);
}

bool isSymmetric(Node* root){
    if(root == NULL) return true;
    return isSymmetrictest(root->left,root->right);
}

bool isSymmetrictest1(Node* p, Node* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;                            //T.C -> O(N)
    if(p -> data != q -> data) return false;                            //S.C -> O(N)
    return isSymmetrictest(p -> left , q -> right) && isSymmetrictest(p -> right , q -> left);
}

bool isSymmetric1(Node* root1){
    if(root1 == NULL) return true;
    return isSymmetrictest1(root1->left,root1->right);
}

    //Iterative 
bool IsSymmetric(Node* root){
    if(!root) return true;
    queue<Node*> q;
    q.push(root -> left);
    q.push(root -> right);
    while(!q.empty()){
        Node* _left = q.front();
        q.pop();
        Node* _right = q.front();
        q.pop();

        if( _left == NULL && _right == NULL) continue;                  //T.C -> O(N)
        if( _left == NULL || _right == NULL) return false;              //S.C -> O(N)
        if( _left -> data != _right -> data) return false;
        q.push(_left -> left);
        q.push(_right -> right);
        q.push(_left -> right);
        q.push(_right -> left);
    }
    return true;
}

bool IsSymmetric1(Node* root){
    if(!root) return true;
    queue<Node*> q;
    q.push(root -> left);
    q.push(root -> right);
    while(!q.empty()){
        Node* _left = q.front();
        q.pop();
        Node* _right = q.front();
        q.pop();

        if( _left == NULL && _right == NULL) continue;
        if( _left == NULL || _right == NULL) return false;
        if( _left -> data != _right -> data) return false;
        q.push(_left -> left);
        q.push(_right -> right);
        q.push(_left -> right);
        q.push(_right -> left);
    }
    return true;
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(3);

    Node* root1 = new Node(1);
    root1 -> left = new Node(2);
    root1 -> left ->right = new Node(3);
    root1 -> right = new Node(2);
    root1 -> right -> right = new Node(3);

    bool ans = isSymmetric(root);
    bool ans1 = isSymmetric1(root1);
    bool res = IsSymmetric(root);
    bool res1 = IsSymmetric1(root1);

    cout << ans << endl << ans1 << endl;
    cout << res << endl << res1 << endl;
}