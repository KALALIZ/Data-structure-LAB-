//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

struct Node 
{
    int item;
    struct Node*prev;
    struct Node*next;
};
struct Node*head = new Node;
struct Node*tail = new Node;


//Operation 1
bool isEmpty()
{   
    return (head -> next == tail);  
}

//Operation 2
int getSize()
{
    struct Node*cur = head -> next;
    int count = 0;
    while(cur != tail)
    {
        cur = cur -> next;
        count++;
    }
    return count;

}

// Operation 3
void insertFirst(int newItem)
{
    Node*newNode = new Node;
    newNode -> item = newItem;

    newNode -> next = head -> next;
    newNode -> prev = head;
    head -> next -> prev = newNode;
    head -> next = newNode;
}

// Operation 4
void insertLast(int newItem) 
{
    Node*newNode = new Node;
    newNode -> item = newItem;

    newNode -> next = tail;
    newNode -> prev = tail -> prev;
    tail -> prev -> next = newNode;
    tail -> prev = newNode;
    
}

// Opeation 5
void removeFirst()
{
    if(head -> next != tail)
    {
        head -> next -> next -> prev = head;
        head -> next = head -> next -> next;
    }
     
}

// Operation 6
void removeLast()
{
    if(tail -> prev != head)
    {
        tail -> prev -> prev -> next = tail;
        tail -> prev = tail -> prev -> prev;
    } 
}

// Operation 7
void displayList()
{
    struct Node*cur;
    cur = head -> next;
    while(cur != tail)
    {
        cout << cur -> item << " ";
        cur = cur -> next;
    }
    cout << endl;
    
}

//Operation 8
void  traverseList(int num, string step)
{
    struct Node*cur = head -> next;
    int item = 0;
    if(head -> next != tail)
    {
        for(int i=0; i<num; i++)
        {
            if(step[i] == 'L')
            {
                if(cur -> prev != head)
                {
                    cur = cur -> prev;
                }
            }
            else if(step[i] == 'R')
            {
                if(cur -> next != tail)
                {
                    cur = cur -> next;
                }
            }
        }
    item = cur -> item;
    }
    if(item != 0)
    {
        cout << item << endl;
    }
    else
    {
        cout << "no" << endl;
    }

}

int main()
{
    head -> prev = NULL;
    head -> next = tail;
    tail -> prev = head;
    tail -> next = NULL;

    int operation;
    cin >> operation;
    do
    {
        if(operation == 1)
        {
            if(isEmpty())
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
            
            
        }
        if(operation == 2)
        {
            cout << getSize() << endl;
        }
        if(operation == 3)
        {
            int newItem;
            cin >> newItem;
            insertFirst(newItem);
        }
        if(operation == 4)
        {
            int newItem;
            cin >> newItem;
            insertLast(newItem);
        }
        if(operation == 5)
        {
            removeFirst();
        }
        if(operation == 6)
        {
            removeLast();
        }
        if(operation == 7)
        {
            displayList();
        }
        if(operation == 8)
        {
            int num;
            string step = "";
            cin >> num;
            cin >> step;
            traverseList(num, step);

        }
        cin >> operation;
    }while(operation != 9);
    
    
}