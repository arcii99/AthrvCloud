//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>

int main()
{
    int n, i, flag = 0;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &n);

    printf("The prime numbers between 2 and %d are: ", n);

    for (i = 2; i <= n; i++)
    {
        flag = 0;

        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0 && i != 1)
        {
            printf("%d ", i);
        }
    }
    
    printf("\nThank you for using the Prime Number Generator!\n");

    return 0;
}