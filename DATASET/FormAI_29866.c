//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, i=0, flag=0;
    printf("Enter a number to generate prime numbers till that number: ");
    scanf("%d", &num);

    // Code to check if the input number is greater than 1
    if(num<=1)
    {
        printf("Invalid input! Please enter a number greater than 1.");
        exit(0);
    }

    // Code to generate prime numbers
    printf("Prime numbers till %d are: ", num);
    for(int j=2; j<=num; j++)
    {
        flag=0;
        for(i=2; i<=j/2; i++)
        {
            if(j%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0 && j!=1)
        {
            printf("%d ", j);
        }    
    }
    printf("\n");

    return 0;
}