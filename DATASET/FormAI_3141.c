//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int arr[MAX], freq[MAX], n, i, j, count;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequencies to -1
    }

    // Calculate frequencies of each element
    for(i = 0; i < n; i++)
    {
        count = 1;
        for(j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freq[j] = 0; // Mark the element as counted
            }
        }

        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    // Print the element list with corresponding frequencies
    printf("\nNumber\tFrequency\n");
    for(i = 0; i < n; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }

    return 0;
}