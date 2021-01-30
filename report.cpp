#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    try
    {
        if (n == 0)
            throw n;
        else
            cout << "n is not zero." << endl;
    }
    catch (int e)
    {
        cout << "\n";
        cout << "An exception occurred: n = " << e << endl;
        cout << "\n" << endl;
    }

    return 0;
}


