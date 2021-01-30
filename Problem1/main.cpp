//Silalak Kaewjanpet 610510670 sec001
#include <iostream> 
using namespace std;

struct Node
{
    int item;
    struct Node*next;
};

struct Node*head = NULL;
struct Node*cur;


void isEmpty()
{   
    if ( head == NULL )
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }      
}  


int getSize()
{
    int count = 0;
    Node*cur = head;
    while(cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    return count;
}


void insertList(int index, int newItem)
{
    if(index >= 1 and index <= (getSize()+1))
    {
        Node*newPtr = new Node;
        newPtr->item = newItem;
        if(index == 1)
        {
            newPtr->next = head;
            head = newPtr;
        }
        else
        {
            Node*prev = new Node;
            cur = head;
            for(int i=1; i<(index-1); i++)
            {
                cur = cur->next;
            }
            prev = cur;
            newPtr->next = prev->next;
            prev->next = newPtr;
        }
        
    }
}


void removeList(int index)
{
    if(index <= getSize())
    {
        Node*cur = head;
        if(index == 1)
        {
            head = head->next;
        }
        else
        {
            Node*prev;
            for(int i=1; i<(index-1); i++)
            {
                cur = cur->next;
            }
            prev = cur;
            cur = prev->next;
            prev->next = cur->next;
        }
        
    }
    
}


int retrieveList(int index)
{
    if(index > 0 and index <= getSize())
    {
        Node*cur = head;
        for(int i=1; i<index; i++)
        {
            cur = cur->next;
        }
        cout << (cur->item) << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    
}


int findList(int pos)
{
    Node*cur = head;
    int count = 1;
    while(cur != NULL)
    {
        if(cur->item == pos)
        {
            return count;
        }
        cur = cur->next;
        count++;      
    }
    return 0;
}


void displayList()
{
    cur = head;
    while(cur != NULL)
    {
        cout << (cur->item) << " ";
        cur = cur->next;
    }
    cout << " " << endl;
}


int main()
{
    int opt;
    cin >> opt;
    do
    {
        if(opt == 1)
        {
            isEmpty();           
        }
        if(opt == 2)
        {
            cout << getSize() << endl;           
        }
        if(opt == 3)
        {
            int index, newItem;
            cin >> index;
            cin >> newItem;
            insertList(index, newItem);
        }
        if(opt == 4)
        {
            int index;
            cin >> index;
            removeList(index);
        }
        if(opt == 5)
        {
            int index;
            cin >> index;
            retrieveList(index);
        }
        if(opt == 6)
        {
            int pos;
            cin >> pos;
            int print = findList(pos);
            if(print)
            {
                cout << print << endl;
            }
            else
            {
                cout << "no" << endl;
            }
            
        }
        if(opt == 7)
        {
            displayList();
        }
        cin >> opt;
    }while(opt != 8);
}