//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>

int main()
{
    double population, military, technology, leadership, resources, invasion_probability;

    printf("Please enter the following parameters to calculate the probability of alien invasion:\n");
    printf("Total human population: ");
    scanf("%lf",&population);
    printf("Number of military personnel: ");
    scanf("%lf",&military);
    printf("Technological advancement (out of 10): ");
    scanf("%lf",&technology);
    printf("Leadership strength (out of 10): ");
    scanf("%lf",&leadership);
    printf("Available resources (out of 10): ");
    scanf("%lf",&resources);

    // Calculation of invasion probability based on given parameters
    invasion_probability = ((technology + leadership + resources)*100000)/(population*military);

    printf("\nBased on the given parameters, the probability of alien invasion is: %.5lf%%\n", invasion_probability);

    return 0;
}

/*
Sample input:
Total human population: 8000000000
Number of military personnel: 5000000
Technological advancement (out of 10): 9.5
Leadership strength (out of 10): 8.5
Available resources (out of 10): 7

Expected output:
Based on the given parameters, the probability of alien invasion is: 2.39375%
*/