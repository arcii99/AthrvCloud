//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>

int main() {
    int command;
    printf("Welcome to C Drone Remote Control System\n");

    while (1) {
        printf("Select a command:\n");
        printf("1. Take off\n");
        printf("2. Move forward\n");
        printf("3. Rotate clockwise\n");
        printf("4. Land\n");
        printf("5. Exit\n");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Drone is taking off\n");
                break;
            case 2:
                printf("Drone is moving forward\n");
                break;
            case 3:
                printf("Drone is rotating clockwise\n");
                break;
            case 4:
                printf("Drone is landing\n");
                break;
            case 5:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}