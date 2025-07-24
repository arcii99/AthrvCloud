//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alien_prob;
    srand(time(NULL));
    alien_prob = rand() % 100;

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("Based on complex data analysis, we have determined there is a %d percent chance of an alien invasion.\n", alien_prob);

    if (alien_prob < 20) {
        printf("It is highly unlikely that we will experience an alien invasion anytime soon.\n");
    } else if (alien_prob >= 20 && alien_prob < 50) {
        printf("There is a moderate chance of an alien invasion. We should prepare ourselves in case it happens.\n");
    } else if (alien_prob >= 50 && alien_prob < 75) {
        printf("The chance of an alien invasion is high. We need to develop a plan to defend ourselves.\n");
    } else {
        printf("Based on the data analysis, an alien invasion is imminent. We need to act fast to prevent it!\n");
    }

    return 0;
}