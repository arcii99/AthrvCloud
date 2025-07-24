//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define COLS 20
#define ROWS 20

char board[ROWS][COLS];
int pacman[2];
int ghosts[10][2];
int num_ghosts = 1;
int score = 0;
bool game_over = false;

void init_board() {
    // fill the board with dots and walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
            }
        }
    }
    
    // place pacman in the middle
    pacman[0] = ROWS / 2;
    pacman[1] = COLS / 2;
    board[pacman[0]][pacman[1]] = 'P';
    
    // place ghosts randomly
    srand(time(NULL));
    for (int i = 0; i < num_ghosts; i++) {
        ghosts[i][0] = rand() % (ROWS - 2) + 1;
        ghosts[i][1] = rand() % (COLS - 2) + 1;
        board[ghosts[i][0]][ghosts[i][1]] = 'G';
    }
}

void print_board() {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void move_pacman() {
    char input;
    scanf(" %c", &input);
    int new_row = pacman[0];
    int new_col = pacman[1];
    switch (input) {
        case 'w':
            new_row--;
            break;
        case 'a':
            new_col--;
            break;
        case 's':
            new_row++;
            break;
        case 'd':
            new_col++;
            break;
    }
    if (board[new_row][new_col] != '#') {
        if (board[new_row][new_col] == '.') {
            score++;
        }
        board[pacman[0]][pacman[1]] = '.';
        pacman[0] = new_row;
        pacman[1] = new_col;
        board[pacman[0]][pacman[1]] = 'P';
    }
}

void move_ghost(int i) {
    int row_diff = pacman[0] - ghosts[i][0];
    int col_diff = pacman[1] - ghosts[i][1];
    int new_row = ghosts[i][0] + (row_diff > 0 ? 1 : -1);
    int new_col = ghosts[i][1] + (col_diff > 0 ? 1 : -1);
    if (board[new_row][new_col] != '#') {
        if (new_row == pacman[0] && new_col == pacman[1]) {
            game_over = true;
        }
        board[ghosts[i][0]][ghosts[i][1]] = '.';
        ghosts[i][0] = new_row;
        ghosts[i][1] = new_col;
        board[ghosts[i][0]][ghosts[i][1]] = 'G';
    }
}

void move_ghosts() {
    for (int i = 0; i < num_ghosts; i++) {
        move_ghost(i);
    }
}

int main() {
    init_board();
    while (!game_over) {
        print_board();
        printf("Score: %d\n", score);
        move_pacman();
        move_ghosts();
    }
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}