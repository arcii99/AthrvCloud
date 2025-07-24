//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>

// Define constants for the range of the remote control
#define MIN_RANGE 1
#define MAX_RANGE 100

// Define function to prompt the user to enter a number within the range
int getUserInput()
{
    int input;
    do {
        printf("Enter a number between %d and %d: ", MIN_RANGE, MAX_RANGE);
        scanf("%d", &input);
        if (input < MIN_RANGE || input > MAX_RANGE) {
            printf("Invalid number. Please try again.\n");
        }
    } while (input < MIN_RANGE || input > MAX_RANGE);
    return input;
}

// Define function to move the drone according to the user input
void moveDrone(int input)
{
    printf("Moving the drone %d meters...\n", input);
}

int main()
{
    // Welcome message
    printf("Welcome to the C Drone Remote Control Program!\n");

    // Ask user to enter a number within the range
    int input = getUserInput();

    // Move the drone according to the user input
    moveDrone(input);

    // Goodbye message
    printf("Thank you for using the C Drone Remote Control Program!\n");
    return 0;
}