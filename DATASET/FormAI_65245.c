//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>

/* Function to check if the input is valid */
int isValidInput(char input) {
    int result = 0;
    if (input == 'F' || input == 'B' || input == 'L' || input == 'R' || input == 'U' || input == 'D' || input == 'S') {
        result = 1;
    }
    return result;
}

int main() {
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Use the following controls to navigate the drone:\n");
    printf("F - Move forward one foot\n");
    printf("B - Move backward one foot\n");
    printf("L - Turn left 90 degrees\n");
    printf("R - Turn right 90 degrees\n");
    printf("U - Move up one foot\n");
    printf("D - Move down one foot\n");
    printf("S - Stop the drone\n");

    char input;
    int isValid;
    do {
        printf("\nEnter your command: ");
        scanf(" %c", &input);
        isValid = isValidInput(input);
        if (!isValid) {
            printf("Invalid command. Please try again.\n");
        } else {
            printf("Executing command: %c\n", input);
        }
    } while (!isValid);

    printf("\nThank you for using C Drone Remote Control!");

    return 0;
}