//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability = 0;
    srand(time(0));   // Seed for random number generator
    int num_aliens = rand() % 100 + 1;   // Generate number of aliens randomly between 1 and 100

    // Check probability based on number of aliens
    if (num_aliens < 10) {
        probability = 5;   // Probability is low if number of aliens is less than 10
    } else if (num_aliens >= 10 && num_aliens < 50) {
        probability = 50;   // Probability is moderate if number of aliens is between 10 and 50
    } else {
        probability = 90;   // Probability is high if number of aliens is greater than or equal to 50
    }

    printf("Alien Invasion Probability Calculator\n");
    printf("--------------------------------------\n");
    printf("Number of Aliens: %d\n", num_aliens);
    printf("Probability of Invasion: %d%%\n", probability);

    return 0;
}