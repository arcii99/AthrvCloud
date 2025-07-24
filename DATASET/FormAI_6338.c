//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int probability = rand() % 101; // generate a random number from 0 to 100
    
    printf("The probability of an alien invasion is %d%%\n", probability);
    
    return 0;
}