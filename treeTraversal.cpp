#include<iostream>
#include<queue>
using namespace std;

struct Node {
        int data;
        struct Node *left;
        struct Node *right;
};

void preOrderTrav(struct Node *root) {
        if(!root)
          return;

        cout<<root->data<<" ";
        preOrderTrav(root->left);
        preOrderTrav(root->right);
}

void inOrderTrav(Node *root) {
        if(!root)
          return;

        inOrderTrav(root->left);
        cout<<root->data<<" ";
        inOrderTrav(root->right);
}

void postOrderTrav(Node *root) {
        if(!root)
          return;

        postOrderTrav(root->left);
        postOrderTrav(root->right);
        cout<<root->data<<" ";
}

Node* insertNode(Node *root,int data) {
        if(!root) {
                root = new Node();
                root->data = data;
                root->left = root->right = NULL;
        }
        else if(data <= root->data)
                root->left = insertNode(root->left,data);
        else
                root->right = insertNode(root->right,data);
        return root;
}


void BFS(Node *root)
{
        queue<Node*> q1;
        q1.push(root);
        queue<Node*> q2;
        do{
                while(!q1.empty())
                {
                   Node* tmp=q1.front();
                   cout<<tmp->data<<" ";
                   q1.pop();
                   if(tmp->left)
                           q2.push(tmp->left);
                   if(tmp->right)
                           q2.push(tmp->right);
                }
                q1=q2;
                q2=queue<Node*>();

        }while(!q1.empty());
}

int main() {

        cout<<""
<<"        12"<<endl
<<"      /     \\"<<endl
<<"   4          15"<<endl
<<"  / \\        /  \\"<<endl
<<"1     9      13   18"<<endl
<<"     /\\           \\"<<endl
<<"     8   11         38"<<endl
<<"                   / \\"<<endl
<<"                 23    98"<<endl
                      <<endl;
        Node* root = NULL;
        root = insertNode(root,12);
        root = insertNode(root,15);
        root = insertNode(root,4);
        root = insertNode(root,18);
        root = insertNode(root,1);
        root = insertNode(root,9);
        root = insertNode(root,38);
        root = insertNode(root,13);
        root = insertNode(root,98);
        root = insertNode(root,11);
        root = insertNode(root,23);
        root = insertNode(root,8);

        cout<<"*********** tree traversal **********"<<endl<<endl;
        cout<<"     DFS     ";
        cout<<endl<<"preOrderTrav: ";
        preOrderTrav(root);
        cout<<endl<<"inOrderTrav: ";
        inOrderTrav(root);
        cout<<endl<<"postOrderTrav: ";
        postOrderTrav(root);
        cout<<endl<<"     BFS     "<<endl;
        BFS(root);
}
