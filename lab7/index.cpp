#include <cstddef>
#include <iostream>
using namespace std;

struct treeNode 
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data;
};

bool check(treeNode* root, int x)
{
    if (root == NULL)
        return false;
    else if (x == root->data)
        return true;
    else if (root->data < x)
        return check(root->left, x);
    else
        return check(root->right, x);
    
    }

void insert(treeNode* &root, int d)
{   
    treeNode* curr = root;
    if (NULL == curr)
    {
        cout<<"before adding"<<endl;
        curr = new treeNode;
        curr->data = d;
        cout<<"added"<<endl;
    }
    else
    if (root->data < d)
    {
         insert(curr->left, d);
          cout<<"left"<<endl;    
        }
    else
         {insert(curr->right, d);
         cout<<"left"<<endl;
}
}

void inorder(treeNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }

}

int main()
{
    treeNode* root=NULL;
    insert(root, 45);
    insert(root, 5);
    insert(root, 4);
    insert(root, 7);
    insert(root, 45);
    insert(root, 17);
    inorder(root);
    cout << (check(root, 45)? "exist\n": "doesn't exist\n");
    return 0;
}