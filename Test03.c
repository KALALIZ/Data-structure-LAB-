//Silalak Kaewjanpet 610510670 sec001
#include <stdio.h>

int main()
{
    int m,n,sum = 0,r,i = 0;
    scanf("%d",&m);
    scanf("\n%d",&n);
    r = n-m;
    while(i <= r)
    {
        sum += m*m;
        m++;
        i++;
    }
    printf("%d",sum);
    return 0;
}
