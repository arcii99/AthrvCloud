//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>

/* Function for Linear Search */
int linearSearch(int arr[], int size, int element) {
    for(int i=0; i<size; i++) {
        if(arr[i] == element) {
            return i;    // Return the index where element found
        }
    }
    return -1;    // Return -1 if element not found
}

int main() {
    int arr[] = {5, 12, 8, 9, 15, 4, 7};
    int size = sizeof(arr)/sizeof(int);
    int element = 15;

    int index = linearSearch(arr, size, element);

    if(index != -1) {
        printf("Element %d found at index %d!", element, index);
    }
    else {
        printf("Element not found!");
    }

    return 0;
}