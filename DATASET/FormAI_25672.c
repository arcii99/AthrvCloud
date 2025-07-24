//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayBoard(char board[]);
int checkWin(char board[]);
int computerMove(char board[]);
void playerMove(char board[]);
int checkValidMove(char board[], int move);
void gameOver(int winner);

// Main function
int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int winner = 0;
    srand(time(NULL)); // Set seed for random number generator

    printf("*** Welcome to the C Table Game! ***\n");

    displayBoard(board);

    // Game loop
    while (winner == 0) {
        // Computer move
        int computerPos = computerMove(board);
        board[computerPos] = 'O';
        printf("Computer selects %d.\n", computerPos + 1);
        displayBoard(board);
        winner = checkWin(board);
        if (winner != 0) break;

        // Player move
        printf("Enter a number (1-9): ");
        playerMove(board);
        displayBoard(board);
        winner = checkWin(board);
    }

    gameOver(winner);

    return 0;
}

// Function to display the game board
void displayBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if a player has won the game
int checkWin(char board[]) {
    int winningPositions[8][3] = {{0,1,2}, {3,4,5}, {6,7,8},
                                  {0,3,6}, {1,4,7}, {2,5,8},
                                  {0,4,8}, {2,4,6}};
    int i;
    for (i = 0; i < 8; i++) {
        if (board[winningPositions[i][0]] == board[winningPositions[i][1]] && 
            board[winningPositions[i][1]] == board[winningPositions[i][2]]) {
            if (board[winningPositions[i][0]] == 'X') {
                return 1; // Player wins
            }
            else if (board[winningPositions[i][0]] == 'O') {
                return 2; // Computer wins
            }
        }
    }
    return 0;
}

// Function for the computer to make its move
int computerMove(char board[]) {
    int move;
    do {
        move = rand() % 9; // Generate random number from 0 to 8
    } while (!checkValidMove(board, move));
    board[move] = 'O';
    return move;
}

// Function for the player to make their move
void playerMove(char board[]) {
    int move;
    while (1) {
        scanf("%d", &move);
        move--;
        if (checkValidMove(board, move)) {
            board[move] = 'X';
            break;
        }
        printf("Please enter a valid move (1-9): ");
    }
}

// Function to check if a move is valid
int checkValidMove(char board[], int move) {
    if (board[move] <= '9' && board[move] >= '1') {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to display the game outcome
void gameOver(int winner) {
    printf("\n");
    switch(winner) {
        case 1:
            printf("Congratulations, you win!\n");
            break;
        case 2:
            printf("Sorry, you lose. Better luck next time!\n");
            break;
        default:
            printf("It's a tie!\n");
    }
}