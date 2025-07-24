//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    srand(time(0)); // seed for RNG

    int num_planets, num_hospitable, num_military;
    float invasion_prob;

    printf("Enter the total number of planets in the galaxy: ");
    scanf("%d", &num_planets);

    printf("Enter the number of hospitable planets in the galaxy: ");
    scanf("%d", &num_hospitable);

    printf("Enter the number of planets with military technology in the galaxy: ");
    scanf("%d", &num_military);

    // calculate invasion probability
    invasion_prob = ((float) (num_military * 100) / num_hospitable) * ((float) (num_hospitable * 100) / num_planets) * ((float) (rand() % 100) / 100);

    printf("Calculating invasion probability...\n");
    printf("Invasion Probability: %f%%\n", invasion_prob);

    if (invasion_prob < 10) {
        printf("Congratulations! The galaxy is safe from alien invasion.\n");
    } else if (invasion_prob >= 10 && invasion_prob < 50) {
        printf("The probability of an alien invasion is low.\n");
    } else if (invasion_prob >= 50 && invasion_prob < 75) {
        printf("The probability of an alien invasion is moderate.\n");
    } else if (invasion_prob >= 75 && invasion_prob < 90) {
        printf("The probability of an alien invasion is high.\n");
    } else {
        printf("WARNING! The galaxy is at high risk of an alien invasion.\n");
    }

    return 0;
}