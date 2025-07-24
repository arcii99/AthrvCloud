//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10; // size of the array
    int array[size]; // declaration of the array
    int i, j, temp; // loop variables and temporary variable
    
    // Generate random integers between 1 to 100 for array elements
    srand(time(NULL)); 
    for(i=0; i<size; i++) {
        array[i] = rand() % 100 + 1;
    }
    
    // Print the unsorted array
    printf("Unsorted Array:\n");
    for(i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    
    // Bubble Sort Algorithm
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-i-1; j++) {
            if(array[j] > array[j+1]) { // swap the elements if jth element is greater than (j+1)th element
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    // Print the sorted array
    printf("\n\nSorted Array:\n");
    for(i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}