//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int command, altitude = 0;
    float temperature = 25.0;
    srand(time(0));
    printf("------------------------------\n");
    printf("| C DRONE REMOTE CONTROL v1.0 |\n");
    printf("------------------------------\n");
    printf("\n");
    printf("Current altitude: %dm\n", altitude);
    printf("Current temperature: %.2f°C\n", temperature);
    printf("\n");
    while (1) {
        printf("Enter command (1-4):\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Check temperature\n");
        printf("4. Quit\n");
        scanf("%d", &command);
        printf("\n");
        switch (command) {
            case 1:
                altitude += rand() % 20 + 1;
                printf("Increased altitude to %dm.\n", altitude);
                break;
            case 2:
                if (altitude > 0) {
                    altitude -= rand() % 20 + 1;
                    printf("Decreased altitude to %dm.\n", altitude);
                } else {
                    printf("Drone is already on the ground.\n");
                }
                break;
            case 3:
                printf("Current temperature: %.2f°C\n", temperature + (rand() % 10 - 5));
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
        printf("\n");
    }
}