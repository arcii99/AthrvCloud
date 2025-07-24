//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

// Declare the function for the search algorithm
int customSearch(int arr[], int left, int right, int value) {
    while (left <= right) {
        // Set the midpoint of the range to check
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid; // Return the index when the value is found
        } else if (arr[mid] < value) {
            left = mid + 1; // Update left end of the search range if the current value is less than the target value
        } else {
            right = mid - 1; // Update right end of the search range if the current value is greater than the target value
        }
    }
    return -1; // Return -1 if the value is not found in the array
}

int main() {
    // Declare an array of integers to be searched
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]); // Determine the size of the array
    
    // Prompt the user to input the value to be searched
    printf("Enter the value to be searched: ");
    int value;
    scanf("%d", &value);
    
    // Call the custom search algorithm
    int index = customSearch(arr, 0, n - 1, value);
    
    // Output the result of the search
    if (index == -1) {
        printf("%d was not found in the array.\n", value);
    } else {
        printf("%d was found at index %d in the array.\n", value, index);
    }
    
    return 0; // Indicate that the program has successfully completed
}