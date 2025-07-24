//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];
int pacman_row, pacman_col;
int score = 0, lives = 3, level = 1;

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == pacman_row && j == pacman_col) {
                printf("P");
            } else if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int i, j;

    //initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                maze[i][j] = 1;
            }
        }
    }

    //initialize pacman location
    pacman_row = ROWS / 2;
    pacman_col = COLS / 2;

    //generate random pellets
    for (i = 0; i < ROWS * COLS / 3; ) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (maze[row][col] == 0) {
            maze[row][col] = 2;
            i++;
        }
    }

    //game loop
    while (lives > 0) {
        printf("Level %d\nScore: %d\nLives: %d\n", level, score, lives);
        print_maze();

        //get user input
        char input;
        printf("Enter move (w,a,s,d): ");
        scanf("%c", &input);
        getchar(); //consume newline

        //update pacman location
        switch (input) {
            case 'w': //up
                if (maze[pacman_row-1][pacman_col] != 1) {
                    pacman_row--;
                }
                break;
            case 'a': //left
                if (maze[pacman_row][pacman_col-1] != 1) {
                    pacman_col--;
                }
                break;
            case 's': //down
                if (maze[pacman_row+1][pacman_col] != 1) {
                    pacman_row++;
                }
                break;
            case 'd': //right
                if (maze[pacman_row][pacman_col+1] != 1) {
                    pacman_col++;
                }
                break;
            default:
                break;
        }

        //check for pellet
        if (maze[pacman_row][pacman_col] == 2) {
            score++;
            maze[pacman_row][pacman_col] = 0;
        }

        //check for game over
        if (score == ROWS * COLS / 3) {
            printf("You win!\n");
            break;
        } else if (input != 'w' && input != 'a' && input != 's' && input != 'd') {
            printf("Invalid input.\n");
        } else if (maze[pacman_row][pacman_col] == 1) {
            lives--;
            printf("You lost a life!\n");
            pacman_row = ROWS / 2;
            pacman_col = COLS / 2;
        }
    }

    return 0;
}