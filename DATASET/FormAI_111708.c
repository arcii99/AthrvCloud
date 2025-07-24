//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define NUM_PAC_DOTS 15
#define NUM_GHOSTS 3

int score = 0;
int pac_x, pac_y;
int ghost_x[NUM_GHOSTS], ghost_y[NUM_GHOSTS];
int dot_x[NUM_PAC_DOTS], dot_y[NUM_PAC_DOTS];

void print_board(int board[WIDTH][HEIGHT]) {
    printf("\nScore: %d\n\n", score);
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            if (i == pac_x && j == pac_y) {
                printf("P");
            } else if (board[i][j] == 1) {
                printf(".");
            } else if (board[i][j] == 2) {
                printf("G");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void move_pacman(char move, int board[WIDTH][HEIGHT]) {
    switch(move) {
        case 'w':
            if (pac_x-1 >= 0 && board[pac_x-1][pac_y] != 2) {
                pac_x--;
            }
            break;
        case 'a':
            if (pac_y-1 >= 0 && board[pac_x][pac_y-1] != 2) {
                pac_y--;
            }
            break;
        case 's':
            if (pac_x+1 < HEIGHT && board[pac_x+1][pac_y] != 2) {
                pac_x++;
            }
            break;
        case 'd':
            if (pac_y+1 < WIDTH && board[pac_x][pac_y+1] != 2) {
                pac_y++;
            }
            break;
    }
    if (board[pac_x][pac_y] == 1) {
        board[pac_x][pac_y] = 0;
        score++;
    }
}

void move_ghosts(int board[WIDTH][HEIGHT]) {
    for (int i=0; i<NUM_GHOSTS; i++) {
        if (ghost_x[i] < pac_x) {
            if (board[ghost_x[i]+1][ghost_y[i]] != 2) {
                ghost_x[i]++;
            }
        } else if (ghost_x[i] > pac_x) {
            if (board[ghost_x[i]-1][ghost_y[i]] != 2) {
                ghost_x[i]--;
            }
        }
        if (ghost_y[i] < pac_y) {
            if (board[ghost_x[i]][ghost_y[i]+1] != 2) {
                ghost_y[i]++;
            }
        } else if (ghost_y[i] > pac_y) {
            if (board[ghost_x[i]][ghost_y[i]-1] != 2) {
                ghost_y[i]--;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int board[WIDTH][HEIGHT];

    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            board[i][j] = 0;
        }
    }

    for (int i=0; i<NUM_PAC_DOTS; i++) {
        dot_x[i] = rand() % HEIGHT;
        dot_y[i] = rand() % WIDTH;
        board[dot_x[i]][dot_y[i]] = 1;
    }

    pac_x = rand() % HEIGHT;
    pac_y = rand() % WIDTH;

    for (int i=0; i<NUM_GHOSTS; i++) {
        ghost_x[i] = rand() % HEIGHT;
        ghost_y[i] = rand() % WIDTH;
        board[ghost_x[i]][ghost_y[i]] = 2;
    }

    char move;
    while (score < NUM_PAC_DOTS && board[pac_x][pac_y] != 2) {
        print_board(board);
        printf("Move Pac-Man (w, a, s, d): ");
        scanf("%c", &move);

        move_pacman(move, board);
        move_ghosts(board);
    }

    if (score == NUM_PAC_DOTS) {
        printf("You win!\n");
    } else {
        printf("You lose\n");
    }

    return 0;
}