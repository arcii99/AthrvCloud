//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seeding the random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Input the number of people on Earth: ");
    int population;
    scanf("%d", &population);

    printf("Input the number of known planets with intelligent life in the universe: ");
    int planets;
    scanf("%d", &planets);

    printf("Input the average distance between the known planets (in light years): ");
    double distance;
    scanf("%lf", &distance);

    double prob = (double)planets * (0.1 + 0.9 * (double)rand() / RAND_MAX) /
                  ((double)population * (double)distance * (double)distance * 3.14);
    printf("The probability of an alien invasion is %.10lf%%\n", prob * 100);

    return 0;
}