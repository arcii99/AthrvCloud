//FormAI DATASET v1.0 Category: Checkers Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Initializes the board with initial checker placement
void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 'r';
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 'b';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Prints the board
void print_board() {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("--");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("--");
    }
    printf("\n");
}

// Checks if a move is valid
int is_valid_move(int start_x, int start_y, int end_x, int end_y, char player) {
    if (start_x < 0 || start_x > BOARD_SIZE - 1 || start_y < 0 || start_y > BOARD_SIZE - 1 ||
            end_x < 0 || end_x > BOARD_SIZE - 1 || end_y < 0 || end_y > BOARD_SIZE - 1 ||
            board[start_x][start_y] != player ||
            board[end_x][end_y] != ' ') {
        return 0;
    }
    // Check if valid move for red
    if (player == 'r' && end_x == start_x - 1 &&
            (end_y == start_y + 1 || end_y == start_y - 1)) {
        return 1;
    } else if (player == 'r' && end_x == start_x - 2 && end_y == start_y - 2 &&
            board[start_x-1][start_y-1] == 'b') {
        return 1;
    } else if (player == 'r' && end_x == start_x - 2 && end_y == start_y + 2 &&
            board[start_x-1][start_y+1] == 'b') {
        return 1;
    }
    // Check if valid move for black
    if (player == 'b' && end_x == start_x + 1 &&
            (end_y == start_y + 1 || end_y == start_y - 1)) {
        return 1;
    } else if (player == 'b' && end_x == start_x + 2 && end_y == start_y - 2 &&
            board[start_x+1][start_y-1] == 'r') {
        return 1;
    } else if (player == 'b' && end_x == start_x + 2 && end_y == start_y + 2 &&
            board[start_x+1][start_y+1] == 'r') {
        return 1;
    }
    return 0;
}

// Moves a checker
void move_checker(int start_x, int start_y, int end_x, int end_y) {
    board[end_x][end_y] = board[start_x][start_y];
    board[start_x][start_y] = ' ';
}

// Checks if game is over
int is_game_over() {
    int i, j;
    int r_count = 0;
    int b_count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'r') {
                r_count++;
            } else if (board[i][j] == 'b') {
                b_count++;
            }
        }
    }
    return (r_count == 0 || b_count == 0);
}

int main() {
    init_board();
    char player = 'r';
    int game_over = 0;
    int start_x, start_y, end_x, end_y;
    while (!game_over) {
        print_board();
        printf("%c's turn \n", player);
        printf("Enter start and end positions separated by spaces: ");
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        if (is_valid_move(start_x, start_y, end_x, end_y, player)) {
            move_checker(start_x, start_y, end_x, end_y);
            // Check if any checkers should be "kinged"
            if (end_x == 0 && player == 'b') {
                board[end_x][end_y] = 'B';
            } else if (end_x == BOARD_SIZE - 1 && player == 'r') {
                board[end_x][end_y] = 'R';
            }
            if (is_game_over()) {
                game_over = 1;
            } else {
                player = (player == 'r') ? 'b' : 'r';
            }
        } else {
            printf("Invalid move! Try again. \n");
        }
    }
    print_board();
    printf("%c wins! \n", player);
    return 0;
}