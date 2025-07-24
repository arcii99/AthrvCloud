//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int prob_sum = 0; // total probability of alien invasion
    srand(time(NULL)); // seeding the random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of years for which you want to calculate the probability: ");
    int num_years;
    scanf("%d", &num_years);

    for (int i = 1; i <= num_years; i++) {
        int prob_year = rand() % 101; // generates a random integer between 0 and 100
        printf("Year %d: Probability of Alien Invasion = %d\n", i, prob_year);
        prob_sum += prob_year; // adding the probability of current year to overall probability sum
    }

    printf("\nTotal Probability of Alien Invasion over %d years = %d\n", num_years, prob_sum);
    float avg_prob = (float)prob_sum / num_years; // calculating average probability
    printf("Average Probability of Alien Invasion per year = %.2f%%\n", avg_prob);

    if (avg_prob > 50) {
        printf("Oh no! The probability of Alien Invasion is too high!\n");
    } else {
        printf("Phew! Looks like we're safe for now.\n");
    }

    return 0;
}