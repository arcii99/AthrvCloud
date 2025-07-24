//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

// Define the size of the array
#define SIZE 10

// Define the function for searching an element
int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;  // Element not found
}

int main() {
    // Declare and initialize the array
    int arr[SIZE] = {2, 8, 5, 6, 4, 9, 7, 1, 3, 0};

    // Prompt user for element to be searched
    int x;
    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    // Call the searching function
    int result = search(arr, SIZE, x);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}