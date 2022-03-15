#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

vector<int> Preorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node* > st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> res = Preorder(root);
    for(auto it: res){
        cout << it << " ";
    }

}