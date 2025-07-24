//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// function to find the sum of an array using recursion
int arraySum(int arr[], int size)
{
    // base case
    if (size == 0)
    {
        return 0;
    }
    else
    {
        // recursive case
        return arr[size - 1] + arraySum(arr, size - 1);
    }
}

// function that takes two integers and returns their maximum value
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// function that finds the maximum value in an array using recursion
int maxArray(int arr[], int size)
{
    // base case
    if (size == 1)
    {
        return arr[0];
    }
    else
    {
        // recursive case
        return max(arr[size - 1], maxArray(arr, size - 1));
    }
}

// function that finds the minimum value in an array using recursion
int minArray(int arr[], int size)
{
    // base case
    if (size == 1)
    {
        return arr[0];
    }
    else
    {
        // recursive case
        int m = minArray(arr, size - 1);
        if (arr[size - 1] < m)
        {
            return arr[size - 1];
        }
        else
        {
            return m;
        }
    }
}

// function that reverses an array using recursion
void reverseArray(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    else
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        reverseArray(arr, left + 1, right - 1);
    }
}

// function that shuffles an array using recursion
void shuffleArray(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        shuffleArray(arr, size - 1);
        int index = rand() % size;
        int temp = arr[size - 1];
        arr[size - 1] = arr[index];
        arr[index] = temp;
    }
}

// main function
int main()
{
    int arr[] = {3, 2, 1, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print sum of array
    printf("Sum of array: %d\n", arraySum(arr, size));
    
    // find the maximum value in the array
    int maxVal = maxArray(arr, size);
    printf("Maximum value in array: %d\n", maxVal);

    // find the minimum value in the array
    int minVal = minArray(arr, size);
    printf("Minimum value in array: %d\n", minVal);

    // reverse the array
    reverseArray(arr, 0, size - 1);
    printf("Reversed array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // shuffle the array
    srand(123); // seed the random number generator
    shuffleArray(arr, size);
    printf("Shuffled array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}