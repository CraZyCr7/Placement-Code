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

vector<int> Postorder(Node* curr){
    vector<int> ans;
    if(curr == NULL) return ans;
    stack<Node* > st;
    while(curr!=NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }else{
                curr = temp;
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> left -> right = new Node(4); 
    root -> left -> left -> right -> right = new Node(5); 
    root -> left -> left -> right -> right -> right = new Node(6);
    root -> right = new Node(7);
    root -> right ->left = new Node(8);

    vector<int> res = Postorder(root); 

    for(int i = 0; i< res.size();i++){
        cout << res[i] << " ";

    }
}