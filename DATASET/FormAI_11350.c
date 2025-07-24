//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Introspection
    printf("Hello, I am a random number generator program.\n");
    printf("I will generate 10 random numbers between 1 and 100.\n");

    // Use the current time as the seed for random number generator
    srand(time(0)); 

    // Loop to generate 10 random numbers
    for (int i=0; i<10; i++) {
        int randomNumber = rand()%100 + 1;
        printf("Random number %d: %d\n", i+1, randomNumber);
    }

    // Clean up
    printf("Thanks for using my program!\n");
    return 0;
}