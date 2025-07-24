//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle an array
void shuffle(int arr[], int n)
{
    // Seed for random number generation
    srand(time(NULL));
    
    // Shuffle the array using Fisher-Yates algorithm
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{
    // Array of integers from 1 to 16
    int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    // Shuffle the array to get a random order
    shuffle(arr, 16);
    
    // Display the shuffled array in a 4x4 grid
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i*4+j]);
        }
        printf("\n");
    }
    
    return 0;
}