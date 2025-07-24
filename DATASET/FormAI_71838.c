//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

// A function to clear the input buffer
void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    int x = 0;
    int y = 0;
    char direction = 'N';
    char input[MAX_INPUT_LENGTH];
    memset(input, 0, MAX_INPUT_LENGTH);

    printf("Welcome to Robot Movement Control!\n");

    while (1) {

        // Print the current position of the robot
        printf("Robot is currently at position (%d, %d) facing %c\n", x, y, direction);

        // Get the user input
        printf("Enter movement command (F to move forward, L to turn left, R to turn right): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Convert the user input to uppercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }

        // Execute the user command
        if (strncmp(input, "F", 1) == 0) {
            switch (direction) {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            }
        } else if (strncmp(input, "L", 1) == 0) {
            switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'W':
                direction = 'S';
                break;
            }
        } else if (strncmp(input, "R", 1) == 0) {
            switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'W':
                direction = 'N';
                break;
            }
        } else {
            printf("Invalid input. Please enter F, L or R.\n");
            continue;
        }

        // Clear the input buffer
        clearInput();

    }

    return 0;
}