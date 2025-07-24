//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include<stdio.h>

int main()
{
    int num, i, j, flag;

    // take input from user
    printf("Enter the number: ");
    scanf("%d",&num);

    printf("Prime numbers from 1 to %d are: \n", num);

    // loop through all numbers until the given number
    for(i=2; i<=num; i++)
    {
        // flag variable
        flag = 0;

        // loop to check if the number is prime
        for(j=2; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }
        }

        // if flag is 0 the number is prime
        if(flag == 0 && i != 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}