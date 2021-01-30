//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

int lastindex = -1;
int array[100] = {};

void restore()
{
    int index = lastindex;
    while(index != 0)
    {
        if(array[index] < array[(index-1)/2])
        {
            int temp = array[index];
            array[index] = array[(index -1)/2];
            array[(index -1)/2] = temp;
        }
        index = (index-1)/2;
    }
}

//Operation 1
bool isEmpty()
{
    if(lastindex == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//Operation 2
void size()
{
    cout << lastindex + 1 << endl;
}

//Operation 3
void min()
{
    if(not isEmpty()) 
    {
        cout << array[0] << endl;
    }
    else 
    {
        cout << "no" << endl;
    }
}

//Operation 4
void insert(int item)
{
    if(lastindex == -1)
    {
        lastindex ++;
        array[lastindex] = item;
    }
    else
    {
        lastindex ++;
        array[lastindex] = item;
        int index = lastindex;
        restore();
    }
}

//Operation 5
void removeMin(int i)
{
    int lchild, rchild, smallest;
    lchild = 2*i+1;
    rchild = 2*i+2;
    if(lchild <= lastindex && array[lchild] < array[i])
    {
        smallest = lchild;
    }
    else
    {
        smallest = i;
    }
    if(rchild <= lastindex && array[rchild] < array[smallest])
    {
        smallest = rchild;
    }
    if(smallest != i)
    {
        int temp;
        temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        removeMin(smallest);
    }
}

//Operation 6
void showPriorityQueue()
{
    int index = lastindex;
    if(lastindex > -1)
    {
        for(int i = 0; i <= index; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

//Operation 7
void parent(int i)
{
    if(i > 0 and i <= lastindex)
    {
        int search = (i-1)/2;
        cout << array[search] << endl;
    }
    else 
    {
        cout << "no" << endl;
    }
}

//Operation 8
void leftChild(int i)
{
    if(2*i+1 <= lastindex && i > 0)
    {
        cout << array[2*i+1] << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

//Operation 9
void rightChild(int i)
{
    if(2*i+2 <= lastindex && i > 0)
    {
        cout << array[2*i+2] << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}


int main()
{
    int operation, input;

    while(operation != 10)
    {
        cin >> operation;
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
            size();
        }
        if(operation == 3)
        {
            min();
        }
        if(operation == 4)
        {
            int item;
            cin >> item;
            insert(item);
        }
        if(operation == 5)
        {
            if(lastindex >= 0)
            {
                array[0] = array[lastindex];
                lastindex --;
                removeMin(0);
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        if(operation == 6)
        {
            showPriorityQueue();
        }
        if(operation == 7)
        {
            cin >> input;
            parent(input);
        }
        if(operation == 8)
        {
            cin >> input;
            leftChild(input);
        }
        if(operation == 9)
        {
            cin >> input;
            rightChild(input);
        }
    }
}
