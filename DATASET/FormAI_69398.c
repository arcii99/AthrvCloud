//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[]) {
    printf("******************************\n");
    printf("*   HUNGRY HIPPOS GAMEBOARD  *\n");
    printf("******************************\n");
    printf("*  1  *  2  *  3  *  4  *  5  *\n");
    printf("*  %d  *  %d  *  %d  *  %d  *  %d  *\n", board[0], board[1], board[2], board[3], board[4]);
    printf("*---------------------------*\n");
    printf("*  6  *  7  *  8  *  9  * 10  *\n");
    printf("*  %d  *  %d  *  %d  *  %d  *  %d  *\n", board[5], board[6], board[7], board[8], board[9]);
    printf("******************************\n");
}

int main() {
    int board[10] = {0}; // initialize the game board to all zeroes
    int playerScores[2] = {0}; // initialize the player scores to all zeroes
    int currentPlayer = 0; // set the starting player to player one
    int winner = -1; // initialize the winner to -1 (no one has won yet)
    int marbleCount = 22; // set the total number of marbles in the game
    int moveChoice; // the player's choice for their move
    int moveAmount; // the number of marbles the player wants to move
    int i; // loop counter
    
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to Hungry Hippos!\n");
    
    while(winner == -1) { // keep playing until someone wins
        printBoard(board); // show the game board
        printf("Player %d, it's your turn!\n", currentPlayer + 1);
        moveChoice = rand() % 10; // choose a random spot on the board for the player to move from
        moveAmount = rand() % (board[moveChoice] + 1); // choose a random number of marbles for the player to move
        
        printf("Player %d chose to move %d marbles from spot %d!\n", currentPlayer + 1, moveAmount, moveChoice + 1);
        
        for(i = 0; i < moveAmount; i++) { // move the marbles
            if(moveChoice + i >= 10) { // if we've reached the end of the board, wrap around to the other side
                board[moveChoice + i - 10]++;
            } else {
                board[moveChoice + i]++;
            }
        }
        
        if(board[moveChoice] > 4) { // if the spot that the player moved from now has more than 4 marbles, a hippo eats them
            board[moveChoice] -= 5;
            playerScores[currentPlayer]++;
            printf("Player %d's hippo just ate 5 marbles!\n", currentPlayer + 1);
        }
        
        marbleCount -= moveAmount; // decrement the total number of marbles
        if(marbleCount == 0) { // if all the marbles have been moved, the game is over
            if(playerScores[0] > playerScores[1]) {
                winner = 0;
            } else if(playerScores[1] > playerScores[0]) {
                winner = 1;
            } else {
                winner = rand() % 2; // if there's a tie, choose a winner randomly
            }
            
            printf("Game over! Player %d wins with a score of %d!\n", winner + 1, playerScores[winner]);
        }
        
        currentPlayer = (currentPlayer + 1) % 2; // switch to the other player's turn
    }
    
    return 0;
}