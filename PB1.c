
#include <stdio.h> 

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
        printf("\nyes") ;
    }
    else
    {
        printf("\nno") ;
    }      
}  


int getSize()
{
    int count = 0;
    struct Node*cur = head;
    while(cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}


void insertList(int index, int newItem)
{
    if(index >= 1 && index <= (getSize()+1))
    {
        struct Node*newPtr = new Node;
        newPtr->item = newItem;
        if(index == 1)
        {
            newPtr->next = head;
            head = newPtr;
        }
        else
        {
            struct Node*prev = new Node;
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
        struct Node*cur = head;
        if(index == 1)
        {
            head = head->next;
        }
        else
        {
            struct Node*prev;
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
    if(index > 0 && index <= getSize())
    {
        struct Node*cur = head;
        for(int i=1; i<index; i++)
        {
            cur = cur->next;
        }
        printf("\n%d",cur->item);
    }
    else
    {
        printf("\nno");
    }
    
}


int findList(int pos)
{
    struct Node*cur = head;
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
        printf("\n%d",cur->item);
        cur = cur->next;
    }
}


int main()
{
    int operation;
    scanf("%d",&operation);
    while(operation != 8)
    {
        if(operation == 1)
        {
            isEmpty();           
        }
        else if(operation == 2)
        {
            printf("\n%d",getSize());           
        }
        else if(operation == 3)
        {
            int index, newItem;
            scanf("\n%d",&index);
            scanf("\n%d",&newItem);
            insertList(index, newItem);
        }
        else if(operation == 4)
        {
            int index;
            scanf("\n%d",&index);
            removeList(index);
        }
        else if(operation == 5)
        {
            int index;
            scanf("\n%d",&index);
            retrieveList(index);
        }
        else if(operation == 6)
        {
            int pos;
            scanf("\n%d",&pos);
            int print = findList(pos);
            if(print)
            {
                printf("\n%d",print);
            }
            else
            {
                printf("\nno");
            }
            
        }
        else if(operation == 7)
        {
            displayList();
        }

        scanf("\n%d",&operation);
    }
}