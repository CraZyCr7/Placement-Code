#include <iostream>
#include<vector>
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

bool getPath(Node* root , int x, vector<int>& ans){
    if(root == NULL) return false;

    ans.push_back(root -> data);
    if(root -> data == x) return true;
    if(getPath(root -> left, x,ans)|| getPath(root -> right, x, ans)){
        return true;
    }
    ans.pop_back();
    return false;

}

vector<int> Nodetopath(Node* root , int x){
    vector<int> ans;
    if(!root) return ans;
    getPath(root, x,ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(3);
    root -> left -> right -> left = new Node(6);
    root -> left -> right -> right = new Node(7);
    int x;
    cout << "Enter the path: " << " ";
    cin>> x;

    vector<int> Solve = Nodetopath(root, x);
    for(auto it: Solve){
        cout << it << " ";
    }
}