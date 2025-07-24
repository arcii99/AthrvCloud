//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Set up random generator for game
    srand(time(NULL));
    // Set initial score and previous roll
    int score = 0;
    int prev_roll = 0;
    // Instructions for player
    printf("Welcome to Happy Dice! Roll the dice and try to get as many points as possible.\nIf you roll the same number twice, you lose all your points.\nPress 'r' to roll and 'q' to quit.\n\n");
    // Loop for game
    while(1){
        // Ask for player input
        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);
        // Quit game if player inputs 'q'
        if(choice == 'q'){
            printf("Thanks for playing. Your final score is: %d\n", score);
            return 0;
        }
        // Roll dice if player inputs 'r'
        else if(choice == 'r'){
            // Generate random number between 1 and 6
            int roll = rand() % 6 + 1;
            printf("\nYou rolled a %d.\n", roll);
            // If roll is same as previous roll, player loses all points
            if(roll == prev_roll){
                printf("Oh no! You rolled the same number twice and lost all your points.\n");
                score = 0;
            }
            // Add points to score if roll is different from previous roll
            else{
                score += roll;
                printf("You gained %d points! Your current score is: %d\n", roll, score);
                // Update previous roll
                prev_roll = roll;
            }
        }
        // If player inputs anything else, ask for input again
        else{
            printf("Invalid choice. Please input 'r' to roll or 'q' to quit.\n\n");
        }
    }
}