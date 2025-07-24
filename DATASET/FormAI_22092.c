//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include<stdio.h>

// Ephemeral searching algorithm
int ephemeralSearch(int arr[], int n, int x) {

    // Start searching from the beginning
    int i = 0;
  
    while (i < n) {

        // Check if the current element is the target element
        if (arr[i] == x) {

            // If it is, return the index and exit the function
            return i;
        }

        // If not, move to the next element in the array
        i++;

        // Generate a random integer to determine whether to continue searching or not
        int r = rand() % 10;

        if (r < 3) {

            // If the random integer is less than 3, exit the function without finding the target element
            return -1;
        }
    }

    // If the function reaches this point, it means that the target element was not found in the array
    return -1;
}

int main() {

    // Seed the random number generator
    srand(time(0));

    // Initialize the array
    int arr[] = {1, 4, 2, 5, 3};

    // Determine the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Determine the target element
    int x = 5;

    // Search for the target element using the ephemeral searching algorithm
    int result = ephemeralSearch(arr, n, x);

    // Print the result of the search
    if (result == -1) {
        printf("Target element not found in array");
    }
    else {
        printf("Target element found at index %d", result);
    }

    return 0;
}