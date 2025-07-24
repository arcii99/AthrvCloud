//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// function to take user input for drone movement
void user_input(char* input) {
    printf("Enter movement command for drone: ");
    scanf("%s", input);
}

int main() {
    printf("Welcome to your C Drone Remote Control!\n");

    // initialize drone position to (0, 0)
    int x_pos = 0;
    int y_pos = 0;

    // main loop for drone control
    while (1) {

        // take user input for drone movement
        char input[10];
        user_input(input);

        // check for quit command
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // update drone position based on movement command
        if (strcmp(input, "up") == 0) {
            y_pos++;
        } else if (strcmp(input, "down") == 0) {
            y_pos--;
        } else if (strcmp(input, "left") == 0) {
            x_pos--;
        } else if (strcmp(input, "right") == 0) {
            x_pos++;
        } else {
            printf("Invalid command. Please enter 'up', 'down', 'left', 'right', or 'quit'.\n");
        }

        // display updated drone position
        printf("Drone position: (%d, %d)\n", x_pos, y_pos);
    }

    return 0;
}