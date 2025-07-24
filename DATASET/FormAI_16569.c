//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
/* Romeo and Juliet: The C Drone Remote Control */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char command[20];
    int distance = 0;
    bool isFlying = false;

    while (true) {
        printf("My love, what shall I do? ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "takeoff") == 0) {
            if (isFlying) {
                printf("My love, the drone is already in the sky!\n");
            } else {
                printf("My love, the drone takes off and reaches for the heavens!\n");
                isFlying = true;
            }
        } else if (strcmp(command, "land") == 0) {
            if (!isFlying) {
                printf("My love, the drone is already on the ground!\n");
            } else {
                printf("My love, the drone gently lands and is ready for its next mission.\n");
                isFlying = false;
                distance = 0;
            }
        } else if (strcmp(command, "forward") == 0) {
            if (!isFlying) {
                printf("My love, the drone cannot perform this action while on the ground!\n");
            } else {
                printf("My love, the drone boldly moves forward through the air!\n");
                distance += 10;
            }
        } else if (strcmp(command, "backward") == 0) {
            if (!isFlying) {
                printf("My love, the drone cannot perform this action while on the ground!\n");
            } else {
                printf("My love, the drone gracefully moves backward through the air!\n");
                distance -= 10;
            }
        } else if (strcmp(command, "left") == 0) {
            if (!isFlying) {
                printf("My love, the drone cannot perform this action while on the ground!\n");
            } else {
                printf("My love, the drone turns left with skill and precision!\n");
            }
        } else if (strcmp(command, "right") == 0) {
            if (!isFlying) {
                printf("My love, the drone cannot perform this action while on the ground!\n");
            } else {
                printf("My love, the drone swerves to the right with grace and poise!\n");
            }
        } else if (strcmp(command, "distance") == 0) {
            printf("My love, the drone has traveled %d meters from its starting point.\n", distance);
        } else if (strcmp(command, "exit") == 0) {
            printf("Farewell, my love. May the winds always be in our favor.\n");
            return 0;
        } else {
            printf("My love, I cannot understand your command. Please try again.\n");
        }
    }
}