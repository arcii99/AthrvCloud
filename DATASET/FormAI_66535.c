//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the following information:\n");

    int num_countries;
    printf("Number of countries on Earth: ");
    scanf("%d", &num_countries);

    int alien_tech_level;
    printf("Alien technology level (1-10): ");
    scanf("%d", &alien_tech_level);

    srand(time(NULL));
    int random_num = rand() % num_countries;

    printf("\nCalculating probability of invasion...\n");

    if (random_num < 10) {
        printf("\nProbability: 0%%\n");
        printf("Earth is safe from an alien invasion for now!\n");
    }
    else if (random_num >= 10 && random_num < 30 && alien_tech_level < 5) {
        printf("\nProbability: 20%%\n");
        printf("The chances of an invasion are low, but we should still be cautious.\n");
    }
    else if (random_num >= 10 && random_num < 30 && alien_tech_level >= 5) {
        printf("\nProbability: 60%%\n");
        printf("We need to prepare for a possible invasion. Our military forces must be ready for any scenario.\n");
    }
    else if (random_num >= 30 && alien_tech_level < 5) {
        printf("\nProbability: 40%%\n");
        printf("We should be on high alert, but there is still a chance that we will not be invaded.\n");
    }
    else {
        printf("\nProbability: 90%%\n");
        printf("An invasion is imminent. Our only hope is to band together and fight back with all our might.\n");
    }

    return 0;
}