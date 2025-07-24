//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Initialize the bingo board
void init_board(int board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) { // center spot
                board[i][j] = -1;
            } else {
                board[i][j] = (i * 15) + (j + 1);
            }
        }
    }
}

// Print the bingo board
void print_board(int board[ROWS][COLS])
{
    int i, j;

    printf("     B   I   N   G   O\n");
    printf("-----------------------\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (board[i][j] < 0) { // center spot
                printf("  * |");
            } else {
                printf(" %2d |", board[i][j]);
            }
        }
        printf("\n-----------------------\n");
    }
}

// Check if a number has been called on the bingo board
int is_duplicate(int board[ROWS][COLS], int num)
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Call a random number
int call_number(int board[ROWS][COLS])
{
    int num;

    do {
        num = rand()%75 + 1;
    } while (is_duplicate(board, num));

    return num;
}

// Check if a player has won
int check_win(int board[ROWS][COLS])
{
    int i, j, count;

    // check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] < 0 || board[i][j] > 0) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // check columns
    for (i = 0; i < COLS; i++) {
        count = 0;
        for (j = 0; j < ROWS; j++) {
            if (board[j][i] < 0 || board[j][i] > 0) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    // check diagonals
    if ((board[0][0] < 0 || board[0][0] > 0) && (board[1][1] < 0 || board[1][1] > 0) &&
        (board[2][2] < 0 || board[2][2] > 0) && (board[3][3] < 0 || board[3][3] > 0) &&
        (board[4][4] < 0 || board[4][4] > 0)) {
        return 1;
    }
    if ((board[0][4] < 0 || board[0][4] > 0) && (board[1][3] < 0 || board[1][3] > 0) &&
        (board[2][2] < 0 || board[2][2] > 0) && (board[3][1] < 0 || board[3][1] > 0) &&
        (board[4][0] < 0 || board[4][0] > 0)) {
        return 1;
    }

    return 0;
}

int main()
{
    int board[ROWS][COLS];
    int num_called;
    int player_win = 0;

    srand(time(NULL));

    printf("Welcome to Bingo!\n\n");

    // initialize the board
    init_board(board);

    // print the board
    print_board(board);

    // play until there is a winner
    do {
        // call a number
        num_called = call_number(board);

        // mark the number on the board
        int i, j;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num_called) {
                    board[i][j] = -1;
                }
            }
        }

        // print the board
        printf("\nNumber called: %d\n\n", num_called);
        print_board(board);

        // check for a win
        if (check_win(board)) {
            player_win = 1;
            break;
        }
    } while (!player_win);

    // print the winning message
    printf("\n\nBingo! You win!\n");

    return 0;
}