//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the following information:\n");

    int number_of_planets;
    double distance_to_aliens;
    int military_strength;
    int technological_advancement;
    int total_score = 0;

    printf("Number of Planets in your Galaxy: ");
    scanf("%d", &number_of_planets);
    total_score += number_of_planets * 10;

    printf("Distance from nearest Alien Planet (in light years): ");
    scanf("%lf", &distance_to_aliens);
    total_score += (int)((100 - distance_to_aliens) / 10);

    printf("Military Strength of your Planet (0-100): ");
    scanf("%d", &military_strength);
    total_score += military_strength;

    printf("Technological Advancement of your Planet (0-100): ");
    scanf("%d", &technological_advancement);
    total_score += technological_advancement;

    double probability = (double)total_score * 0.01;

    printf("\nBased on the information provided, the probability of an Alien Invasion is %.2lf%%.\n\n", probability);

    return 0;
}