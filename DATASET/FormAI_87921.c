//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int shown[BOARD_SIZE][BOARD_SIZE];
int num_shown = 0;
int first_row, first_col, second_row, second_col;

void init_board() {
    // Initialize board with random numbers
    int nums[BOARD_SIZE*BOARD_SIZE/2];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        nums[i] = i+1;
    }
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 && j == 0) {
                board[i][j] = 0;
            } else {
                int r = rand() % (BOARD_SIZE*BOARD_SIZE/2);
                board[i][j] = nums[r];
                nums[r] = nums[BOARD_SIZE*BOARD_SIZE/2-1];
            }
            shown[i][j] = 0;
        }
    }
}

void display_board() {
    // Display current state of board
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n  +");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (shown[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    printf("  +");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("---");
    }
    printf("\n");
}

void get_input() {
    // Get user input for two positions to flip
    do {
        printf("Enter the row and column of the first tile to flip (e.g. 1 2): ");
        scanf("%d %d", &first_row, &first_col);
    } while (first_row < 0 || first_row >= BOARD_SIZE ||
             first_col < 0 || first_col >= BOARD_SIZE ||
             shown[first_row][first_col]);
    do {
        printf("Enter the row and column of the second tile to flip (e.g. 2 3): ");
        scanf("%d %d", &second_row, &second_col);
    } while (second_row < 0 || second_row >= BOARD_SIZE ||
             second_col < 0 || second_col >= BOARD_SIZE ||
             shown[second_row][second_col] ||
             (first_row == second_row && first_col == second_col));
}

int check_match() {
    // Check if the two flipped tiles match
    if (board[first_row][first_col] == board[second_row][second_col]) {
        num_shown += 2;
        shown[first_row][first_col] = 1;
        shown[second_row][second_col] = 1;
        printf("Match found!\n");
        return 1;
    } else {
        printf("No match.\n");
        return 0;
    }
}

int check_win() {
    // Check if all tiles have been flipped
    return num_shown == BOARD_SIZE*BOARD_SIZE-1;
}

int main() {
    int num_moves = 0;

    init_board();
    display_board();

    while (!check_win()) {
        get_input();
        num_moves++;
        printf("Flipping tiles...\n");
        display_board();

        if (check_match()) {
            printf("You have %d matches and have used %d moves.\n", num_shown/2, num_moves);
        } else {
            // Flip back incorrect tiles
            shown[first_row][first_col] = 0;
            shown[second_row][second_col] = 0;
        }
    }

    printf("Congratulations, you win in %d moves!\n", num_moves);

    return 0;
}