//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define TARGET 2048
#define MAX_MOVES 100

int grid[GRID_SIZE][GRID_SIZE];
int score, moves;

void init_game() {
    int i, j;
    for (i=0; i<GRID_SIZE; i++) {
        for (j=0; j<GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    score = 0;
    moves = 0;

    int r1 = rand() % GRID_SIZE;
    int r2 = rand() % GRID_SIZE;
    grid[r1][r2] = (rand() % 2 + 1) * 2;
}

void print_game() {
    int i, j;
    printf("Score: %d Moves: %d\n\n", score, moves);
    printf("+-----+-----+-----+-----+\n");
    for (i=0; i<GRID_SIZE; i++) {
        printf("|");
        for (j=0; j<GRID_SIZE; j++) {
            if (grid[i][j] > 0) {
                printf("%-4d|", grid[i][j]);
            } else {
                printf("    |");
            }
        }
        printf("\n+-----+-----+-----+-----+\n");
    }
}

void move_left() {
    int i, j, k;
    for (i=0; i<GRID_SIZE; i++) {
        for (j=0; j<GRID_SIZE-1; j++) {
            for (k=j+1; k<GRID_SIZE; k++) {
                if (grid[i][j] == 0 && grid[i][k] > 0) {
                    grid[i][j] = grid[i][k];
                    grid[i][k] = 0;
                    break;
                } else if (grid[i][j] > 0 && grid[i][j] == grid[i][k]) {
                    grid[i][j] = grid[i][j] * 2;
                    grid[i][k] = 0;
                    score += grid[i][j];
                    break;
                } else if (grid[i][j] > 0 && grid[i][k] > 0) {
                    break;
                }
            }
        }
    }
}

void move_right() {
    int i, j, k;
    for (i=0; i<GRID_SIZE; i++) {
        for (j=GRID_SIZE-1; j>0; j--) {
            for (k=j-1; k>=0; k--) {
                if (grid[i][j] == 0 && grid[i][k] > 0) {
                    grid[i][j] = grid[i][k];
                    grid[i][k] = 0;
                    break;
                } else if (grid[i][j] > 0 && grid[i][j] == grid[i][k]) {
                    grid[i][j] = grid[i][j] * 2;
                    grid[i][k] = 0;
                    score += grid[i][j];
                    break;
                } else if (grid[i][j] > 0 && grid[i][k] > 0) {
                    break;
                }
            }
        }
    }
}

void move_up() {
    int i, j, k;
    for (j=0; j<GRID_SIZE; j++) {
        for (i=0; i<GRID_SIZE-1; i++) {
            for (k=i+1; k<GRID_SIZE; k++) {
                if (grid[i][j] == 0 && grid[k][j] > 0) {
                    grid[i][j] = grid[k][j];
                    grid[k][j] = 0;
                    break;
                } else if (grid[i][j] > 0 && grid[i][j] == grid[k][j]) {
                    grid[i][j] = grid[i][j] * 2;
                    grid[k][j] = 0;
                    score += grid[i][j];
                    break;
                } else if (grid[i][j] > 0 && grid[k][j] > 0) {
                    break;
                }
            }
        }
    }
}

void move_down() {
    int i, j, k;
    for (j=0; j<GRID_SIZE; j++) {
        for (i=GRID_SIZE-1; i>0; i--) {
            for (k=i-1; k>=0; k--) {
                if (grid[i][j] == 0 && grid[k][j] > 0) {
                    grid[i][j] = grid[k][j];
                    grid[k][j] = 0;
                    break;
                } else if (grid[i][j] > 0 && grid[i][j] == grid[k][j]) {
                    grid[i][j] = grid[i][j] * 2;
                    grid[k][j] = 0;
                    score += grid[i][j];
                    break;
                } else if (grid[i][j] > 0 && grid[k][j] > 0) {
                    break;
                }
            }
        }
    }
}

int is_gameover() {
    int i, j;
    for (i=0; i<GRID_SIZE; i++) {
        for (j=0; j<GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
            if (i>0 && grid[i][j] == grid[i-1][j]) {
                return 0;
            }
            if (i<GRID_SIZE-1 && grid[i][j] == grid[i+1][j]) {
                return 0;
            }
            if (j>0 && grid[i][j] == grid[i][j-1]) {
                return 0;
            }
            if (j<GRID_SIZE-1 && grid[i][j] == grid[i][j+1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    init_game();

    while (1) {
        print_game();

        if (is_gameover()) {
            printf("Game over! Final score: %d\n", score);
            break;
        }

        char move;
        printf("Enter move (l/r/u/d): ");
        scanf("%c", &move);

        switch (move) {
            case 'l':
                move_left();
                break;
            case 'r':
                move_right();
                break;
            case 'u':
                move_up();
                break;
            case 'd':
                move_down();
                break;
            default:
                printf("Invalid move!\n");
        }

        if (score >= TARGET) {
            printf("You win! Final score: %d\n", score);
            break;
        }

        moves++;
        if (moves >= MAX_MOVES) {
            printf("Maximum moves reached. Final score: %d\n", score);
            break;
        }
    }

    return 0;
}