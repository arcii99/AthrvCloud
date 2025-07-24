//FormAI DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 500

int board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board with random values
void init_board() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// Function to print the board
void print_board() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %2d", i);
    }
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d| ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("---");
    }
    printf("\n");
}

// Function to get the sum of all elements in a row
int get_row_sum(int row) {
    int sum = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        sum += board[row][i];
    }
    return sum;
}

// Function to get the sum of all elements in a column
int get_col_sum(int col) {
    int sum = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        sum += board[i][col];
    }
    return sum;
}

// Function to handle player input
int handle_input(int player_num, int *row, int *col) {
    printf("Player %d's turn\n", player_num);
    printf("Enter row: ");
    scanf("%d", row);
    printf("Enter column: ");
    scanf("%d", col);
    if (*row < 0 || *row >= BOARD_SIZE || *col < 0 || *col >= BOARD_SIZE) {
        printf("Invalid input\n");
        return 0;
    }
    if (board[*row][*col] == 0) {
        printf("That space is already empty\n");
        return 0;
    }
    return 1;
}

// Function to play the game
void play_game() {
    int cur_player = 1;
    int moves_left = MAX_MOVES;
    while (1) {
        print_board();
        printf("Player %d, you have %d moves left\n", cur_player, moves_left);
        int row, col;
        while (!handle_input(cur_player, &row, &col));
        moves_left--;
        int sum = get_row_sum(row);
        if (sum == 0) {
            printf("Player %d wins!\n", cur_player);
            break;
        }
        sum = get_col_sum(col);
        if (sum == 0) {
            printf("Player %d wins!\n", cur_player);
            break;
        }
        board[row][col] = 0;
        if (moves_left == 0) {
            printf("Game over. No more moves left\n");
            break;
        }
        cur_player = (cur_player % 2) + 1;
    }
}

// Main function
int main() {
    init_board();
    play_game();
    return 0;
}