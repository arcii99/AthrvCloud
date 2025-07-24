//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main()
{
    // Generate an array of random numbers
    int arr[MAX];
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % MAX;
    }

    // Find the maximum number in the array
    int max = arr[0];
    for (int i = 1; i < MAX; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Calculate the sum of all even numbers in the array
    int sum = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
        }
    }

    // Print the results
    printf("The maximum number in the array is %d\n", max);
    printf("The sum of all even numbers in the array is %d\n", sum);

    return 0;
}