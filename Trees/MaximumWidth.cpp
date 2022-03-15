#include <iostream>
#include<queue>
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

int WidthofBt(Node* root){
    if(root == NULL) return 0;
    int width = 0;
    queue<pair<Node* , long int >> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int currmin = q.front().second;
        int first = 0;
        int last = 0;
        for(int i=0;i<size;i++){
            Node* temp = q.front().first;
            int id = q.front().second - currmin;
            q.pop();
            if(i == 0) first = id;
            if(i == size - 1) last = id;
            if(temp -> left) q.push({temp -> left,2 * id + 1});
            if(temp -> right) q.push({temp -> right,2 * id + 2});
        }
        width = max(width , last - first + 1);
    }
    return width;
}
int main(){
    Node* root = new Node(1);
    root -> left = new Node(3);
    root -> left -> left = new Node(5);
    root -> left -> left -> left = new Node(7);
    root -> right = new Node(2);
    root -> right -> right = new Node(4);
    root -> right -> right -> right = new Node(6);

    cout << WidthofBt(root) << " ";
}