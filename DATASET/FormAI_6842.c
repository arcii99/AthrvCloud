//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
    int n, i, flag;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n <= 1)
    {
        printf("Invalid input. Enter a positive integer greater than 1.");
        return 0;
    }
    else
    {
        printf("Prime numbers between 1 and %d are: ", n);
    }

    for(i = 2; i <= n; i++)
    {
        flag = 0;
        for(int j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                flag = 1; // If the number is divisible by any other number, it is not Prime
                break;
            }
        }
        if(flag == 0 && i != 1)
        {
            printf("%d ", i); // If the number is not divisible by any other number, it is Prime
        }
    }

    return 0;
}