//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

int playGame(int board[][3], int player);
int checkWin(int board[][3]);
void printBoard(int board[][3]);

int main() {
    int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} }; // initialize board
    printf("Welcome to the C Table game!\n");
    printBoard(board); // print initial board
    printf("Player 1 (X) goes first.\n\n");
    playGame(board, 1); // start game with player 1
    return 0;
}

int playGame(int board[][3], int player) {
    int row, col, winner, nextPlayer;
    char mark;
    if (player == 1) {
        mark = 'X';
        nextPlayer = 2;
    } else {
        mark = 'O';
        nextPlayer = 1;
    }
    // get input from current player
    printf("Player %d (%c), please enter a row number (1-3): ", player, mark);
    scanf("%d", &row);
    printf("Player %d (%c), please enter a column number (1-3): ", player, mark);
    scanf("%d", &col);
    printf("\n");
    if (row < 1 || row > 3 || col < 1 || col > 3) {
        printf("Invalid input. Please enter a row and column number between 1 and 3.\n");
        return playGame(board, player); // recursive call to replay turn
    } else if (board[row-1][col-1] != 0) {
        printf("That cell is already taken. Please choose an empty cell.\n");
        return playGame(board, player); // recursive call to replay turn
    } else {
        board[row-1][col-1] = player;
        printBoard(board); // print updated board
        winner = checkWin(board); // check if game is over
        if (winner != 0) {
            printf("Player %d (%c) wins!\n", winner, (winner==1) ? 'X' : 'O');
            return 0; // exit game
        } else {
            if (player == 1) {
                printf("It's now Player %d (O)'s turn.\n\n", nextPlayer);
            } else {
                printf("It's now Player %d (X)'s turn.\n\n", nextPlayer);
            }
            return playGame(board, nextPlayer); // recursive call for next turn
        }
    }
}

int checkWin(int board[][3]) {
    int i, j, sum;
    // check rows
    for (i = 0; i < 3; i++) {
        sum = board[i][0] + board[i][1] + board[i][2];
        if (sum == 3 || sum == 6) {
            return board[i][0];
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        sum = board[0][j] + board[1][j] + board[2][j];
        if (sum == 3 || sum == 6) {
            return board[0][j];
        }
    }
    // check diagonals
    if ((board[0][0] + board[1][1] + board[2][2] == 3) || (board[0][2] + board[1][1] + board[2][0] == 3)) {
        return 1;
    } else if ((board[0][0] + board[1][1] + board[2][2] == 6) || (board[0][2] + board[1][1] + board[2][0] == 6)) {
        return 2;
    } else {
        // check for tie
        sum = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                sum += board[i][j];
            }
        }
        if (sum == 13) {
            printf("It's a tie!\n");
            return 3;
        } else {
            return 0;
        }
    }
}

void printBoard(int board[][3]) {
    int i, j;
    printf("   1   2   3\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i+1);
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf("|   "); // print empty cell
            } else {
                printf("|%c ", (board[i][j] == 1) ? 'X' : 'O'); // print X or O
            }
        }
        printf("|\n");
        printf("  -----------\n");
    }
    printf("\n");
}