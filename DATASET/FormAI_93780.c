//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\nWe are here to help you calculate the probability of an alien invasion!\n\n");

    int rating;
    printf("On a scale of 1 to 10, how prepared is your country for an alien invasion?: ");
    scanf("%d", &rating);
    printf("\n");

    if (rating == 10) {
        printf("Congratulations! Your country has a 5%% chance of being invaded by aliens.\n");
    } else if (rating >= 8 && rating <= 9) {
        printf("Great job! Your country has a 10%% chance of being invaded by aliens.\n");
    } else if (rating >= 5 && rating <= 7) {
        printf("Your country has a 25%% chance of being invaded by aliens. Some extra preparation may be necessary.\n");
    } else if (rating >= 2 && rating <= 4) {
        printf("Your country has a 50%% chance of being invaded by aliens. Immediate action is recommended.\n");
    } else {
        printf("Sorry, but your country has a 75%% chance of being invaded by aliens. Your lack of preparation is concerning.\n");
    }

    printf("\nThank you for using our Alien Invasion Probability Calculator!\n\n");

    return 0;
}