//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <time.h>

int main() {
    int light = 0;
    int timeOfDay = 0;
    srand(time(NULL));
    printf("Welcome to the Surrealist Smart Home Light Control Program!\n");

    while (1) {
        printf("\nCurrent Light Brightness: %d\n", light);
        printf("Current Time of Day: %d\n", timeOfDay);
        
        if (timeOfDay == 0) {
            printf("You are in a dream. The light flickers in and out of existence.\n");
            light = rand() % 2;
        } else if (timeOfDay < 6) {
            printf("The light casts long shadows. You can hear whispers on the wind.\n");
            light = rand() % 5;
        } else if (timeOfDay < 12) {
            printf("The world is lit by a warm, gentle glow.\n");
            light = rand() % 15 + 5;
        } else if (timeOfDay < 18) {
            printf("The colors of the world are vivid and bright.\n");
            light = rand() % 30 + 20;
        } else {
            printf("The darkness creeps in around the edges of the light.\n");
            light = rand() % 10;
        }

        printf("Enter a new time of day (0-23) or -1 to exit: ");
        scanf("%d", &timeOfDay);
        if (timeOfDay == -1) {
            break;
        }
    }

    printf("\nThank you for using the Surrealist Smart Home Light Control Program!\n");

    return 0;
}