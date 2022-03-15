#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

};

vector<vector<int>>Levelorder(Node* root){
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(root->left);
            if(temp->right != NULL) q.push(root->right);
            level.push_back(temp->data);
        }
        res.push_back(level);
    }
    return res;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<vector<int>> ans = Levelorder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }

}