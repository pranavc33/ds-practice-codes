#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *
buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << "Inorder traversal" << endl;
    inorder(root);

    return 0;
}