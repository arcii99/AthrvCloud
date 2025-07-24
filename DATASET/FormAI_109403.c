//FormAI DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 10
#define MAX_Y 10

int main()
{
    int x = 0, y = 0;
    char direction = 'N';

    printf("Welcome to irregular Robot Movement Control Program!\n");
    printf("Enter 'X' to Exit.\n\n");

    while (1) {
        printf("Current position: (%d, %d), Direction: %c\n", x, y, direction);

        char input;
        printf("Enter command (F/B/L/R): ");
        scanf(" %c", &input);

        if (input == 'X') {
            printf("Exiting program...\n");
            break;
        }

        if (input == 'F') {
            switch (direction) {
                case 'N':
                    if (y < MAX_Y) {
                        y++;
                        printf("Moved Forward!\n");
                    } else {
                        printf("Cannot move forward. Reached maximum Y limit!\n");
                    }
                    break;
                case 'S':
                    if (y > 0) {
                        y--;
                        printf("Moved Forward!\n");
                    } else {
                        printf("Cannot move forward. Reached minimum Y limit!\n");
                    }
                    break;
                case 'E':
                    if (x < MAX_X) {
                        x++;
                        printf("Moved Forward!\n");
                    } else {
                        printf("Cannot move forward. Reached maximum X limit!\n");
                    }
                    break;
                case 'W':
                    if (x > 0) {
                        x--;
                        printf("Moved Forward!\n");
                    } else {
                        printf("Cannot move forward. Reached minimum X limit!\n");
                    }
                    break;
                default:
                    printf("Invalid input! Try again.\n");
                    break;
            };
        } else if (input == 'B') {
            switch (direction) {
                case 'N':
                    if (y > 0) {
                        y--;
                        printf("Moved Backward!\n");
                    } else {
                        printf("Cannot move backward. Reached minimum Y limit!\n");
                    }
                    break;
                case 'S':
                    if (y < MAX_Y) {
                        y++;
                        printf("Moved Backward!\n");
                    } else {
                        printf("Cannot move backward. Reached maximum Y limit!\n");
                    }
                    break;
                case 'E':
                    if (x > 0) {
                        x--;
                        printf("Moved Backward!\n");
                    } else {
                        printf("Cannot move backward. Reached minimum X limit!\n");
                    }
                    break;
                case 'W':
                    if (x < MAX_X) {
                        x++;
                        printf("Moved Backward!\n");
                    } else {
                        printf("Cannot move backward. Reached maximum X limit!\n");
                    }
                    break;
                default:
                    printf("Invalid input! Try again.\n");
                    break;
            };
        } else if (input == 'L') {
            switch (direction) {
                case 'N':
                    direction = 'W';
                    printf("Turned Left!\n");
                    break;
                case 'S':
                    direction = 'E';
                    printf("Turned Left!\n");
                    break;
                case 'E':
                    direction = 'N';
                    printf("Turned Left!\n");
                    break;
                case 'W':
                    direction = 'S';
                    printf("Turned Left!\n");
                    break;
                default:
                    printf("Invalid input! Try again.\n");
                    break;
            }
        } else if (input == 'R') {
            switch (direction) {
                case 'N':
                    direction = 'E';
                    printf("Turned Right!\n");
                    break;
                case 'S':
                    direction = 'W';
                    printf("Turned Right!\n");
                    break;
                case 'E':
                    direction = 'S';
                    printf("Turned Right!\n");
                    break;
                case 'W':
                    direction = 'N';
                    printf("Turned Right!\n");
                    break;
                default:
                    printf("Invalid input! Try again.\n");
                    break;
            }
        } else {
            printf("Invalid input! Try again.\n");
        }
    }

    return 0;
}