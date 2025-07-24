//FormAI DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i, j;
    char response;
    
    // Seed random number generator
    srand(time(NULL));
    
    do {
        // Get input from user
        printf("How many sides does your dice have? ");
        scanf("%d", &sides);
        
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &rolls);
        
        // Print results of each roll
        printf("Rolling the %dd%d...\n", rolls, sides);
        for (i = 1; i <= rolls; i++) {
            printf("Roll %d: ", i);
            int total = 0;
            for (j = 1; j <= sides; j++) {
                int roll = rand() % sides + 1;
                printf("%d ", roll);
                total += roll;
            }
            printf("(Total: %d)\n", total);
        }
        
        // Ask user if they want to continue
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');
    
    return 0;
}