//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator.
    int die1 = rand() % 6 + 1; // Generate a random number between 1 and 6 for die 1.
    int die2 = rand() % 6 + 1; // Generate a random number between 1 and 6 for die 2.
    int total = die1 + die2; // Calculate the total of both dice.
    
    printf("+-----+\n|     |\n|  %d  |\n|     |\n+-----+\n\n", die1); // Print the first die.
    printf("+-----+\n|     |\n|  %d  |\n|     |\n+-----+\n\n", die2); // Print the second die.
    printf("Total: %d\n", total); // Print the total.
    
    return 0;
}