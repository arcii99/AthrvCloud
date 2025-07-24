//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
// A table game called "Dice Roll"

#include<stdio.h>
#include<time.h>

// Declaration of helper functions
int rollDice();
void printLeaderboard(int, int);

int main(){
    //Initial player scores
    int player1_score = 0;
    int player2_score = 0;

    //Welcome message
    printf("Welcome to Dice Roll game!\n\n");

    //Play rounds until one player reaches 100 points
    while(player1_score < 100 && player2_score < 100){
        printf("Player 1's turn: Press Enter to roll the dice!\n");
        getchar(); //waits for user to press enter
        int roll1 = rollDice();
        printf("You rolled a %d\n", roll1);
        player1_score += roll1;
        printf("Your score is now %d\n\n", player1_score);

        printf("Player 2's turn: Press Enter to roll the dice!\n");
        getchar(); //waits for user to press enter
        int roll2 = rollDice();
        printf("You rolled a %d\n", roll2);
        player2_score += roll2;
        printf("Your score is now %d\n\n", player2_score);

        //Print leaderboard after each round
        printLeaderboard(player1_score, player2_score);
    }

    //Print the winner of the game!
    if(player1_score >= 100){
        printf("Congratulations Player 1, you win!\n");
    } else {
        printf("Congratulations Player 2, you win!\n");
    }

    return 0;
}

//Rolls a six-sided dice and returns result
int rollDice(){
    srand(time(NULL)); //sets seed for random number generator
    return (rand() % 6) + 1;
}

//Prints the current score of each player
void printLeaderboard(int p1, int p2){
    printf("-----------------\n");
    printf("Scoreboard\n");
    printf("Player 1: %d\n", p1);
    printf("Player 2: %d\n");
    printf("-----------------\n\n");
}