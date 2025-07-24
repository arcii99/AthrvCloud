//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3]; // Global 2-D Array as Tic Tac Toe Board

/**
 * Function to display the Tic Tac Toe Board
 */
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("_________\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("_________\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/**
 * Function to check if a given move is valid or not
 */
int isValidMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (board[row][col] == '_') 
            return 1;
    }
    return 0;
}

/**
 * Function to check if a given player has won the game or not
 */
int isWinner(char player) {
    // Check the rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    // Check the columns
    for (int j=0; j<3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    // Check the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

/**
 * Function to get the opponent player
 */
char getOpponent(char player) {
    if (player == 'X')
        return 'O';
    return 'X';
}

/**
 * Function to simulate the current board state and return the score
 */
int simulateBoard(char player) {
    int score = 0;
    if (isWinner(player))
        score = 1;
    else {
        char opponent = getOpponent(player);
        int movesLeft = 0;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    score += -simulateBoard(opponent);
                    board[i][j] = '_';
                    movesLeft = 1;
                }
            }
        }
        if (movesLeft == 0)
            score=0;
    }
    return score;
}

/**
 * Function to make the best move for the computer player
 */
int makeComputerMove(char player) {
    int maxScore = -2;
    int row = -1;
    int col = -1;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                int score = -simulateBoard(getOpponent(player));
                if (score > maxScore) {
                    maxScore = score;
                    row = i;
                    col = j;
                }
                board[i][j] = '_';
            }
        }
    }
    board[row][col] = player;
    return isWinner(player);
}

/**
 * Function to get the input from the user and make the move
 */
int makePlayerMove(char player) {
    int row, col;
    while (1) {
        printf("Enter row and column (0-2) to make a move : ");
        scanf("%d %d", &row, &col);
        if (isValidMove(row, col)) {
            board[row][col] = player;
            return isWinner(player);
        }
        printf("Invalid Move!");
    }
}

/**
 * Main function to start the game
 */
int main() {
    // Initialize the board with _
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = '_';
        }
    }

    int movesLeft = 9;
    srand(time(0)); // Seed the random number generator
    int player = rand()%2 == 0 ? 'X' : 'O'; // Choose the player randomly

    printf("Tic Tac Toe\n");
    printf("Player %c will play first\n", player);
    displayBoard();

    while (movesLeft > 0) {
        int winner = 0;
        if (player == 'X') {
            winner = makePlayerMove(player);
        } else {
            winner = makeComputerMove(player);
        }
        displayBoard();
        if (winner) {
            printf("Player %c wins!\n", player);
            break;
        }
        player = getOpponent(player);
        movesLeft--;
    }
    if (movesLeft == 0) {
        printf("Game Tie!\n");
    }
    return 0;
}