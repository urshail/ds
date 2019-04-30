#include<iostream>
#include<queue>
using namespace std;

struct Node {
        int data;
        struct Node *left;
        struct Node *right;
};

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

int max(int a,int b)
{
        return a>b?a:b;
}

int findLen(Node* root)
{
   if(!root)
           return 0;
   return 1+max( findLen(root->left), findLen(root->right) );

}

int countNodes(Node* root)
{
        if(!root)
                return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
}

int countLeaf(Node* root)
{
        static int ln;
        if(!root->left)
                return 1;

        return  countLeaf(root->left) + countLeaf(root->right);
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
        cout<<endl<<"     BFS     "<<endl;
        BFS(root);
        
        cout<<endl<<"length of tree is : ";
        cout<<findLen(root)<<endl;

        cout<<"no of nodes in tree are : "<<countNodes(root)<<endl;
        cout<<countLeaf(root)<<endl;

}
