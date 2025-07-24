//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, flag;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    // Dynamically allocate an array to store the prime numbers
    int *prime_num = (int*)malloc(n * sizeof(int));

    // 2 is the only even prime number, so add it directly
    prime_num[0] = 2;
    flag = 1; // Flag to keep track of the index of prime number array

    // Check for prime numbers starting from 3
    for (i = 3; flag < n; i+=2)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                // Not a prime number
                break;
            }
        }

        if (j == i)
        {
            // i is a prime number
            prime_num[flag] = i;
            flag++;
        }
    }

    printf("The first %d prime numbers are: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", prime_num[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(prime_num);

    return 0;
}