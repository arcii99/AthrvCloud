//FormAI DATASET v1.0 Category: Game ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 4
#define MAX_ROUND 3

int main(){
    srand(time(NULL));
    int players[MAX_PLAYERS] = {0};
    int scores[MAX_PLAYERS] = {0};
    int total_score = 0;    
    int round_score = 0;

    printf("\nWELCOME TO THE MULTIPLAYER GAME\nLet's get started!");

    // Round Loop
    for(int round = 1; round <= MAX_ROUND; round++){       

        printf("\n\nROUND %d\n\n", round);

        // Player Loop
        for(int player = 1; player <= MAX_PLAYERS; player++){
            printf("\nIt's Player %d's turn.\n", player);

            int roll_dice = rand() % 6 + 1;
            printf("\nPlayer %d rolled a dice and got %d.\n", player, roll_dice);

            if(roll_dice % 2 == 0){
                round_score += roll_dice;
                total_score += roll_dice;
                printf("Player %d has scored %d in this round and has a total score of %d.\n", player, round_score, total_score);
            } else {
                printf("Unfortunately, Player %d's score in this round won't be added to the total score.\n", player);
            }

            scores[player-1] = total_score;

            // Check for winner
            if(total_score >= 50){
                printf("\nPlayer %d has won the game with a total score of %d!\n", player, total_score);
                exit(0);
            }
        }      
    }

    // Check for winners
    int max_score = scores[0];
    int winner = 1;
    for(int i=1; i < MAX_PLAYERS; i++){
        if(scores[i] > max_score){
            max_score = scores[i];
            winner = i+1;
        } else if(scores[i] == max_score){
            printf("\nIt's a tie! Players %d and %d both have a total score of %d.\n", winner, i+1, max_score);
        }
    }

    printf("\nPlayer %d has won the game with a total score of %d!\n", winner, max_score);

    return 0;
}