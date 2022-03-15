#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}
bool isBalanced(Node* root){
    if(root == NULL) return true;
    else{
        int lh = height(root -> left);   // T.C = O(N2),S.C = O(N);
        int rh = height(root -> right);
        int diff = abs(lh - rh);
        return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}


//Optimum solution
int dfsheight(Node* root){
    if(root == NULL) return 0;

    int lh = dfsheight(root -> left);
    if(lh == -1) return -1;
    int rh = dfsheight(root -> right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;       // T.C = O(N), S.C = O(N);

    return 1 + max(lh , rh);
}

bool isbalanced(Node* root){
    return dfsheight(root) != -1;
}

int main(){
    Node* root = new Node(3);
    root -> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> left = new Node(7);

    cout << isBalanced(root) <<endl;
    cout << isbalanced(root) <<endl;
}