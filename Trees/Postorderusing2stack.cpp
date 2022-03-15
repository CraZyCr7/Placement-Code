#include<iostream>
#include<vector>
#include<stack>
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
vector<int> Postorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp -> left !=NULL) st1.push(temp->left);
        if(temp -> right !=NULL) st1.push(temp->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> res = Postorder(root);
    for(auto it : res){
        cout<< it << " ";
    }
}