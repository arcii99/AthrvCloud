//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to C Drone Remote Control!\n");
    printf("Please enter the drone's ID number: ");

    int id;
    scanf("%d", &id);

    printf("Great! Now let's start flying.\n");
    printf("Use the arrow keys to move the drone.\n");
    printf("Press 'w' to go up, 's' to go down, 'a' to go left, and 'd' to go right.\n");

    char key;
    while (1) {
        printf(">> ");
        scanf(" %c", &key);

        switch (key) {
            case 'w':
                printf("Flying up!\n");
                break;
            case 's':
                printf("Flying down!\n");
                break;
            case 'a':
                printf("Flying left!\n");
                break;
            case 'd':
                printf("Flying right!\n");
                break;
            default:
                printf("I don't know that command!\n");
        }

        printf("Current location: X%d Y%d Z%d\n", rand()%100, rand()%100, rand()%100);
    }

    return 0;
}