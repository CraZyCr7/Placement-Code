#include <iostream>
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
Node* Ancestor(Node* root, int x, int y){
        if(root == NULL || root -> data == x || root -> data == y){
            return root;
        }
        Node* Left = Ancestor(root -> left , x, y);
        Node* Right = Ancestor(root -> right, x, y);

        if(Left == NULL) return Right;
        else if(Right == NULL) return Left;
        else return root;
    }


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    int p = 4;
    int q = 5;

    Node* LCA = Ancestor(root, p, q);  
    cout << LCA->data << " ";
}