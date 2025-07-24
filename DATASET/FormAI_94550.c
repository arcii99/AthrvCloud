//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>

int main()
{
    int num, i, flag;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: ", num);

    // loop through all numbers from 2 to num
    for(i=2; i<=num; i++)
    {
        // assume the number is prime at first
        flag = 1; 

        // loop through all numbers from 2 to i/2
        for(int j=2; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 0; // if i is divisible by any number other than 1 and itself, it's not prime
                break;
            }
        }

        // if flag is still 1 (i is prime), print i
        if(flag == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}