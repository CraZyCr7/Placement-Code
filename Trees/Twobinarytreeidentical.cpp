#include<iostream>
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
// iterative 
bool isSame(Node* p , Node* q){
    queue<Node* > st; // or you can use stack also;
    st.push(p);
    st.push(q);
    while(!st.empty()){
        Node* q2 = st.front();
        st.pop();                   // T.C = O(N),S.C = o(N);
        Node* q1 = st.front();
        st.pop();

        if(q1 == NULL && q2 == NULL) continue;
        if(q1 == NULL || q2 == NULL) return false;
        if(q1->data != q2->data) return false;

        st.push(q1->left);
        st.push(q2->left);
        st.push(q1->right);
        st.push(q2->right);
    }
    return true;
}

//Recursive
bool issame(Node* p, Node* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    if(p->data != q->data) return false;   // T.C = O(N), S.C = O(N);
    return issame(p->left,q->left) && issame(p->right,q->right);
}


int main(){
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    p->right->left = new Node(4);
    p->right->right = new Node(5);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->right->left = new Node(4);
    q->right->right = new Node(5);

    cout<< isSame(p,q) << endl;
    cout<< issame(p,q) << endl;
}