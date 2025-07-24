//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_simulations, num_aliens, num_days;
    float success_rate;

    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    printf("Enter the average number of aliens in the invasion: ");
    scanf("%d", &num_aliens);

    printf("Enter the number of days until the invasion: ");
    scanf("%d", &num_days);

    srand(time(NULL)); // Seed the random number generator with the current time

    int num_success = 0;

    for (int i = 0; i < num_simulations; i++) {
        int num_killed = 0;

        for (int day = 0; day < num_days; day++) {
            int daily_kill_chance = rand() % 10 + 1; // Generate a random number between 1 and 10

            if (daily_kill_chance == 1) { // 10% chance of killing an alien each day
                num_killed++;
            }
        }

        if (num_killed >= num_aliens) { // Invasion is successfully repelled if enough aliens are killed
            num_success++;
        }
    }

    success_rate = (float)num_success / num_simulations * 100;

    printf("After %d simulations, the probability of repelling an alien invasion with %d aliens in %d days is %.2f%%", num_simulations, num_aliens, num_days, success_rate);

    return 0;
}