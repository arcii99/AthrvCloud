//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Setting seed for random number generation based on time
    int array[10]; // Initializing an array of size 10
    int i;

    printf("Generating 10 random numbers:\n");

    for(i = 0; i < 10; i++) {
        array[i] = rand(); // Generating a random integer and adding it to the array
        printf("%d\n", array[i]); // Printing the generated number
    }

    printf("\nSorting the array in ascending order:\n");
    int j;
    int temp;
    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            if(array[i] > array[j]) { // Check if the current element is greater than the next element
                temp = array[i]; // Swap the elements if the condition is true
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(i = 0; i < 10; i++) {
        printf("%d\n", array[i]); // Printing the sorted array
    }
    return 0;
}