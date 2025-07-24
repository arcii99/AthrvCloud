//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int invasionProbability = rand() % 101; // Generate a random probability of alien invasion between 0 and 100
    printf("CALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("--------------------------------------\n");
    printf("The probability of an alien invasion is %d%%\n", invasionProbability);
    if (invasionProbability >= 70) {
        printf("ALERT! The probability of an alien invasion is very high.\n");
        printf("Please take necessary precautions.\n");
    } else if (invasionProbability >= 40) {
        printf("CAUTION! The probability of an alien invasion is moderate.\n");
        printf("Stay vigilant and report any unusual activities.\n");
    } else {
        printf("The probability of an alien invasion is low.\n");
        printf("You can carry on with your daily routine.\n");
    }
    printf("Press any key to exit.\n");
    getchar();
    return 0;
}