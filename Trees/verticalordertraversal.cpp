#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>


using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

vector<vector<int>> verticalOrder(Node* root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(temp->data);
        if(temp->left) todo.push({temp -> left,{x-1,y+1}});        // T.C = O(NlogN), S.C = O(N);
        if(temp->right) todo.push({temp -> right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto it : nodes){
        vector<int> v;
        for(auto t : it.second){
            for(auto x : t.second){
                v.push_back(x);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(10);
    root -> left -> left -> right = new Node(5);
    root -> left -> left -> right -> right = new Node(6);
    root -> right = new Node(3);
    root -> right -> left = new Node(9);
    root -> right -> right = new Node(10);

    vector<vector<int>> res = verticalOrder(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }

}