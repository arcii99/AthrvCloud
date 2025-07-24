//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // ensure random seed based on current time

    int num_attackers = rand() % 100; // number of alien attackers, range: 0 to 99
    int num_defenders = rand() % 100; // number of human defenders, range: 0 to 99
    int num_days = rand() % 15; // number of days until invasion, range: 0 to 14

    float prob_win = 0; // probability of winning against the alien invasion
    
    // calculate probability of winning based on number of attackers, defenders, and days until invasion
    if (num_attackers == 0) {
        prob_win = 1; // 100% chance of winning if there are no attackers
    } else if (num_attackers > num_defenders) {
        prob_win = 1 - ((float)num_defenders / (float)num_attackers) - ((float)num_days / 100);
    } else {
        prob_win = 1 - ((float)num_attackers / (float)num_defenders) - ((float)num_days / 100);
    }
    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("The scenario is as follows:\n\n");
    printf("Number of alien attackers: %d\n", num_attackers);
    printf("Number of human defenders: %d\n", num_defenders);
    printf("Days until invasion: %d\n\n", num_days);
    printf("Based on our calculations, your probability of winning against the alien invasion is %.2f%%.\n", prob_win * 100);

    return 0;
}