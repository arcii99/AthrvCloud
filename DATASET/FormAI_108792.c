//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
// Welcome to the Wacky Search!
// This is a C program that searches for a specific number in a given array.
// But wait, we don't just do a linear search, that's too boring.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Function to perform the wacky search
int wacky_search(int arr[], int n, int key)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    // First we randomly shuffle the array
    srand(time(NULL));
    for (i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        k = arr[i];
        arr[i] = arr[j];
        arr[j] = k;
    }

    // Now we divide the array into three parts
    int left = 0;
    int right = n - 1;
    int mid1 = left + (right - left) / 3;
    int mid2 = left + 2 * (right - left) / 3;

    while (left <= right)
    {
        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (arr[mid1] > key)
            right = mid1 - 1;

        else if (arr[mid2] < key)
            left = mid2 + 1;

        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }

        mid1 = left + (right - left) / 3;
        mid2 = left + 2 * (right - left) / 3;
    }

    // Number not found
    return -1;
}

// Our main function
int main()
{
    printf("Welcome to the Wacky Search!\n");

    int arr[ARRAY_SIZE];
    int i = 0;
    int key = 0;

    // Initialize the array with random integers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    // Print out the original unsorted array
    printf("\nHere is the unsorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);

    // Get user input
    printf("\nEnter the number you want to search for: ");
    scanf("%d", &key);

    // Perform the wacky search
    int index = wacky_search(arr, ARRAY_SIZE, key);

    // Print out the result
    if (index == -1)
        printf("\nSorry, the number was not found.\n");

    else
        printf("\nCongratulations! The number %d was found at index %d.\n", key, index);

    return 0;
}