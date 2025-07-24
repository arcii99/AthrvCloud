//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define SPACES 25
#define RANGE 75

int main() {

    srand(time(NULL));

    // Initialize Bingo Board
    int board[ROWS][COLS] = {0};
    char seen[SPACES] = {0};

    // Setup Bingo Call List
    int calls[RANGE] = {0};
    for (int i = 0; i < RANGE; i++) {
        calls[i] = i + 1;
    }

    // Shuffle Bingo Call List
    for (int i = 0; i < RANGE; i++) {
        int rand_index = rand() % RANGE;
        int temp = calls[i];
        calls[i] = calls[rand_index];
        calls[rand_index] = temp;
    }

    // Mark Center Square as Free Space
    board[ROWS/2][COLS/2] = -1;

    // Print Bingo Board
    printf("\n\t     B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\t   +---+---+---+---+---+\n");
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("\t   | X ");
            }
            else {
                printf("\t   | %2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\t   +---+---+---+---+---+\n");

    // Play Bingo Game
    int num_calls = 0;
    while (true) {

        // Generate Next Random Call
        int call = calls[num_calls];

        // Check if Call is Already Seen
        if (seen[call]) {
            continue;
        }

        // Mark Call as Seen
        seen[call] = 1;

        // Find Cell with Call Number and Mark as Seen
        bool found_call = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == call) {
                    board[i][j] = -1;
                    found_call = true;
                    break;
                }
            }
            if (found_call) {
                break;
            }
        }

        // Print Called Number
        printf("\n\n\t\t%d\n\n", call);

        // Print Bingo Board
        printf("\t     B   I   N   G   O\n");
        for (int i = 0; i < ROWS; i++) {
            printf("\t   +---+---+---+---+---+\n");
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == -1) {
                    printf("\t   | X ");
                }
                else {
                    printf("\t   | %2d ", board[i][j]);
                }
            }
            printf("|\n");
        }
        printf("\t   +---+---+---+---+---+\n");

        // Increment Number of Calls
        num_calls++;

        // Check for Winning Condition
        bool won_vertical = false;
        bool won_horizontal = false;
        bool won_diagonal = false;

        // Check Vertical Rows
        for (int j = 0; j < COLS; j++) {
            bool all_seen = true;
            for (int i = 0; i < ROWS; i++) {
                if (board[i][j] != -1) {
                    all_seen = false;
                    break;
                }
            }
            if (all_seen) {
                won_vertical = true;
                break;
            }
        }

        // Check Horizontal Rows
        for (int i = 0; i < ROWS; i++) {
            bool all_seen = true;
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != -1) {
                    all_seen = false;
                    break;
                }
            }
            if (all_seen) {
                won_horizontal = true;
                break;
            }
        }

        // Check Diagonal
        if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            won_diagonal = true;
        }
        else if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            won_diagonal = true;
        }

        // Print Winning Message and End Game
        if (won_vertical || won_horizontal || won_diagonal) {
            printf("\n\n\t\tBINGO!\n\n");
            break;
        }
    }

    return 0;
}