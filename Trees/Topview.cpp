#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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

vector<int> TopView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int>mpp;
    queue<pair<Node*, int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* temp = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()){
            mpp[line] = temp->data;
        }
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});       //T.C = O(nlogn);, S.C = O(n);
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;

}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right = new Node(5);
    root -> right ->left = new Node(6);
    root -> right -> right = new Node(7);
    vector<int> res = TopView(root);
    for(auto it : res){
        cout<< it << " " ;
    }

}