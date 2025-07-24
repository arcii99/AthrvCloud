//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

#define PACMAN 'O'
#define WALL '#'
#define DOT '.'
#define EMPTY ' '
#define GHOST 'X'

void print_board(char board[][COLS]);
void generate_dots(char board[][COLS]);
void move_pacman(char board[][COLS], int direction, int* row, int* col);
bool is_ghost_in_direction(char board[][COLS], int direction, int row, int col);
void move_ghosts(char board[][COLS], int ghost_rows[], int ghost_cols[]);
void move_ghost(char board[][COLS], int* row, int* col);
void handle_collision(char board[][COLS], int* pacman_row, int* pacman_col, int* score);
void win_game(int score);
void lose_game();

int main()
{
    char board[ROWS][COLS];
    int pacman_row = ROWS / 2;
    int pacman_col = COLS / 2;
    int ghost_rows[3] = {1, 1, ROWS - 2};
    int ghost_cols[3] = {1, COLS - 2, COLS - 2};
    int score = 0;
    int direction;
    srand(time(NULL));

    // Initialize board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = WALL;
            }
        }
    }
    generate_dots(board);
    board[pacman_row][pacman_col] = PACMAN;
    for (int i = 0; i < 3; i++) {
        board[ghost_rows[i]][ghost_cols[i]] = GHOST;
    }
    print_board(board);

    while (true) {
        printf("Enter direction (1: up, 2: right, 3: down, 4: left): ");
        scanf("%d", &direction);
        move_pacman(board, direction, &pacman_row, &pacman_col);
        handle_collision(board, &pacman_row, &pacman_col, &score);
        move_ghosts(board, ghost_rows, ghost_cols);
        handle_collision(board, &pacman_row, &pacman_col, &score);
        print_board(board);
        if (score == ROWS * COLS - 4) {  // Subtracting number of walls
            win_game(score);
            break;
        }
        if (is_ghost_in_direction(board, 0, pacman_row, pacman_col) ||
            is_ghost_in_direction(board, 1, pacman_row, pacman_col) ||
            is_ghost_in_direction(board, 2, pacman_row, pacman_col) ||
            is_ghost_in_direction(board, 3, pacman_row, pacman_col)) {
            lose_game();
            break;
        }
    }

    return 0;
}

void print_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generate_dots(char board[][COLS])
{
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            if (board[i][j] != WALL) {
                if (rand() % 5 == 0) {
                    board[i][j] = DOT;
                }
            }
        }
    }
}

void move_pacman(char board[][COLS], int direction, int* row, int* col)
{
    switch (direction) {
    case 1:
        if (board[*row - 1][*col] != WALL) {
            board[*row][*col] = EMPTY;
            (*row)--;
        }
        break;
    case 2:
        if (board[*row][*col + 1] != WALL) {
            board[*row][*col] = EMPTY;
            (*col)++;
        }
        break;
    case 3:
        if (board[*row + 1][*col] != WALL) {
            board[*row][*col] = EMPTY;
            (*row)++;
        }
        break;
    case 4:
        if (board[*row][*col - 1] != WALL) {
            board[*row][*col] = EMPTY;
            (*col)--;
        }
        break;
    }
    board[*row][*col] = PACMAN;
}

bool is_ghost_in_direction(char board[][COLS], int direction, int row, int col)
{
    switch (direction) {
    case 0:
        return (board[row - 1][col] == GHOST);
    case 1:
        return (board[row][col + 1] == GHOST);
    case 2:
        return (board[row + 1][col] == GHOST);
    case 3:
        return (board[row][col - 1] == GHOST);
    default:
        return false;
    }
}

void move_ghosts(char board[][COLS], int ghost_rows[], int ghost_cols[])
{
    for (int i = 0; i < 3; i++) {
        move_ghost(board, &ghost_rows[i], &ghost_cols[i]);
    }
}

void move_ghost(char board[][COLS], int* row, int* col)
{
    // Move in random direction
    int direction = rand() % 4;
    switch (direction) {
    case 0:
        if (board[*row - 1][*col] != WALL && board[*row - 1][*col] != GHOST) {
            board[*row][*col] = EMPTY;
            (*row)--;
        }
        break;
    case 1:
        if (board[*row][*col + 1] != WALL && board[*row][*col + 1] != GHOST) {
            board[*row][*col] = EMPTY;
            (*col)++;
        }
        break;
    case 2:
        if (board[*row + 1][*col] != WALL && board[*row + 1][*col] != GHOST) {
            board[*row][*col] = EMPTY;
            (*row)++;
        }
        break;
    case 3:
        if (board[*row][*col - 1] != WALL && board[*row][*col - 1] != GHOST) {
            board[*row][*col] = EMPTY;
            (*col)--;
        }
        break;
    }
    board[*row][*col] = GHOST;
}

void handle_collision(char board[][COLS], int* pacman_row, int* pacman_col, int* score)
{
    switch (board[*pacman_row][*pacman_col]) {
    case DOT:
        (*score)++;
        break;
    }
    board[*pacman_row][*pacman_col] = PACMAN;
}

void win_game(int score)
{
    printf("Congratulations! You completed the game with a score of %d\n", score);
}

void lose_game()
{
    printf("Game over! You were eaten by the ghosts :(\n");
}