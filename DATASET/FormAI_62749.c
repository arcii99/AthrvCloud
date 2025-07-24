//FormAI DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 0, y = 0;
    printf("Welcome to the happy C robot movement control program!\n");
    while (1) {
        printf("Enter a direction (up/down/left/right): ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "up") == 0) {
            printf("Moving up!\n");
            y++;
        } else if (strcmp(input, "down") == 0) {
            printf("Moving down!\n");
            y--;
        } else if (strcmp(input, "left") == 0) {
            printf("Moving left!\n");
            x--;
        } else if (strcmp(input, "right") == 0) {
            printf("Moving right!\n");
            x++;
        } else {
            printf("Invalid direction. Choose up, down, left, or right.\n");
        }
        printf("Current location: (%d, %d)\n", x, y);
        printf("Yay! This C robot is so happy to be moving around.\n");
        usleep(500000);
        system("clear");
    }
    return 0;
}