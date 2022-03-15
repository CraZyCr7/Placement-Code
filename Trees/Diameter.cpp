#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

//Naive Approach
int height(Node*root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}
void solve(Node* root , int& ans){
    if(root == NULL) return;

    int lh = height(root->left);
    int rh = height(root->right);

    ans = max(ans,lh + rh);             // T.C = O(N2), S.C = O(N);

    solve(root->left, ans);
    solve(root->right, ans);
}
int Diameter(Node* root){
    int ans = 0;
    solve(root , ans);
    return ans;
}

//Optimum Approach
int Height(Node* root, int& dia){
    if(root == NULL) return 0;
    int lh = Height(root->left,dia);
    int rh = Height(root->right,dia);

    dia = max(dia,lh + rh);             // T.C = O(N), S.C = O(N);
    return 1 + max(lh , rh);
}
int diameter(Node* root){
    int dia = 0;
    Height(root,dia);
    return dia;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> left ->left = new Node(5);
    root -> right -> left ->left -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> right -> right -> right = new Node(8);
    root -> right -> right -> right -> right = new Node(9);

    cout << Diameter(root) <<endl;
    cout << diameter(root) <<endl;
}
