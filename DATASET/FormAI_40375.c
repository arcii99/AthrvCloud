//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability;
    srand(time(NULL)); // seed the random number generator
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    
    // randomly generate a probability between 0 and 100
    probability = rand() % 101;
    
    printf("The probability of an alien invasion is %d%%.\n", probability);
    if (probability >= 50) {
        printf("It looks like the odds are against us...\n");
    } else {
        printf("Don't worry, the odds are in our favor!\n");
    }
    
    return 0;
}