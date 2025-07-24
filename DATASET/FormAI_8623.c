//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array of conspiracy theories
char *theories[] = {
    "The government is controlling the weather through chemtrails!",
    "Aliens have been living among us for decades!",
    "The moon landing was faked!",
    "The earth is flat!",
    "The illuminati control the world!",
    "9/11 was an inside job!",
    "The coronavirus was engineered in a laboratory!"
};

// Function to generate a random number between min and max (inclusive)
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with current time
    srand((unsigned int)time(NULL));
    
    // Generate a random conspiracy theory
    int index = getRandom(0, sizeof(theories) / sizeof(theories[0]) - 1);
    printf("Conspiracy theory of the day:\n\n%s\n", theories[index]);
    
    return 0;
}