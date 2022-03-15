#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
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
//Recursive method
void recursion(Node* root,int level,vector<int>& ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->data);      //T.C -> O(N)
    recursion(root->right,level+1,ans);                     //S.C -> O(N)
    recursion(root->right,level+1,ans);
}
vector<int> rightSideView(Node* root){
    vector<int> ans;
    recursion(root,0,ans);
    return ans;
}

// Iterative Method
vector<int> RightSideView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size =  q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(i == size-1){
                ans.push_back(node->data);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right = new Node(5);
    root -> right ->left = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> res = rightSideView(root);
    for(auto it: res){
        cout << it << " "; 
    }cout << endl;
    vector<int> it = RightSideView(root);
    for(auto x : it){
        cout << x << " ";
    }
    return 0;
}