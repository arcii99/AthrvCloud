//FormAI DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>

// Function to implement Linear Search algorithm
int linearSearch(int arr[], int n, int key)
{
    // Start searching from the first element of the array
    for (int i = 0; i < n; i++) {
      
        // Check if the key is equal to the element at index i
        if (arr[i] == key)
            return i;
    }
    
    // Return -1 if the key is not found in the array
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    // Call the Linear Search function and store the result in variable result
    int result = linearSearch(arr, n, key);
  
    // Check if the key is present in the array and print the appropriate message
    if (result != -1)
        printf("Element %d is present at index %d\n", key, result);
    else
        printf("Element %d is not present in the array\n", key);

    return 0;
}