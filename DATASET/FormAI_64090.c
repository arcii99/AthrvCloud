//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* theories[] = {
    "The government is controlled by shape-shifting lizard people.",
    "9/11 was an inside job to justify the War on Terror.",
    "Chemtrails are being used to control the population.",
    "The moon landing was faked in a Hollywood studio.",
    "The Illuminati are behind all major world events.",
    "The Earth is actually flat and the government is covering up the truth.",
};

int main() {
    srand(time(NULL));  // Seed the random number generator with the time

    printf("Random Conspiracy Theory Generator\n\n");

    for (int i = 1; i <= 5; ++i) {  // Generate 5 conspiracy theories
        printf("%d. %s\n", i, theories[rand() % (sizeof(theories) / sizeof(theories[0]))]);
    }

    return 0;
}