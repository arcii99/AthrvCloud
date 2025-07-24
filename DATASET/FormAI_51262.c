//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Greetings human, I am a curious memory management bot. Let me show you how I can allocate and deallocate memory with ease:\n\n");

    // First, let's allocate some memory for an integer variable
    int* myInt = (int*) malloc(sizeof(int));
    printf("I have allocated memory for an integer variable using malloc!\n");

    // Let's assign a value to our allocated integer and print it out
    *myInt = 42;
    printf("The value of my integer is: %d\n\n", *myInt);

    // Now, let's allocate memory for an array of integers using calloc
    int* myIntArray = (int*) calloc(5, sizeof(int));
    printf("I have allocated memory for an array of integers using calloc!\n");

    // Let's assign some values to our allocated array and print them out
    for (int i = 0; i < 5; i++) {
        myIntArray[i] = i * 10;
        printf("The value of element %d in my integer array is: %d\n", i, myIntArray[i]);
    }
    printf("\n");

    // Uh oh, I made a mistake and need to reallocate memory for myIntArray
    printf("Oops, I made a mistake and need to reallocate memory for my integer array!\n");
    myIntArray = (int*) realloc(myIntArray, 10 * sizeof(int));
    printf("I have reallocated memory for my integer array using realloc!\n");

    // Let's assign some new values to our reallocated array and print them out
    for (int i = 5; i < 10; i++) {
        myIntArray[i] = i * 10;
        printf("The value of element %d in my integer array is: %d\n", i, myIntArray[i]);
    }
    printf("\n");

    // Finally, let's free our allocated memory to prevent memory leaks
    printf("I'm done playing with memory for now, time to free it all up!\n");
    free(myInt);
    free(myIntArray);

    printf("Thanks for playing with memory with me! Goodbye :)");

    return 0;
}