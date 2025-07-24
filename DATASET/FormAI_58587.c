//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
    int total_population, available_weapons, probability;

    printf("Welcome to the C Alien Invasion Probability Calculator\n");

    printf("Please enter the total population of the area: ");
    scanf("%d", &total_population);

    printf("Please enter the total number of available weapons: ");
    scanf("%d", &available_weapons);

    printf("\nCalculating...\n\n");
    
    probability = (total_population / 10000) * (available_weapons / 100);

    if(probability > 75) {
        printf("Probability of Alien Invasion: High\n");
    } else if(probability <= 75 && probability > 50) {
        printf("Probability of Alien Invasion: Moderate\n");
    } else if(probability <= 50 && probability > 25) {
        printf("Probability of Alien Invasion: Low\n");
    } else {
        printf("Probability of Alien Invasion: Very Low\n");
    }

    return 0;
}