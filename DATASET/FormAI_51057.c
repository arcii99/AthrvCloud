//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
// Oh, hello there! I'm just a simple C Alien Invasion Probability Calculator.
// I didn't expect to see any humans around here. This is quite exciting!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Let me just set up the basics here for our little calculation.
    int probability;
    srand(time(0));
    probability = rand() % 101;
    
    // Wow, the probability is really high! Humans, beware!
    printf("Our scanners have detected a %d%% chance of an alien invasion.\n", probability);
    if(probability > 80) {
        printf("Oh my, that's not good. The chances are extremely high.\n");
    }
    else if (probability > 50) {
        printf("Hmmm, it seems the chances are middling. We'll need to prepare just in case.\n");
    }
    else {
        printf("Phew, it looks like we're safe for now. No need to panic.\n");
    }
    
    // Let's just do a bit of cleanup for our program.
    printf("Thanks for using our Alien Invasion Probability Calculator. Have a great day!\n");
    return 0;
}