//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(time(NULL)); // Set seed for random number generation
    
    int num_days; // Number of days to simulate
    float invasion_prob, total_prob = 0; // Invasion probability for each day and total probability over all days
    
    printf("Alien Invasion Probability Calculator\n");
    printf("=====================================\n\n");
    
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);
    
    printf("\n\nSimulation Results\n");
    printf("==================\n");
    
    for (int i = 1; i <= num_days; i++) {
        invasion_prob = (float) (rand() % 100 + 1) / 100; // Generate random probability between 0.01 and 1.00
        total_prob += invasion_prob;
        
        printf("Day %d: Probability of Alien Invasion = %.2f\n", i, invasion_prob);
    }
    
    printf("\n\nOverall Probability\n");
    printf("===================\n");
    printf("The total probability of Alien Invasion over %d days = %.2f\n", num_days, total_prob);
    
    return 0;
}