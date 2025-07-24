//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20
#define GHOSTS 4

void initialize_board(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]);
void print_board(char board[][COLS], int score, int lives);
void update_board(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]);
void move_ghost(char board[][COLS], int ghost_rows[], int ghost_cols[]);
void move_pacman(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, char direction);
int valid_move(char board[][COLS], int row, int col);
void check_collision(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]);

int main()
{
    char board[ROWS][COLS];
    int score = 0;
    int lives = 3;
    int pacman_row, pacman_col;
    int ghost_rows[GHOSTS], ghost_cols[GHOSTS];

    srand(time(NULL));

    initialize_board(board, &score, &lives, &pacman_row, &pacman_col, ghost_rows, ghost_cols);

    char direction;
    while (lives != 0) {
        print_board(board, score, lives);
        printf("Enter move (w,a,s,d): ");
        scanf(" %c", &direction);
        move_pacman(board, &score, &lives, &pacman_row, &pacman_col, direction);
        update_board(board, &score, &lives, &pacman_row, &pacman_col, ghost_rows, ghost_cols);
    }
    printf("Game Over!\n");
}

void initialize_board(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || (i == 7 && j >= 8 && j < 12)) {
                board[i][j] = '#';
            } else if ((i == 1 && j >= 1 && j <= 5) || (i == 1 && j >= 14 && j <= 18) ||
                       (i == 4 && j >= 6 && j <= 8) || (i == 4 && j >= 11 && j <= 13) ||
                       (i == 10 && j >= 1 && j <= 3) || (i == 10 && j >= 16 && j <= 18) ||
                       (i == 12 && j >= 6 && j <= 8) || (i == 12 && j >= 11 && j <= 13)) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
                *score += 1;
            }
        }
    }
    board[7][9] = 'C';
    board[1][1] = 'P';
    *pacman_row = 1;
    *pacman_col = 1;

    for (i = 0; i < GHOSTS; i++) {
        ghost_rows[i] = rand() % (ROWS - 2) + 1;
        ghost_cols[i] = rand() % (COLS - 2) + 1;
        board[ghost_rows[i]][ghost_cols[i]] = 'G';
    }
}

void print_board(char board[][COLS], int score, int lives) {
    int i, j;
    printf("\nScore: %d   Lives: %d\n\n", score, lives);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int valid_move(char board[][COLS], int row, int col) {
    if (board[row][col] != '#') {
        return 1;
    }
    return 0;
}

void move_pacman(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, char direction) {
    int new_row = *pacman_row;
    int new_col = *pacman_col;

    if (direction == 'w' && valid_move(board, *pacman_row - 1, *pacman_col)) {
        new_row--;
    } else if (direction == 'a' && valid_move(board, *pacman_row, *pacman_col - 1)) {
        new_col--;
    } else if (direction == 's' && valid_move(board, *pacman_row + 1, *pacman_col)) {
        new_row++;
    } else if (direction == 'd' && valid_move(board, *pacman_row, *pacman_col + 1)) {
        new_col++;
    }

    if (board[new_row][new_col] == '.') {
        *score += 1;
    } else if (board[new_row][new_col] == 'G') {
        *lives -= 1;
    } else if (board[new_row][new_col] == 'C') {
        *score += 10;
    }

    board[*pacman_row][*pacman_col] = '.';
    board[new_row][new_col] = 'P';

    *pacman_row = new_row;
    *pacman_col = new_col;
}

void move_ghost(char board[][COLS], int ghost_rows[], int ghost_cols[]) {
    int i;
    for (i = 0; i < GHOSTS; i++) {
        int direction = rand() % 4;
        int new_row = ghost_rows[i];
        int new_col = ghost_cols[i];

        if (direction == 0 && valid_move(board, ghost_rows[i] - 1, ghost_cols[i])) {
            new_row--;
        } else if (direction == 1 && valid_move(board, ghost_rows[i] + 1, ghost_cols[i])) {
            new_row++;
        } else if (direction == 2 && valid_move(board, ghost_rows[i], ghost_cols[i] - 1)) {
            new_col--;
        } else if (direction == 3 && valid_move(board, ghost_rows[i], ghost_cols[i] + 1)) {
            new_col++;
        }

        board[ghost_rows[i]][ghost_cols[i]] = '.';
        board[new_row][new_col] = 'G';

        ghost_rows[i] = new_row;
        ghost_cols[i] = new_col;
    }
}

void check_collision(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]) {
    int i;
    for (i = 0; i < GHOSTS; i++) {
        if (ghost_rows[i] == *pacman_row && ghost_cols[i] == *pacman_col) {
            *lives -= 1;
            printf("You ran into a ghost!\n");
            initialize_board(board, score, lives, pacman_row, pacman_col, ghost_rows, ghost_cols);
        }
    }
}

void update_board(char board[][COLS], int *score, int *lives, int *pacman_row, int *pacman_col, int ghost_rows[], int ghost_cols[]) {
    move_ghost(board, ghost_rows, ghost_cols);
    check_collision(board, score, lives, pacman_row, pacman_col, ghost_rows, ghost_cols);
}