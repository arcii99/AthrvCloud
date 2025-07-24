//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>

#define BOARD_SIZE 8

// Function to draw the checkers board
void draw_board(int board[][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char symbol;
            switch (board[i][j]) {
                case 0:
                    symbol = '-';
                    break;
                case 1:
                    symbol = 'x';
                    break;
                case 2:
                    symbol = 'o';
                    break;
                case 3:
                    symbol = 'X';
                    break;
                case 4:
                    symbol = 'O';
                    break;
            }
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

// Function to validate the movement of the checker
int is_valid_move(int board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    // Check if the from position is valid
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE || board[from_x][from_y] == 0) {
        printf("Invalid starting position.\n");
        return 0;
    }

    // Check if the to position is within the board
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        printf("Invalid ending position.\n");
        return 0;
    }

    // Check if the checker is moving diagonally
    if (from_x == to_x || from_y == to_y) {
        printf("Invalid move. Checkers must move diagonally.\n");
        return 0;
    }

    // Check if the checker is being moved to an empty space
    if (board[to_x][to_y] != 0) {
        printf("Illegal move. The target space is not empty.\n");
        return 0;
    }

    // Check if the checker is being moved to a valid position
    int direction = to_x - from_x;
    if (board[from_x][from_y] == 1) {
        if (direction != 1 || abs(to_y - from_y) != 1) {
            printf("Invalid move for x checker!\n");
            return 0;
        }
    } else if (board[from_x][from_y] == 2) {
        if (direction != -1 || abs(to_y - from_y) != 1) {
            printf("Invalid move for o checker!\n");
            return 0;
        }
    } else if (board[from_x][from_y] == 3 || board[from_x][from_y] == 4) {
        if (abs(to_x - from_x) != 1 || abs(to_y - from_y) != 1) {
            printf("Invalid move for king!\n");
            return 0;
        }
    }

    return 1;
}

// Function to move the checker on the board
void move_checker(int board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    // Update the board with the new position of the checker
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = 0;
}

// Function to check if the game is over
int is_game_over(int board[][BOARD_SIZE]) {
    int count_x = 0, count_o = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1 || board[i][j] == 3) {
                count_x++;
            } else if (board[i][j] == 2 || board[i][j] == 4) {
                count_o++;
            }
        }
    }
    if (count_x == 0 || count_o == 0) {
        return 1;
    }
    return 0;
}

// Function to convert the checker into king
void convert_to_king(int board[][BOARD_SIZE], int x, int y) {
    if (board[x][y] == 1 && x == BOARD_SIZE - 1) {
        board[x][y] = 3; // King x checker
    } else if (board[x][y] == 2 && x == 0) {
        board[x][y] = 4; // King o checker
    }
}

int main() {
    // Initialize the game board
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0}
    };

    int current_player = 1;
    int game_over = 0;
    int from_x, from_y, to_x, to_y;

    while (!game_over) {
        draw_board(board);
        printf("Player %d's move: \n", current_player);

        printf("Enter the position of the checker you want to move (row, column): ");
        scanf("%d,%d", &from_x, &from_y);

        printf("Enter the position where you want to move the checker (row, column): ");
        scanf("%d,%d", &to_x, &to_y);

        if (!is_valid_move(board, from_x - 1, from_y - 1, to_x - 1, to_y - 1)) {
            continue;
        }

        move_checker(board, from_x - 1, from_y - 1, to_x - 1, to_y - 1);

        // Check if the checker has been promoted to king
        convert_to_king(board, to_x - 1, to_y - 1);

        // Check if the game is over
        game_over = is_game_over(board);

        // Switch the turn to the other player
        if (current_player == 1) {
            current_player = 2;
        } else {
            current_player = 1;
        }
    }

    draw_board(board);

    if (current_player == 1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Player 1 wins!\n");
    }

    return 0;
}