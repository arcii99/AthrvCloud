//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>

// Function to search for an element in an array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main()
{
    printf("Welcome to the search program!\n");
    printf("Let's search for an element in an array.\n");

    // Create a sample array
    int arr[] = { 5, 10, 15, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ask user for the element to search
    int x;
    printf("Enter the element you want to search: ");
    scanf("%d", &x);

    // Call the search function and print the result
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Sorry, the element was not found in the array.\n");
    }
    else {
        printf("Yay! The element was found at index %d in the array.\n", result);
    }

    printf("Thanks for using the search program. Have a nice day!\n");

    return 0;
}