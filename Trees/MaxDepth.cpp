#include<iostream>
#include<queue>
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
// Recursive Version
int Depth(Node* root){
    if(root == NULL) return 0;
    int lh = Depth(root -> left);
    int rh = Depth(root -> right);

    return 1 + max(lh,rh);
}

// Iterative version
int MaxDepth(Node* root){
    int depth = 0;
    if(root == NULL) return depth;
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        depth++;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if(temp -> left != NULL) q.push(temp->left);
            if(temp -> right != NULL) q.push(temp->right);
        }
    }
    return depth;
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> left ->left = new Node(5);
    root -> right -> right = new Node(6);

    cout<< Depth(root) << endl;
    cout<< MaxDepth(root) <<endl;

}