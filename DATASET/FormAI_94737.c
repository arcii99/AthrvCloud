//FormAI DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_INT_DIGITS 11

// Initialize the game board with unique random numbers
void init_board(int board[ROWS][COLS]) {
    int num_unique_num = ROWS * COLS / 2;
    int unique_nums[num_unique_num], rand_num, i, j, k;

    // Generate random unique numbers for the board
    for (i = 0; i < num_unique_num;) {
        rand_num = rand() % 100;
        for (j = 0; j < i; j++) {
            if (unique_nums[j] == rand_num) break;
        }
        if (j == i) unique_nums[i++] = rand_num;
    }

    // Fill the game board using the randomly generated unique numbers
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = unique_nums[(i * COLS + j) / 2];
        }
    }

    // Shuffle the board
    for (k = 0; k < 20; k++) {
        i = rand() % ROWS;
        j = rand() % COLS;
        while (board[i][j] == -1) {
            i = rand() % ROWS;
            j = rand() % COLS;
        }
        board[i][j] = -1;
    }
}

// Print the game board
void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    int i, j;
    char cell[MAX_INT_DIGITS + 1];

    // Print column headers
    printf("  |");
    for(j=0; j<COLS; j++) printf(" %c |", j + 'A');
    printf("\n");

    // Print horizontal line separator
    printf("--*");
    for(j=0; j<COLS; j++) printf("---*");
    printf("\n");

    // Print rows
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(revealed[i][j]) sprintf(cell, "%02d", board[i][j]);
            else sprintf(cell, "  ");
            if(j == 0) printf("%d |", i);
            printf(" %s |", cell);
        }
        printf("\n");

        // Print horizontal line separator
        printf("--*");
        for(j=0; j<COLS; j++) printf("---*");
        printf("\n");
    }
}

// Reveal the cell at the specified row and column
void reveal_cell(int row, int col, int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    revealed[row][col] = 1;
}

// Check if the game is over
int is_game_over(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    int i, j, count=0;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(revealed[i][j] == 1) count++;
        }
    }
    if(count == ROWS * COLS) return 1;
    else return 0;
}

int main() {
    int board[ROWS][COLS], revealed[ROWS][COLS], row, col, prev_row=-1, prev_col=-1, move_count=0;
    char temp_row, temp_col;
    char confirm;

    srand(time(0)); // Seed random number generator with current time

    // Initialize the game board with unique random numbers
    init_board(board);

    // Set all cells to unrevealed
    for(row=0; row<ROWS; row++) {
        for(col=0; col<COLS; col++) {
            revealed[row][col] = 0;
        }
    }

    printf("Welcome to the Memory Game!\n");
    printf("---------------------------\n\n");
    printf("Here is the game board:\n\n");

    // Print the initial game board
    print_board(board, revealed);

    // Start the game loop
    while(!is_game_over(board, revealed)) {
        do {
            printf("Enter the row and column of the cell you want to reveal (e.g. A2): ");
            scanf(" %c%c", &temp_row, &temp_col);
            row = temp_row - '0';
            col = temp_col - 'A';
        } while(row < 0 || row >= ROWS || col < 0 || col >= COLS || revealed[row][col]);

        reveal_cell(row, col, board, revealed);
        print_board(board, revealed);

        // Check if the current cell matches the previous cell revealed
        if(prev_row != -1) {
            if(board[row][col] != board[prev_row][prev_col]) {
                // Ask the player if they want to continue or quit
                do {
                    printf("Sorry, that was not a match.\n");
                    printf("Do you want to continue or quit the game? (C/Q): ");
                    scanf(" %c", &confirm);
                } while(confirm != 'C' && confirm != 'c' && confirm != 'Q' && confirm != 'q');
                if(confirm == 'Q' || confirm == 'q') break;
                // Hide the previous cell revealed
                revealed[prev_row][prev_col] = 0;
            } else {
                printf("Congratulations, you found a match!\n");
            }
            prev_row = -1;
            prev_col = -1;
        } else {
            prev_row = row;
            prev_col = col;
        }
        move_count++;
    }

    // Game over message
    if(is_game_over(board, revealed)) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Game Over.\n");
    }
    printf("You made %d moves.\n", move_count);

    return 0;
}