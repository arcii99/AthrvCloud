//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[50], size, i, search, flag = 0;

    // Cyberspace teleportation to generate array
    srand(time(0)); // initialize the random number generator
    size = rand() % 50 + 1; // generate a random size between 1 to 50
    printf("\nWelcome to the Cyberspace Searching Algorithm.\n");
    printf("\nGenerating a random integer array of size %d...\n", size);

    // Fill array with random integers between 1 and 100
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1; // generate a random integer between 1 to 100
        printf("%d ", array[i]); // display each array element
    }

    // Prompt user for integer to search
    printf("\n\nTime to search for an integer!\n");
    printf("\nEnter an integer to search for: ");
    scanf("%d", &search);

    // Search the array for the integer inputted
    for (i = 0; i < size; i++) {
        if (array[i] == search) {
            printf("\nInteger found at index %d.\n", i);
            flag = 1; // set flag to true to indicate integer was found
            break; // exit the for loop
        }
    }

    // Display message if the integer was not found
    if (flag == 0) {
        printf("\nInteger not found in array.\n");
    }

    return 0;
}