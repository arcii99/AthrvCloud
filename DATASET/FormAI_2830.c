//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randrange(int min, int max) {
    return ((rand() % (max - min + 1)) + min);
}

int main() {
    srand((unsigned) time(NULL));

    int army_size = 10000;
    int invasion_force = 5000;
    int invasion_probability = (invasion_force / army_size) * 100;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("The size of your army is: %d\n", army_size);
    printf("The size of the invasion force is: %d\n", invasion_force);
    printf("The probability of an alien invasion is: %d%%\n", invasion_probability);

    int attack_probability = randrange(0, 100);
    printf("The attack probability is: %d%%\n", attack_probability);

    if (attack_probability <= invasion_probability) {
        printf("ALIEN INVASION!!!\n");
        printf("Your army was defeated...\n");
    } else {
        printf("Phew, your army was able to repel the alien invasion!\n");
    }

    return 0;
}