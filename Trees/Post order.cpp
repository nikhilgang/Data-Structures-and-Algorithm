#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    // TODO
}
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;
 
    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
 
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}
 
 

 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 

 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;
 
   
 
    return 0;
}