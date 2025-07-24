//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>

// Function to find an element in the array using Linear Search Algorithm
int linearSearch(int arr[], int size, int element) {
    for(int i=0; i<size; i++) {
        if(arr[i] == element)
            return i;
    }
    return -1; // element not found
}

int main() {
    int arr[] = {23, 45, 67, 89, 12, 56, 78, 91, 34, 76};
    int element = 23;
    int size = sizeof(arr)/sizeof(arr[0]);

    // calling the linearSearch function to search for the element in the array
    int result = linearSearch(arr, size, element);

    if(result == -1)
        printf("The element is not present in the array!");
    else
        printf("The element is present at index: %d", result);

    return 0;
}