//FormAI DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>

// Define a function that takes an array and its length as input
int my_search(int arr[], int len, int val) {
    // Loop through the array
    for(int i = 0; i < len; i++) {
        // If the current element of the array matches the value we are trying to find, return its index
        if(arr[i] == val) {
            return i;
        }
    }

    // If the value is not found, return -1
    return -1;
}

int main() {
    // Define an array and populate it with some values
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Define a value to search for
    int val = 8;

    // Call the my_search function to find the index of the value
    int idx = my_search(arr, 10, val);

    // Print out the index of the value
    if(idx != -1) {
        printf("The value %d was found at index %d\n", val, idx);
    } else {
        printf("The value %d was not found in the array\n", val);
    }

    return 0;
}