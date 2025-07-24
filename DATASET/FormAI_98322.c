//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator with current time
    int probability = rand() % 101; // generate a random probability between 0 to 100
    char invasion = (probability > 50) ? 'Y' : 'N'; // assign invasion as Y or N based on probability

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Calculating the probability of an alien invasion...\n");
    printf("Probability of an alien invasion: %d%%\n", probability);
    printf("Will there be an invasion? %c\n", invasion);
    
    // add some retro ASCII art for fun
    printf("\n");
    printf("    /~~~~~~~~\\\n");
    printf("   //^ ^ ^ ^ \\\\\n");
    printf("  // ^ ^ ^ ^ ^\\\\\n");
    printf(" //^ ^ ^ ^ ^ ^ \\\\\n");
    printf("// ^ ^ ^ ^ ^ ^ ^\\\\\n");
    printf("~~~~~~~~~~~~~~~~~~\n");
    
    return 0;
}