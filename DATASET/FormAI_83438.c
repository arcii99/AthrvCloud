//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

// A gratitude-filled searching algorithm
// to find the index of an element in an array
// of integers using linear search

int findElement(int arr[], int size, int element) {

    int index = -1;

    printf("Searching for %d...\n", element);

    for(int i=0; i<size; i++) {
        if(arr[i] == element) {
            index = i;
            printf("Hooray! Found %d at index %d\n", element, index);
            printf("Thank you algorithm, you're amazing!\n");
            break;
        }
    }

    if(index == -1) {
        printf("Oops! Couldn't find %d in the array.\n", element);
        printf("But that's okay, you tried your best.\n");
    }

    return index;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int size = 5;

    int element = 15;

    int index = findElement(arr, size, element);

    printf("The index of %d in the array is %d\n", element, index);

    return 0;
}