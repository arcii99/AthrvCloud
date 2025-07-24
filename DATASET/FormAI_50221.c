//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>

int main() {
    int pushups = 0;
    int situps = 0;
    float distance = 0;
    int choice = 0;

    printf("Welcome to the Fitness Tracker!\n");

    while(choice != 4) {
        printf("\n1. Track Pushups\n");
        printf("2. Track Situps\n");
        printf("3. Track Distance Traveled\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of pushups: ");
                scanf("%d", &pushups);
                printf("Total pushups tracked: %d\n", pushups);
                break;
            case 2:
                printf("Enter the number of situps: ");
                scanf("%d", &situps);
                printf("Total situps tracked: %d\n", situps);
                break;
            case 3:
                printf("Enter the distance traveled (in kilometers): ");
                scanf("%f", &distance);
                printf("Total distance tracked: %.2f kilometers\n", distance);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}