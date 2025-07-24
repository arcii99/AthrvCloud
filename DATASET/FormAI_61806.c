//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ROWS = 20;
int COLS = 20;

// Defining game board
int board[20][20];

// Direction variables
int up = 1, down = -1, left = 2, right = -2;

// Characters
char PACMAN = 'P';
char BLANK = '.';
char DOT = '*';
char WALL = '+';
char GHOST = 'G';

// Function to draw the board
void draw_board() {
    int i,j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            // Drawing outer walls
            if(i==0 || j==0 || i==ROWS-1 || j==COLS-1)
                printf("%c", WALL);
            
            // Drawing players
            else if(board[i][j]==PACMAN)
                printf("%c", PACMAN);
            else if(board[i][j]==GHOST)
                printf("%c", GHOST);
            
            // Drawing dots and empty cells
            else if(board[i][j]==DOT)
                printf("%c", DOT);
            else
                printf("%c", BLANK);
        }
        printf("\n");
    }
}

int main() {
    // Initializing board
    int i,j;
    for(i = 1; i < ROWS-1; i++) {
        for(j = 1; j < COLS-1; j++) {
            board[i][j] = DOT;
        }
    }

    // Creating a Pac-Man in the middle of the board
    board[ROWS/2][COLS/2] = PACMAN;

    // Adding two ghosts
    board[ROWS/3][COLS/3] = GHOST;
    board[ROWS/3][2*COLS/3] = GHOST;

    draw_board();

    return 0;
}