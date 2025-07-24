//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>

int main()
{
    // Get the range of numbers to check for prime numbers from the user
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("The prime numbers between %d and %d are:\n", start, end);

    // Traverse through each number in the given range
    for(int i = start; i <= end; i++)
    {
        int flag = 0;

        // Check if the number is prime or not
        for(int j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        // Print the number if it is prime
        if(flag == 0 && i != 1)
            printf("%d ", i);
    }

    return 0;
}