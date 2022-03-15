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
int path(Node* root, int& pathsum){
    if(root == NULL) return 0;
    int lh = max(0,path(root->left,pathsum));
    int rh = max(0,path(root->right,pathsum));

    pathsum = max(pathsum , lh + rh + root->data);  // T.C = O(N), S.C = O(N);

    return root -> data + max(lh,rh);
}
int maxpathsum(Node* root){
    int pathsum = INT32_MIN;
    path(root,pathsum);
    return pathsum;

}

int main(){
    Node* root = new Node(-10);
    root-> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);

    cout << maxpathsum(root) << endl; 
}