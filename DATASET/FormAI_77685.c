//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player1_score = 0;
    int player2_score = 0;
    int dice_roll;
    char player_name[20];
    
    srand(time(0)); //Seed the random number generator
    
    printf("Welcome to the Dice Roll Game!\n");
    printf("Player 1, enter your name: ");
    scanf("%s", player_name);
    printf("Hello, %s!\n", player_name);
    printf("Player 2, enter your name: ");
    scanf("%s", player_name);
    printf("Hello, %s!\n", player_name);
    
    printf("The game has begun!\n");

    while(player1_score < 50 && player2_score < 50){ //Game is played until one player reaches 50 points
        printf("\nPlayer 1's turn!\n");
        dice_roll = rand() % 6 + 1; //Roll the dice
        printf("%s rolled a %d!\n", player_name, dice_roll);
        player1_score += dice_roll; //Add the score to player1's total score
        printf("Score: %d\n", player1_score);
        
        if(player1_score >= 50){ //If player 1 reaches 50 points or more, they win
            printf("%s wins!\n", player_name);
            break;
        }
        
        printf("\nPlayer 2's turn!\n");
        dice_roll = rand() % 6 + 1; //Roll the dice
        printf("%s rolled a %d!\n", player_name, dice_roll);
        player2_score += dice_roll; //Add the score to player2's total score
        printf("Score: %d\n", player2_score);
        
        if(player2_score >= 50){ //If player 2 reaches 50 points or more, they win
            printf("%s wins!\n", player_name);
            break;
        }
    }
    printf("Thanks for playing!");
    return 0;
}