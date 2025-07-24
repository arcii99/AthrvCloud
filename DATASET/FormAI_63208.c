//FormAI DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* define the total number of elements */
#define NUM_ELEMENTS 10

/* define a struct to hold a single element with its index */
typedef struct {
    int index;
    int value;
} Element;

/* define a function to generate a random int between 0 and 99 */
int getRandomInt() {
    return (rand() % 100);
}

int main() {
    
    /* seed the random number generator */
    srand(time(NULL));
    
    /* create an array of elements with random values */
    Element elements[NUM_ELEMENTS];
    for (int i=0; i<NUM_ELEMENTS; i++) {
        elements[i].index = i;
        elements[i].value = getRandomInt();
    }
    
    /* print the unsorted array */
    printf("Unsorted array:\n");
    for (int i=0; i<NUM_ELEMENTS; i++) {
        printf("%d ", elements[i].value);
    }
    printf("\n\n");
    
    /* begin invasive sorting */
    int i, j;
    for (i=0; i<NUM_ELEMENTS; i++) {
        for (j=0; j<NUM_ELEMENTS; j++) {
            if (elements[j].value > elements[i].value) {
                /* perform the invasive operation */
                Element tmp = elements[j];
                elements[j] = elements[i];
                elements[i] = tmp;
            }
        }
    }
    
    /* print the sorted array */
    printf("Sorted array:\n");
    for (int i=0; i<NUM_ELEMENTS; i++) {
        printf("%d ", elements[i].value);
    }
    printf("\n\n");
    
    /* print the index array that shows the original position of elements */
    printf("Index array:\n");
    for (int i=0; i<NUM_ELEMENTS; i++) {
        printf("%d ", elements[i].index);
    }
    printf("\n\n");
    
    return 0;
}