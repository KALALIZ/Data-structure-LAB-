//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

struct Node
{
    int item;
    struct Node*left, *right;
};
struct Node*root, *ptr;
struct Node*NewNode(int data)
{
    Node*new_node;
    new_node = new Node;
    new_node->item = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return(new_node);
}

struct Node* insert_New_Node(Node*root, Node*new_node)
{
    Node*p, *previous;
    if(root == NULL) 
    {
        root = new_node;
    }
    else
    {
        p = root;
        while(p!=NULL)
        {
            previous = p;
            if(p -> item > new_node -> item)
            {
                p = p -> left;
            }
            else
            {
                p = p -> right;
            }
        }
        if(previous -> item > new_node -> item)
        {
            previous -> left = new_node;
        }
        else 
        {
            previous -> right = new_node;
        }
    }
    return (root);
}


void inOrder(Node*root)
{
    if(root -> left != NULL)
    {
        inOrder(root -> left);
    }
    cout << root -> item << " ";

    if(root -> right != NULL)
    {
        inOrder(root -> right);
    }
}


void proOrder(Node*root)
{
    cout << root->item << " ";
    if(root -> left != NULL)
    {
        proOrder(root -> left);
    }
    if(root -> right != NULL)
    {
        proOrder(root -> right);
    }
}


void postOrder(Node*root)
{
    if(root -> left != NULL)
    {
        postOrder(root -> left);
    }
    if(root -> right != NULL)
    {
        postOrder(root -> right);
    }
    cout << root -> item << " ";
}


int main()
{
    int n, item;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> item;
        ptr = NewNode(item);
        root = insert_New_Node(root, ptr);
    }
    proOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
}
