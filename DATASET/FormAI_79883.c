//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice;
    char play_again;
    srand(time(NULL));
    
    printf("Welcome to the Dice Roller!\n\n");
    
    do {
        dice = rand() % 6 + 1;
        
        printf("You rolled a %d!\n", dice);
        
        if (dice == 1) {
            printf("Oh no, you rolled a one! Better luck next time!\n");
        } else if (dice == 6) {
            printf("Wow, you rolled a six! Congrats!\n");
        } else {
            printf("Not bad, not bad. Roll again?\n");
        }
        
        printf("Press y to roll again or any other key to exit: ");
        scanf(" %c", &play_again);
        printf("\n");
    } while (play_again == 'y' || play_again == 'Y');
    
    printf("Thanks for playing! Goodbye!\n");
    
    return 0;
}