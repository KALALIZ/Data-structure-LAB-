//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

struct Node{
    int coefficient;  
    int exponent;   
    struct Node*next = NULL;
};
struct Node*head = new Node;
struct Node*cur;

void sort(int coefficient, int exponent)
{
    Node*newPtr = new Node;
    newPtr -> coefficient = coefficient;
    newPtr -> exponent = exponent;
    cur = head -> next;
    if(cur == NULL or newPtr -> exponent > cur -> exponent)
    {
        newPtr -> next = cur;
        head -> next = newPtr;
    }
    else
    {
        while(true)
        {
            if(cur -> next == NULL)
            {
                cur -> next = newPtr;
                newPtr -> next = NULL;
                break;
            }
            if(newPtr -> exponent > cur -> next -> exponent)
            {
                newPtr -> next = cur -> next;
                cur -> next = newPtr;
                break;
            }
            cur = cur -> next;
        }

    }
}

void inputF1(int num)
{
    for(int i=0; i<num ;i++)
    {
        int coefficient, exponent;
        cin >> coefficient >> exponent;
        sort(coefficient, exponent);
    }
}

void plusFn()
{
    int secondFn, coefficient, exponent;
    cin >> secondFn;  
    cur = head -> next; 
    for(int i=0; i<secondFn; i++)
    {
        bool check = false;
        cin >> coefficient >> exponent;
        while(true and cur != NULL)
        {
            if(exponent == cur -> exponent)
            {
                cur -> coefficient += coefficient;
                check = true;
                break;
            }
            cur = cur -> next;
        }
        if(check == false)
        {
            sort(coefficient, exponent);
        }
    }

}

void minusFn()
{ 
    int secondFn, coefficient, exponent;
    cin >> secondFn;
    cur = head -> next;
    for(int i=0; i<secondFn; i++){
        bool check = false;
        cin >> coefficient >> exponent;
        while(true and cur != NULL)
        {
            if(exponent == cur -> exponent)
            {
                cur -> coefficient -= coefficient;
                check = true;
                break;
            }
            cur = cur -> next;
        }
        coefficient = 0 - coefficient;
        if(check == false)
        {
            sort(coefficient, exponent);
        }
    }
}

void display()
{
    cur = head -> next;
    while(cur != NULL)
    {
        if(cur -> coefficient != 0)
        {
            cout << cur -> coefficient << "x^{" << cur -> exponent << "} ";
        }
        cur = cur -> next;
    }
}
int main(){
    int operater, firstFn;

    cin >> operater;
    cin >> firstFn;

    inputF1(firstFn);

    if(operater == 1)
    {
        plusFn();
    }
    else if(operater == 2)
    {
        minusFn();
    }
    display();
}
