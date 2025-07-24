//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Define an array of fortunes
    char *fortunes[] = {"Good luck is just around the corner.",
                        "Happiness will come to you.",
                        "You will find success in your future endeavors.",
                        "Don't give up, the end result will be worth it."};
    
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random index number
    int index = rand() % 4; // Size of the fortunes array

    // Print out the fortune at that index
    printf("Your fortune: %s", fortunes[index]);

    return 0;
}