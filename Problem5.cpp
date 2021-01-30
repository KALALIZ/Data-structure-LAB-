//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

struct Node{

    int item;
    struct Node*next;

};

struct Node*front = NULL;
struct Node*back = NULL;

void enqueue(int newItem)
{
    Node *newNode = new Node;
    newNode -> item = newItem;
    newNode -> next = NULL;
    if(front == NULL)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back -> next = newNode;
        back = back -> next;
    }

}

void dequeue()
{
    if(front != NULL)
    {
        cout << front -> item << endl;
        front = front -> next;
    }
    else
    {
        cout << "no" << endl;
    }
}
void getFront()
{
    if(front != NULL)
    {
        cout << front -> item << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

void clearQueue()
{
    Node*cur = front;
    while(cur != NULL)
    {
        cout << cur -> item << " ";
        cur = cur -> next;
    }

    if(front == NULL)
    {
        cout << "no";
    }
    cout << endl;
    front = NULL; 
    back = front;
}

int size()
{
    Node*cur = front;
    int count = 0;

    while(cur != NULL)
    {
        count++;
        cur = cur -> next;
    }

    return count;
}

void isEmpty()
{
    if(front == NULL)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

}

int main(){
    int operation, newItem;
    do{
        cin >> operation;
        if(operation == 1)
        {
            cin >> newItem;
            enqueue(newItem);
        }
        else if(operation == 2)
        {
            dequeue();
        }
        else if(operation == 3)
        {
            getFront();
        }
        else if(operation == 4)
        {
            clearQueue();
        }
        else if(operation == 5)
        {
            cout << size() << endl;
        }
        else if(operation == 6)
        {
            isEmpty();
        }

    }
    while(operation != 7);
}