//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board
void init_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Set the initial positions of the checkers
            if (row < 3 && (row + col) % 2 == 0) {
                board[row][col] = 'B';
            } else if (row > 4 && (row + col) % 2 == 0) {
                board[row][col] = 'W';
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

// Print the board to the console
void print_board() {
    printf("\n   A B C D E F G H");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("\n %d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("|%c", board[row][col]);
        }
        printf("| %d", row + 1);
    }
    printf("\n   A B C D E F G H\n");
}

int main() {
    init_board();
    print_board();

    // Game loop
    int turn = 0;
    while (1) {
        if (turn % 2 == 0) {
            printf("\nBlack's turn:");
        } else {
            printf("\nWhite's turn:");
        }

        // Get user input
        int start_x, start_y, end_x, end_y;
        printf("\nEnter start position (e.g. A1):");
        scanf(" %c%d", &start_x, &start_y);
        printf("Enter end position (e.g. B2):");
        scanf(" %c%d", &end_x, &end_y);
        start_x -= 'A';
        end_x -= 'A';
        start_y -= 1;
        end_y -= 1;

        // Check if move is valid
        if (start_x < 0 || start_x >= BOARD_SIZE || start_y < 0 || start_y >= BOARD_SIZE ||
            end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) {
            printf("Invalid move! Coordinates out of bounds.\n");
            continue;
        }
        if (board[start_y][start_x] == ' ') {
            printf("Invalid move! No checker at start position.\n");
            continue;
        }
        if (board[end_y][end_x] != ' ') {
            printf("Invalid move! End position already occupied.\n");
            continue;
        }

        // Move the checker
        if (turn % 2 == 0) {
            if (board[start_y][start_x] == 'B') {
                if (end_y == start_y + 1 && (end_x == start_x-1 || end_x == start_x+1)) {
                    board[start_y][start_x] = ' ';
                    board[end_y][end_x] = 'B';
                } else if (end_y == start_y + 2 && (end_x == start_x-2 || end_x == start_x+2)) {
                    int middle_x = (start_x + end_x) / 2;
                    int middle_y = (start_y + end_y) / 2;
                    if (board[middle_y][middle_x] != 'W') {
                        printf("Invalid move! You must jump over an enemy checker.\n");
                        continue;
                    }
                    board[start_y][start_x] = ' ';
                    board[middle_y][middle_x] = ' ';
                    board[end_y][end_x] = 'B';
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
            } else {
                printf("Invalid move! You cannot move an enemy checker.\n");
                continue;
            }
        } else {
            if (board[start_y][start_x] == 'W') {
                if (end_y == start_y - 1 && (end_x == start_x-1 || end_x == start_x+1)) {
                    board[start_y][start_x] = ' ';
                    board[end_y][end_x] = 'W';
                } else if (end_y == start_y - 2 && (end_x == start_x-2 || end_x == start_x+2)) {
                    int middle_x = (start_x + end_x) / 2;
                    int middle_y = (start_y + end_y) / 2;
                    if (board[middle_y][middle_x] != 'B') {
                        printf("Invalid move! You must jump over an enemy checker.\n");
                        continue;
                    }
                    board[start_y][start_x] = ' ';
                    board[middle_y][middle_x] = ' ';
                    board[end_y][end_x] = 'W';
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
            } else {
                printf("Invalid move! You cannot move an enemy checker.\n");
                continue;
            }
        }

        // Check for a win
        int black_count = 0;
        int white_count = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == 'B' || board[row][col] == 'K') {
                    black_count++;
                } else if (board[row][col] == 'W' || board[row][col] == 'Q') {
                    white_count++;
                }
            }
        }
        if (black_count == 0) {
            printf("\nWhite wins!");
            break;
        } else if (white_count == 0) {
            printf("\nBlack wins!");
            break;
        }

        // Print the board and switch turns
        print_board();
        turn++;
    }

    return 0;
}