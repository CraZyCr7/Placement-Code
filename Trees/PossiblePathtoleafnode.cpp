#include <iostream>
#include <vector>
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

void helper(Node* root, vector<vector<int>>& ans,vector<int> res){
    if(root == NULL) return ;
    res.push_back(root -> data);
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(res);
        return;
    }
    helper(root->left,ans,res);
    helper(root->right,ans,res);
}

vector<vector<int>> Path(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> res;
    helper(root,ans,res);
    return ans;
}

int main(){
    Node* root = new Node(10);
    root -> left = new Node(8);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(5);
    root -> right ->  left = new Node(2);

    vector<vector<int>> ans = Path(root);
    for(int i = 0 ;i< ans.size();i++){
        for(int j =0;j<ans[i].size();j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl;
    }
}