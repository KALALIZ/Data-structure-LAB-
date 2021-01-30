//Silalak Kaewjanpet 610510670 sec001
#include <stdio.h>

int main()
{
    int choice;
    float temp,temp0;

    scanf("%d",&choice);
    scanf("\n%f",&temp);

    if(choice == 1) //C --> F
    {
        temp0 = (1.8*temp)+32;
    }
    else
    {
        temp0 = (temp-32)*(0.555556);
    }
    printf("%.2f",temp0);
    return 0;
    
}