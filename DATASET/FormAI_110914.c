//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Initialize variables
    int x = 0, y = 0;
    char input;

    // Loop until the user enters 'q'
    while(input != 'q') {
        // Print current position
        printf("Current position: (%d, %d)\n", x, y);

        // Get user input
        printf("Enter a direction (u = up, d = down, l = left, r = right, q = quit): ");
        scanf(" %c", &input);

        // Update position based on user input
        switch(input) {
            case 'u':
                y++;
                break;
            case 'd':
                y--;
                break;
            case 'l':
                x--;
                break;
            case 'r':
                x++;
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}