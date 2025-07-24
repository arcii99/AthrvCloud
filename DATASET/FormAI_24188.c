//FormAI DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include<stdio.h>

/* This is a peaceful searching algorithm that finds the index of an element in an array 
   using linear search technique */

int peaceful_search(int arr[], int size, int element) {
    int i;
    for(i=0; i<size; i++) {
        if(arr[i] == element) {
            printf("The element %d is present at index %d\n", element, i);
            return i;
        }
    }
    printf("The element %d is not present in the array\n", element);
    return -1;
}

int main() {
    int array[] = {1, 2, 5, 7, 9, 10, 13, 16, 18, 20}; // An example  array
    int element = 16; // The element whose index is to be found

    int size = sizeof(array)/sizeof(array[0]); // Size of the array

    peaceful_search(array, size, element); // Function call for searching

    return 0;
}