//FormAI DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Welcome Message
    printf("Welcome to the Table Game!\n\n");

    // Prompt user to enter their name
    char player_name[20];
    printf("Enter your name: ");
    scanf("%s", player_name);

    // Prompt user to choose a number between 1 and 10
    int player_guess;
    printf("\n%s, choose a number between 1 and 10: ", player_name);
    scanf("%d", &player_guess);

    // Generate a random number between 1 and 10 for the computer's guess
    srand(time(0)); // Seed the random number generator
    int computer_guess = rand() % 10 + 1;

    // Show the computer's guess
    printf("The computer guessed %d.\n", computer_guess);

    // Determine the winner
    if(player_guess == computer_guess){
        printf("\nCongratulations %s! You won!\n", player_name);
    }
    else{
        printf("\nBetter luck next time %s. The computer won.\n", player_name);
    }

    // Play again option
    char play_again;
    printf("\nDo you want to play again? (Y/N): ");
    scanf(" %c", &play_again);

    if(play_again == 'Y' || play_again == 'y'){
        // Play again
        printf("\nLet's play again!\n");
        main();
    }
    else{
        // Exit program
        printf("\nThank you for playing!\n");
        return 0;
    }
}