//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initialize random number generator
    srand(time(NULL));
    
    // Define variables
    int invasion_prob = rand() % 100 + 1;  // Probability of alien invasion (between 1 and 100)
    int n_years = rand() % 100 + 1;  // Number of years to simulate (between 1 and 100)
    int invasion_year = 0;  // Year of alien invasion (0 if no invasion)
    int prev_prob = 0;  // Probability of invasion in previous year
    
    // Print initial conditions
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("Initial probability of invasion: %d%%\n", invasion_prob);
    printf("Number of years to simulate: %d\n", n_years);
    printf("\n");
    
    // Simulate invasion probability over n_years
    for (int year = 1; year <= n_years; year++) {
        // Compute new probability of invasion based on previous year's probability
        int new_prob = prev_prob + rand() % 20 - 10;
        if (new_prob < 0) {
            new_prob = 0;
        } else if (new_prob > 100) {
            new_prob = 100;
        }
        
        // Print probability of invasion for current year
        if (new_prob > invasion_prob && invasion_year == 0) {
            invasion_year = year;
            printf("*** WARNING: Probability of invasion has increased to %d%% in year %d ***\n", new_prob, invasion_year);
        } else {
            printf("Year %d: Probability of invasion is %d%%\n", year, new_prob);
        }
        
        // Set previous probability for next year's simulation
        prev_prob = new_prob;
    }
    
    // Print final results
    printf("\n");
    if (invasion_year == 0) {
        printf("No alien invasion detected after %d years.\n", n_years);
    } else {
        printf("*** ALERT: Alien invasion detected in year %d with probability of %d%% ***\n", invasion_year, prev_prob);
    }

    return 0;
}