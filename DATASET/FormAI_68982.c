//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    int command;

    printf("Quadcopter Drone Remote Control\n\n");

    do {
        printf("\nSelect a command:\n");
        printf("1. Takeoff\n");
        printf("2. Ascend\n");
        printf("3. Descend\n");
        printf("4. Travel North\n");
        printf("5. Travel South\n");
        printf("6. Travel East\n");
        printf("7. Travel West\n");
        printf("8. Land\n");
        printf("9. Exit\n");

        printf("\nEnter command number: ");
        scanf("%d", &command);

        switch(command) {
            case 1:
                printf("\nQuadcopter is now taking off...\n");
                break;
            case 2:
                printf("\nQuadcopter is ascending...\n");
                break;
            case 3:
                printf("\nQuadcopter is descending...\n");
                break;
            case 4:
                printf("\nQuadcopter is traveling North...\n");
                break;
            case 5:
                printf("\nQuadcopter is traveling South...\n");
                break;
            case 6:
                printf("\nQuadcopter is traveling East...\n");
                break;
            case 7:
                printf("\nQuadcopter is traveling West...\n");
                break;
            case 8:
                printf("\nQuadcopter is now landing...\n");
                break;
            case 9:
                printf("\nExiting drone remote control program...\n");
                return 0;
            default:
                printf("\nInvalid command. Please enter a valid command number (1-9).\n");
        }
    } while(command != 9);

    return 0;
}