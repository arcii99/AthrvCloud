//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global constants
#define WIDTH 40
#define HEIGHT 20
#define GHOSTS 4
#define GHOST_CHAR 'G'
#define PACMAN_CHAR 'P'
#define PELLET_CHAR '.'

// function prototypes
void init_board(char board[HEIGHT][WIDTH]);
void print_board(char board[HEIGHT][WIDTH]);
void move_pacman(char board[HEIGHT][WIDTH], int direction);
void move_ghosts(char board[HEIGHT][WIDTH]);
void spawn_ghosts(char board[HEIGHT][WIDTH]);
void check_collisions(char board[HEIGHT][WIDTH]);

// main function
int main(void) {
    char board[HEIGHT][WIDTH];
    int direction = 0;
    srand(time(0));

    init_board(board);
    spawn_ghosts(board);

    while (1) {
        print_board(board);
        printf("Choose a direction (0 up, 1 right, 2 down, 3 left): ");
        scanf("%d", &direction);
        move_pacman(board, direction);
        move_ghosts(board);
        check_collisions(board);
    }

    return 0;
}

// function definitions
void init_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = '#';
            } else if (rand() % 10 < 2) {
                board[i][j] = PELLET_CHAR;
            } else {
                board[i][j] = ' ';
            }
        }
    }
    board[HEIGHT / 2][WIDTH / 2] = PACMAN_CHAR;
}

void print_board(char board[HEIGHT][WIDTH]) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", board[i]);
    }
}

void move_pacman(char board[HEIGHT][WIDTH], int direction) {
    int current_row, current_col;
    int next_row, next_col;

    // find current position of pacman
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == PACMAN_CHAR) {
                current_row = i;
                current_col = j;
            }
        }
    }

    // compute next position based on direction
    switch (direction) {
        case 0:
            next_row = current_row - 1;
            next_col = current_col;
            break;
        case 1:
            next_row = current_row;
            next_col = current_col + 1;
            break;
        case 2:
            next_row = current_row + 1;
            next_col = current_col;
            break;
        case 3:
            next_row = current_row;
            next_col = current_col - 1;
            break;
        default:
            printf("Invalid direction\n");
            return;
    }

    // update board with new position of pacman
    if (board[next_row][next_col] == GHOST_CHAR) {
        printf("Game over!\n");
        exit(0);
    } else if (board[next_row][next_col] != '#') {
        board[current_row][current_col] = ' ';
        board[next_row][next_col] = PACMAN_CHAR;
    }
}

void spawn_ghosts(char board[HEIGHT][WIDTH]) {
    int row, col;
    for (int i = 0; i < GHOSTS; i++) {
        row = rand() % (HEIGHT - 2) + 1;
        col = rand() % (WIDTH - 2) + 1;
        while (board[row][col] != ' ') {
            row = rand() % (HEIGHT - 2) + 1;
            col = rand() % (WIDTH - 2) + 1;
        }
        board[row][col] = GHOST_CHAR;
    }
}

void move_ghosts(char board[HEIGHT][WIDTH]) {
    int current_row, current_col;
    int next_row, next_col;

    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            if (board[i][j] != GHOST_CHAR) {
                continue;
            }

            current_row = i;
            current_col = j;

            // move randomly to a neighboring cell
            switch (rand() % 4) {
                case 0:
                    next_row = current_row - 1;
                    next_col = current_col;
                    break;
                case 1:
                    next_row = current_row;
                    next_col = current_col + 1;
                    break;
                case 2:
                    next_row = current_row + 1;
                    next_col = current_col;
                    break;
                case 3:
                    next_row = current_row;
                    next_col = current_col - 1;
                    break;
            }

            // update board with new position of ghost
            if (board[next_row][next_col] == PACMAN_CHAR) {
                printf("Game over!\n");
                exit(0);
            } else if (board[next_row][next_col] != '#' && board[next_row][next_col] != GHOST_CHAR) {
                board[current_row][current_col] = ' ';
                board[next_row][next_col] = GHOST_CHAR;
            }
        }
    }
}

void check_collisions(char board[HEIGHT][WIDTH]) {
    int pellets = 0;
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            if (board[i][j] == PELLET_CHAR) {
                pellets++;
            }
        }
    }
    if (pellets == 0) {
        printf("You win!\n");
        exit(0);
    }
}