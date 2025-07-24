//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void initializeBoard(int board[][3]);
void printBoard(int board[][3]);
int checkWin(int board[][3], int player);
int getValidMove(int board[][3], int player);
int game();

int main() {
    srand(time(NULL)); // seed for randomization

    int winner = 0;

    // loop until a player wins or quits
    while(winner == 0) {
        winner = game();
    }

    // print winner
    if(winner == 1) {
        printf("Player 1 has won!\n");
    } else if(winner == 2) {
        printf("Player 2 has won!\n");
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}

// function to initialize the board
void initializeBoard(int board[][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}

// function to print the board
void printBoard(int board[][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a player has won
int checkWin(int board[][3], int player) {
    int i, j;
    int rowSum, colSum, diagSum1, diagSum2;

    // check rows and columns
    for(i = 0; i < 3; i++) {
        rowSum = 0;
        colSum = 0;
        for(j = 0; j < 3; j++) {
            rowSum += board[i][j];
            colSum += board[j][i];
        }
        if(rowSum == player*3 || colSum == player*3) {
            return player;
        }
    }

    // check diagonals
    diagSum1 = board[0][0] + board[1][1] + board[2][2];
    diagSum2 = board[0][2] + board[1][1] + board[2][0];
    if(diagSum1 == player*3 || diagSum2 == player*3) {
        return player;
    }

    return 0;
}

// function to get a valid move from a player
int getValidMove(int board[][3], int player) {
    int row, col;

    do {
        printf("Player %d, enter a row (0-2): ", player);
        scanf("%d", &row);
        printf("Enter a column (0-2): ");
        scanf("%d", &col);
    } while(row > 2 || row < 0 || col > 2 || col < 0 || board[row][col] != 0);

    return row*3 + col + 1; // return position for display purposes
}

// function to play the game
int game() {
    int board[3][3];
    int player1 = 1, player2 = 2;
    int currentPlayer = player1;
    int winner = 0;
    int move;

    initializeBoard(board);

    printf("Player 1 is X and Player 2 is O.\n");

    do {
        printBoard(board);
        printf("Player %d's turn.\n", currentPlayer);
        move = getValidMove(board, currentPlayer);
        board[(move-1)/3][(move-1)%3] = currentPlayer;

        winner = checkWin(board, currentPlayer);
        if(winner) {
            printBoard(board);
            return winner;
        }

        if(currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }

    } while(move != 0);

    return 3; // quit game
}