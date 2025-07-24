//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// roll the dice function
int rollDice() {
    return rand() % 6 + 1;
}

// main function
int main() {
    // set the random seed based on the current time
    srand(time(NULL));
    
    printf("Welcome to the Dice Roller!\n");
    
    // the main game loop
    while (1) {
        printf("Press enter to roll the dice or q to quit...\n");
        
        // wait for user input
        char input = getchar();
        
        // if the user enters q, break out of the loop and exit
        if (input == 'q') {
            break;
        }
        
        // roll the dice and output the result to the user
        int result = rollDice();
        printf("You rolled a %d!\n", result);
        
        // wait for a bit before prompting the user again
        for (int i = 0; i < 100000000; i++); // this is just a silly way of delaying by 1 second
        
        // clear the input buffer
        while (getchar() != '\n');
    }
    
    printf("Thanks for playing the Dice Roller!\n");
    
    return 0;
}