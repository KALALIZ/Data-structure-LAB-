//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

struct Node
{
    int item;
    struct Node*left, *right;
};
struct Node*root;
struct Node*NewNode(int data)
{
    Node*new_node;
    new_node = new Node;
    new_node->item = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return(new_node);
}

struct Node*insert_New_Node(Node*root, Node*new_node)
{
    Node*p, *previous;
    if(root == NULL) 
    {
        root = new_node;
    }
    else
    {
        p = root;
        while(p != NULL)
        {
            previous = p;
            if(p->item > new_node -> item)
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


struct Node*FindMin(Node* root)
{
    while(root -> left != NULL)
    {
        root = root -> left;
    }
    return root;
}


void deleteNode(int k, Node*root)
{
    bool found = false;
    Node*cur = root, *pre = NULL;
    if(cur == NULL)
    {
        cout << "no" << endl;
        return;
    }
    while(cur != NULL)
    {
        if(cur -> item == k)
        {
            found = true;
            break;
        }
        else
        {
            pre = cur;
            if(k > cur -> item)
            {
                cur = cur -> right;
            }
            else
            {
                cur = cur -> left;
            }
        }
    }
    if(!found)
    {
        cout << "no" << endl;
        return;
    }
    //case 2
    if((cur -> left == NULL && cur -> right != NULL) || (cur -> left != NULL && cur -> right == NULL))
    {
        if(cur -> left == NULL && cur -> right != NULL)
        {
            if(pre == NULL)
            {
                cout << "yes" << endl;
                cur -> item = cur -> right -> item;
                cur -> right = NULL;
            }
            else if(pre -> left == cur)
            {
                pre -> left = cur -> right;
                cout << "yes" << endl;
                delete cur;
                cur = NULL;
            }
            else
            {
                pre -> right = cur -> right;
                cout << "yes" << endl;
                delete cur;
                cur = NULL;
            }

        }
        else
        {
            if(pre == NULL)
            {
                cout << "yes" << endl;
                cur -> item = cur -> left -> item;
                cur -> left = NULL;
            }
            else if(pre -> left == cur)
            {
                pre -> left = cur -> left;
                cout << "yes" << endl;
                delete cur;
                cur = NULL;
            }
            else
            {
                pre -> right = cur -> left;
                cout << "yes" << endl;
                delete cur;
                cur = NULL;
            }
        }
        return;
    }
    //case 1
    if(cur -> left == NULL && cur -> right == NULL)
    {
        if(pre == NULL)
        {
            root = NULL;
        }
        else if(pre -> left == cur)
        {
            pre -> left = NULL;
        }
        else
        {
            pre -> right = NULL;
        }
        cout << "yes" << endl;
        delete cur;
        return;
    }
    //case 3
    if(cur -> left != NULL && cur -> right != NULL)
    {
        Node*check = cur -> right;
        if(cur -> left == NULL && cur -> right == NULL)
        {
            cur = check;
            cout << "yes" << endl;
            delete check;
            cur -> right == NULL;
        }
        else
        {
            if(cur -> right -> left != NULL)
            {
                Node* leftCur;
                Node* leftCurPre;
                leftCurPre = cur -> right;
                leftCur = cur -> right -> left;

                while(leftCur -> left != NULL)
                {
                    leftCurPre = leftCur;
                    leftCur = leftCur -> left;
                }
                cur -> item = leftCur -> item;
                leftCurPre -> left = leftCur -> right;
                cout << "yes" << endl;
            }
            else
            {
                Node*temp = cur -> right;
                cur -> item  = temp -> item;
                cur -> right = temp -> right;
                cout << "yes" << endl;
                delete temp;

            }
        }
        return;
    }
}


void showleft(Node*root)
{
    cout << root -> item << " ";
    if(root -> left !=NULL)
    {
        showleft(root -> left);
    }
}


void showright(Node*root)
{
    cout << root -> item << " ";
    if(root -> right !=NULL)
    {
        showright(root -> right);
    }
}


void showLeaf(Node*root)
{
    if(root -> left == NULL && root -> right == NULL)
    {
        cout << root -> item << " ";
    }
    if(root -> left !=NULL)
    {
        showLeaf(root -> left);
    }
    if(root -> right !=NULL)
    {
        showLeaf(root -> right);
    }
}


int main()
{
    int operation, item, data;
    Node*ptr;
    while(operation != 4)
    {
        cin >> operation;
        if(operation == 1)
        {
            cin >> item;
            ptr = NewNode(item);
            root = insert_New_Node(root, ptr);
        }
        if(operation == 2)
        {
            cin >> data;
            deleteNode(data, root);
        }
        if(operation == 3)
        {
            showleft(root);
            cout << endl;
            showright(root);
            cout << endl;
            showLeaf(root);
            cout << endl;

        }
    }
}
