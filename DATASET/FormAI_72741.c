//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define constants for control signal
#define CONTROL_UP 'w'
#define CONTROL_DOWN 's'
#define CONTROL_LEFT 'a'
#define CONTROL_RIGHT 'd'
#define CONTROL_STOP 'x'
#define CONTROL_QUIT 'q'

/* Define helper functions */
void printInstructions() {
    printf("\n*******************\n");
    printf("* CONTROLS:        *\n");
    printf("* Up: %c            *\n", CONTROL_UP);
    printf("* Down: %c          *\n", CONTROL_DOWN);
    printf("* Left: %c          *\n", CONTROL_LEFT);
    printf("* Right: %c         *\n", CONTROL_RIGHT);
    printf("* Stop: %c          *\n", CONTROL_STOP);
    printf("* Quit: %c          *\n", CONTROL_QUIT);
    printf("*******************\n");
}

void printSignal(char signal) {
    printf("Signal sent: %c\n", signal);
}

/* Define main program */
int main(int argc, char *argv[]) {
    char controlSignal = CONTROL_STOP;

    // Print instructions
    printInstructions();

    // Loop until user quits
    while (controlSignal != CONTROL_QUIT) {
        // Prompt user for input
        printf("\nEnter control signal: ");
        controlSignal = tolower(getchar());

        // Ignore any characters after the first
        while (getchar() != '\n');

        // Print signal and send it to drone
        printSignal(controlSignal);
        // Your code to send controlSignal to drone here
    }

    printf("\nExiting program\n");

    return 0;
}