//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float alienProbabilities[5][5] = {
        {0.90, 0.70, 0.50, 0.30, 0.10},
        {0.80, 0.60, 0.40, 0.20, 0.05},
        {0.70, 0.50, 0.30, 0.10, 0.03},
        {0.60, 0.40, 0.20, 0.05, 0.01},
        {0.50, 0.30, 0.10, 0.03, 0.005}
    };
    int cities[5] = {1, 2, 3, 4, 5};
    int totalCities = 5;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    while (1) {
        printf("Here is the list of available cities:\n");
        for (int i = 0; i < totalCities; i++) {
            printf("%d) City %d\n", i+1, cities[i]);
        }

        int selectedCity;
        do {
            printf("\nPlease select a city (1-%d): ", totalCities);
            scanf("%d", &selectedCity);
        } while (selectedCity < 1 || selectedCity > totalCities);

        float alienProbability = alienProbabilities[selectedCity-1][rand() % 5];

        printf("\nThe probability of an alien invasion in City %d is %.2f%%\n\n", cities[selectedCity-1], alienProbability * 100);

        printf("Would you like to calculate the probability of another city? (Y/N): ");
        char response;
        scanf(" %c", &response);
        if (response != 'Y' && response != 'y') {
            break;
        }
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n\n");

    return 0;
}