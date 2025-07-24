//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
// The Alien Invasion Probability Calculator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the following information:\n\n");

    // Collect information from user
    char name[100];
    int age, num_countries_visited, num_abductions;
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Number of countries visited: ");
    scanf("%d", &num_countries_visited);
    printf("Number of times abducted by aliens: ");
    scanf("%d", &num_abductions);

    // Initialize random number generator using seed from current time
    srand(time(NULL));

    // Calculate probability of alien invasion based on user information
    double probability = 0.0;
    probability += (double) age / 100.0;
    probability += (double) num_countries_visited / 50.0;
    probability += (double) num_abductions / 10.0;
    probability += (double) (rand() % 101) / 100.0;

    // Output results
    printf("\n\nCalculating probability...\n\n");
    printf("Based on the information provided, %s, your probability of experiencing an alien invasion is %f%%.\n", name, probability);

    // Interpret results based on probability
    if (probability < 50.0) {
        printf("It is unlikely that you will experience an alien invasion in your lifetime.\n");
    } else if (probability >= 50.0 && probability < 75.0) {
        printf("You have a moderate chance of experiencing an alien invasion in your lifetime.\n");
    } else {
        printf("You have a high chance of experiencing an alien invasion in your lifetime!\n");
    }

    return 0;
}