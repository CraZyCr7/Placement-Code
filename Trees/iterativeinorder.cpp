#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

vector<int> Inorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node* > st;
    Node* node = root;
    while(true){
        if(node!= NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node= node->right;
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int > res = Inorder(root);
    for(auto it : res){
        cout << it << " ";
    }
}