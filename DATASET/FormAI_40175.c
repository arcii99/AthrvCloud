//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>

int main() {
    int i = 0, j = 0, k = 0;
    char input;

    printf("Welcome to our drone remote control program!\n");

    while (1) {
        // Display current drone position
        printf("Current drone position: (%d, %d, %d)\n", i, j, k);

        // Prompt user for input
        printf("Enter input (w/a/s/d/f): ");
        scanf("%c", &input);

        // Move drone based on input
        switch(input) {
            case 'w':
                i++;
                break;
            case 'a':
                j--;
                break;
            case 's':
                i--;
                break;
            case 'd':
                j++;
                break;
            case 'f':
                k++;
                break;
            default:
                printf("Invalid input!\n");
        }
    }
    return 0;
}