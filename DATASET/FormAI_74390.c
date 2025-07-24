//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int shape = -1, choice, score = 0;
    srand(time(NULL)); // initialize random seed
    
    while (1) {
        // Print menu
        printf("\n====================\n");
        printf("    SHAPE SHIFTER   \n");
        printf("====================\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n4. Quit\n");
        printf("Choose your shape: ");
        scanf("%d", &choice);
        
        // Check user input
        if (choice < 1 || choice > 4) {
            printf("\nInvalid choice. Try again.\n");
            continue;
        }
        if (choice == 4) {
            printf("\nFinal score: %d\n", score);
            printf("Goodbye!\n");
            break;
        }
        
        // Generate random shape and compare with user's choice
        shape = rand() % 3 + 1;
        if (choice == shape) {
            printf("\nYou both chose the same shape. Draw game.\n");
        } else if ((choice == 1 && shape == 3) || (choice == 2 && shape == 1) || (choice == 3 && shape == 2)) {
            printf("\nYou won! %d beats %d.\n", choice, shape);
            score++;
        } else {
            printf("\nYou lost! %d beats %d.\n", shape, choice);
            score--;
        }
    }
    
    return 0;
}