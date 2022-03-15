// Zig- Zag or Spiral Traversal;
#include<iostream>
#include<vector>
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

vector<vector<int>> SpiralTraversal(Node* root){
    vector<vector<int>> ans;
    queue<Node* > q;
    q.push(root);
    bool leftright = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            int index = leftright ? i : (size - 1 - i);

            row[index] = temp->data;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        leftright = !leftright;
        ans.push_back(row);
    }
    return ans;
}
int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(6);

    vector<vector<int>> res = SpiralTraversal(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }

}