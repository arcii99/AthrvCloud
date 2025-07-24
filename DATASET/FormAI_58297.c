//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Weather Simulator!\n");

    int temperature = 20;
    int day = 1;
    srand(time(NULL));
    int chance;

    while (day <= 7) {
        printf("\n---Day %d---\n", day);

        chance = rand() % 100 + 1;
        if (chance > 70) {
            printf("A storm is approaching...\n");
            temperature -= 5;
        } else {
            printf("The weather is clear.\n");
        }

        chance = rand() % 100 + 1;
        if (chance > 20) {
            printf("Temperature is rising.\n");
            temperature += 2;
        } else {
            printf("Temperature is falling.\n");
            temperature -= 3;
        }

        printf("The temperature is %d degrees Celsius.\n", temperature);

        day++;
    }

    printf("\nThe simulation is over. Thank you for using the Weather Simulator!");

    return 0;
}