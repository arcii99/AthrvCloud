//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the following information:\n\n");

    int n_people, n_aliens;
    float prob_invasion;

    printf("Number of people on Earth: ");
    scanf("%d", &n_people);

    printf("Number of aliens invading: ");
    scanf("%d", &n_aliens);

    printf("\nCalculating probability of invasion...");
    srand(time(NULL));  // set random seed based on current time

    for (int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout); // flush output to console immediately
        sleep(1); // wait for 1 second
    }

    prob_invasion = (float) n_aliens / n_people * 100;

    printf("\n\nResults:\n\n");
    printf("Number of people: %d\n", n_people);
    printf("Number of aliens: %d\n", n_aliens);
    printf("Probability of Alien Invasion: %.2f%%\n", prob_invasion);

    if (prob_invasion >= 50) {
        printf("\n!!! ALERT !!!\n");
        printf("The probability of an Alien Invasion is greater than 50%%.\n");
        printf("Please take appropriate precautions and prepare for an extraterrestrial encounter.\n");
    } else {
        printf("\nPhew... It seems like you're safe for now.\n");
        printf("The probability of an Alien Invasion is only %.2f%%.\n", prob_invasion);
    }

    return 0;
}