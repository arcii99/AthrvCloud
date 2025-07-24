//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: rigorous
#include <stdio.h>

// Defining constants
#define NROWS 20
#define NCOLS 20
#define BLANK ' '
#define PACMAN 'C'
#define DOT '.'
#define GHOST 'G'

// Function to print the game board
void print_board(char board[NROWS][NCOLS]) {
    int i, j;
    for (i = 0; i < NROWS; i++) {
        for (j = 0; j < NCOLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board
void init_board(char board[NROWS][NCOLS]) {
    int i, j;
    for (i = 0; i < NROWS; i++) {
        for (j = 0; j < NCOLS; j++) {
            if (i == 0 || i == NROWS-1 || j == 0 || j == NCOLS-1) {
                board[i][j] = '-';
            } else {
                board[i][j] = BLANK;
            }
        }
    }
    board[NROWS/2][NCOLS/2] = PACMAN;
    for (i = 1; i < NROWS-1; i++) {
        for (j = 1; j < NCOLS-1; j++) {
            if ((i+j) % 3 == 0) {
                board[i][j] = DOT;
            }
        }
    }
    board[NROWS/2+1][NCOLS/2] = board[NROWS/2][NCOLS/2+1] = board[NROWS/2-1][NCOLS/2] = board[NROWS/2][NCOLS/2-1] = GHOST;
}

// Main function to run the game
int main() {
    char board[NROWS][NCOLS];
    int score = 0;
    int i, j;
    int pacman_x = NROWS/2, pacman_y = NCOLS/2;
    int ghost_x = NROWS/2+1, ghost_y = NCOLS/2;
    int game_over = 0;
    char direction;
    init_board(board);
    printf("Welcome to Pacman!\n");
    while (!game_over) {
        printf("Score: %d\n", score);
        print_board(board);
        printf("Enter direction (w/a/s/d): ");
        scanf(" %c", &direction);
        switch (direction) {
            case 'w':
                if (board[pacman_x-1][pacman_y] != '-') {
                    if (board[pacman_x-1][pacman_y] == DOT) {
                        score++;
                    }
                    board[pacman_x-1][pacman_y] = PACMAN;
                    board[pacman_x][pacman_y] = BLANK;
                    pacman_x--;
                }
                break;
            case 'a':
                if (board[pacman_x][pacman_y-1] != '-') {
                    if (board[pacman_x][pacman_y-1] == DOT) {
                        score++;
                    }
                    board[pacman_x][pacman_y-1] = PACMAN;
                    board[pacman_x][pacman_y] = BLANK;
                    pacman_y--;
                }
                break;
            case 's':
                if (board[pacman_x+1][pacman_y] != '-') {
                    if (board[pacman_x+1][pacman_y] == DOT) {
                        score++;
                    }
                    board[pacman_x+1][pacman_y] = PACMAN;
                    board[pacman_x][pacman_y] = BLANK;
                    pacman_x++;
                }
                break;
            case 'd':
                if (board[pacman_x][pacman_y+1] != '-') {
                    if (board[pacman_x][pacman_y+1] == DOT) {
                        score++;
                    }
                    board[pacman_x][pacman_y+1] = PACMAN;
                    board[pacman_x][pacman_y] = BLANK;
                    pacman_y++;
                }
                break;
            default:
                printf("Invalid direction!\n");
                break;
        }
        if (pacman_x == ghost_x && pacman_y == ghost_y) {
            game_over = 1;
            printf("Game over!\n");
        } else {
            board[ghost_x][ghost_y] = BLANK;
            if (pacman_x < ghost_x) {
                ghost_x--;
            } else if (pacman_x > ghost_x) {
                ghost_x++;
            }
            if (pacman_y < ghost_y) {
                ghost_y--;
            } else if (pacman_y > ghost_y) {
                ghost_y++;
            }
            board[ghost_x][ghost_y] = GHOST;
        }
        if (score == NROWS * NCOLS / 3) {
            game_over = 1;
            printf("You win!\n");
        }
    }
    print_board(board);
    return 0;
}