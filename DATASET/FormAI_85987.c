//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <unistd.h>

int main() {
    int lightLevel = 10;
    int desiredLevel = 0;

    printf("Welcome to your medieval smart home light control system!\n");

    while (1) {
        printf("Current light level: %d\n", lightLevel);
        printf("Enter desired light level (0-10): ");
        scanf("%d", &desiredLevel);

        if (desiredLevel < 0) {
            printf("That's too dark! Please choose a level between 0 and 10.\n");
        } else if (desiredLevel > 10) {
            printf("That's too bright! Please choose a level between 0 and 10.\n");
        } else {
            while (lightLevel != desiredLevel) {
                printf("Adjusting light level...\n");

                if (lightLevel < desiredLevel) {
                    lightLevel++;
                } else {
                    lightLevel--;
                }

                usleep(500000);
            }

            printf("Light level set to %d.\n\n", lightLevel);
        }
    }

    return 0;
}