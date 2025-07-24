//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed using system time
    
    printf("Welcome to the C Alien Invasion Probability Calculator!\n\n");

    int num_tests;
    printf("How many simulations would you like to run? ");
    scanf("%d", &num_tests);

    int num_aliens;
    printf("\nHow many alien ships do you think will attack? (between 1 and 1000) ");
    scanf("%d", &num_aliens);
    
    if (num_aliens < 1 || num_aliens > 1000) { // check for valid input
        printf("\nInvalid number of aliens. Please try again.\n");
        return 0;
    }
    
    float avg_defenders, avg_shots_fired;
    int total_defenders = 0, total_shots_fired = 0;

    for (int i = 1; i <= num_tests; i++) { // run simulations
        printf("\nSimulation %d\n", i);
        int defenders = rand() % 10000 + 1; // generate random number of defenders between 1 and 10000
        total_defenders += defenders;

        int attack_prob = rand() % 100 + 1; // generate random probability of attack between 1 and 100
        if (attack_prob > 50) { // alien attack probability = attack_prob / 100
            int shots_fired = rand() % 100000 + 10000; // generate random number of shots fired between 10000 and 100000
            total_shots_fired += shots_fired;
            printf("%d alien ships attacked! %d defenders fought back and fired %d shots.\n", num_aliens, defenders, shots_fired);
        } else {
            printf("No alien ships attacked.\n");
        }
    }

    avg_defenders = (float) total_defenders / num_tests; // calculate averages
    avg_shots_fired = (float) total_shots_fired / num_tests;

    printf("\nResults:\n");
    printf("Average number of defenders: %.2f\n", avg_defenders);
    printf("Average number of shots fired: %.2f\n", avg_shots_fired);

    return 0;
}