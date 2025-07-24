//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include<stdio.h>

// Custom search function that returns the index of the searched element
int customSearch(int arr[], int n, int searchElement) {
    int i;
    for(i=0; i<n; i++) {
        if(arr[i] == searchElement) {
            return i;
        }
    }
    return -1;
}

// Main function to demonstrate the custom search function
int main() {
    int n, searchElement, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Accept array elements from user
    int arr[n], i;
    printf("Enter array elements:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Accept the element to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    // Call the custom search function
    result = customSearch(arr, n, searchElement);

    // Check if the searched element was found or not
    if(result == -1) {
        printf("%d was not found in the array.", searchElement);
    }
    else {
        printf("%d was found at index %d in the array.", searchElement, result);
    }
    return 0;
}