//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {

    int array[ARRAY_SIZE];    // Our Array

    // Populate Array with Random Numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    // Find Largest Number in Array
    int largest = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (array[i] > largest) {
           largest = array[i];
       }
    }

    printf("The largest number in the array is: %d\n", largest);

    return 0;
}