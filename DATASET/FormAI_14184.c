//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player_score = 0, computer_score = 0, round = 1, player_choice, computer_choice;
    srand(time(NULL)); // Seed the random number generator

    printf("\n\t\t\t--- Welcome to the C Table Game ---\n");
    printf("\n\tRules: The game has 5 rounds. In each round, you and the computer will choose a number between 1 and 10.\n\t If the sum of the choices is even, you get a point. If the sum is odd,\n\t the computer gets a point. The player with the most points at the end of 5 rounds, wins.\n");

    for(round = 1; round <= 5; round++){
        printf("\n\tRound %d\n", round);
        printf("\tChoose a number between 1 and 10: ");
        scanf("%d", &player_choice);
        while(player_choice < 1 || player_choice > 10){
            printf("\n\tInvalid choice. Please choose a number between 1 and 10: ");
            scanf("%d", &player_choice);
        }
        computer_choice = (rand() % 10) + 1; // Generate a random number between 1 and 10 for the computer
        printf("\tComputer chooses: %d\n", computer_choice);
        if((player_choice + computer_choice) % 2 == 0){
            player_score++;
            printf("\tYou win this round!\n");
        }
        else{
            computer_score++;
            printf("\tComputer wins this round!\n");
        }
    }

    printf("\n\tFinal Scores\n");
    printf("\tPlayer: %d\n", player_score);
    printf("\tComputer: %d\n", computer_score);

    if(player_score > computer_score){
        printf("\n\tCongratulations! You win the game!\n");
    }
    else if(computer_score > player_score){
        printf("\n\tSorry, the computer wins the game. Better luck next time!\n");
    }
    else{
        printf("\n\tIt's a tie!\n");
    }

    printf("\n\t\t--- Thanks for playing! ---\n");

    return 0;
}