//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>

// Function to perform searching algorithm
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    printf("Welcome to the unique C Searching Algorithm program!\n");
    printf("Please enter the number of elements in your array: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    printf("Great! Please enter %d integers for your array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Please enter the integer that you would like to search for: ");
    int x;
    scanf("%d", &x);

    int result = search(arr, n, x);

    if (result == -1)
        printf("Sorry, the integer %d was not found in the array.\n", x);
    else
        printf("Success! The integer %d was found at index %d in the array.\n", x, result);

    return 0;
}