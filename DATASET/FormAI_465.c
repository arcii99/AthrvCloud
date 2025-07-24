//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>

int main() {
    int population, military_power;

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the population of your city: ");
    scanf("%d", &population);
    printf("Great! Now please enter your city's military power (on a scale of 1 to 10): ");
    scanf("%d", &military_power);

    int invasion_prob = ((population / 1000000) * military_power) / 10;

    printf("Calculating probability...\n");
    sleep(3);
    printf("The probability of an alien invasion is: %d%%\n", invasion_prob);

    if (invasion_prob < 30) {
        printf("The chances of an invasion are slim. No need to panic.\n");
    } else if (invasion_prob >= 30 && invasion_prob < 70) {
        printf("There is a moderate chance of an invasion. Prepare your defenses.\n");
    } else {
        printf("The chances of an invasion are very high. Evacuate immediately!\n");
    }

    return 0;
}