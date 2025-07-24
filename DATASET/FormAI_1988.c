//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
/*
  This program is a cheerful example of a linear search algorithm in C.
  It searches for an element in an array and returns its index if found,
  or a message saying it was not found.
  Enjoy your search!
*/

// Required headers
#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int n, int x)
{
    // Loop through the array to find the element
    for (int i = 0; i < n; i++) {
        // If the element is found, return its index
        if (arr[i] == x) {
            return i;
        }
    }
    // If the element is not found, return -1
    return -1;
}

// Main function
int main()
{
    // Let's create an array of numbers
    int arr[] = {20, 15, 35, 10, 45, 25};
    // Let's get the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Let's search for the number 45 in the array
    int x = 45;
    int index = linear_search(arr, n, x);

    // If the number is found, print its index
    if (index != -1) {
        printf("Number %d is found at index %d :-)\n", x, index);
    }
    // If the number is not found, print a message
    else {
        printf("Number %d is not found in the array :-(\n", x);
    }

    // Let's search for the number 55 in the array
    x = 55;
    index = linear_search(arr, n, x);

    // If the number is found, print its index
    if (index != -1) {
        printf("Number %d is found at index %d :-)\n", x, index);
    }
    // If the number is not found, print a message
    else {
        printf("Number %d is not found in the array :-(\n", x);
    }

    // Hooray, we're done!
    return 0;
}