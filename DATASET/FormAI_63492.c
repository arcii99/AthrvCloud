//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int main()
{
    int n, i, j, flag;
    printf("Enter the range of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The prime numbers within the range are: \n");

    //Iterating through numbers in the range
    for (i = 2; i <= n; i++)
    {
        flag = 0;

        //checking if i is prime or not
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        //if i is prime number, print it
        if (flag == 0)
            printf("%d\n", i);
    }

    return 0;
}