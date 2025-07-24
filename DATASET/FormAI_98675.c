//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initialize drone variables
    int altitude = 0;
    int speed = 0;
    int direction = 0;
    int batteryPercentage = 100;

    while (1) {
        // Display menu
        printf("Drone Remote Control Menu\n");
        printf("--------------------------\n");
        printf("1 - Increase altitude\n");
        printf("2 - Decrease altitude\n");
        printf("3 - Increase speed\n");
        printf("4 - Decrease speed\n");
        printf("5 - Change direction\n");
        printf("6 - Check battery percentage\n");
        printf("7 - Exit\n");
        printf("--------------------------\n");
        printf("Please enter your option: ");

        // Get user input
        int option;
        scanf("%d", &option);

        // Perform selected action
        switch (option) {
            case 1:
                altitude += 10;
                printf("Altitude increased by 10. Current altitude is %d\n\n", altitude);
                break;
            case 2:
                altitude -= 10;
                printf("Altitude decreased by 10. Current altitude is %d\n\n", altitude);
                break;
            case 3:
                if (speed < 100) {
                    speed += 10;
                    printf("Speed increased by 10. Current speed is %d\n\n", speed);
                } else {
                    printf("Maximum speed reached. Current speed is %d\n\n", speed);
                }
                break;
            case 4:
                if (speed > 0) {
                    speed -= 10;
                    printf("Speed decreased by 10. Current speed is %d\n\n", speed);
                } else {
                    printf("Minimum speed reached. Current speed is %d\n\n", speed);
                }
                break;
            case 5:
                printf("Please enter a new direction (in degrees): ");
                scanf("%d", &direction);
                printf("Direction changed to %d degrees\n\n", direction);
                break;
            case 6:
                printf("Battery Percentage: %d%%\n\n", batteryPercentage);
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}