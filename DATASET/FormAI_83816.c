//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

// Function to initialize the game board
void initializeBoard(char board[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the game board
void printBoard(char board[][COL]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROW; i++) {
        printf(" ");
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to place Pacman on the board
void placePacman(char board[][COL], int *r, int *c) {
    int i, j;
    bool placed = false;
    while (!placed) {
        i = rand() % ROW;
        j = rand() % COL;
        if (board[i][j] == '-') {
            board[i][j] = 'P';
            *r = i;
            *c = j;
            placed = true;
        }
    }
}

// Function to place Ghosts on the board
void placeGhosts(char board[][COL]) {
    int i, j;
    for (int g = 0; g < 3; g++) {
        bool placed = false;
        while (!placed) {
            i = rand() % ROW;
            j = rand() % COL;
            if (board[i][j] == '-') {
                board[i][j] = 'G';
                placed = true;
            }
        }
    }
}

// Function to move Pacman
void movePacman(char board[][COL], int *r, int *c) {
    int move;
    printf("Enter move (1=up, 2=down, 3=left, 4=right): ");
    scanf("%d", &move);
    switch (move) {
        case 1:
            if (*r > 0 && board[*r-1][*c] != 'G') {
                board[*r][*c] = '-';
                board[*r-1][*c] = 'P';
                (*r)--;
            }
            break;
        case 2:
            if (*r < ROW-1 && board[*r+1][*c] != 'G') {
                board[*r][*c] = '-';
                board[*r+1][*c] = 'P';
                (*r)++;
            }
            break;
        case 3:
            if (*c > 0 && board[*r][*c-1] != 'G') {
                board[*r][*c] = '-';
                board[*r][*c-1] = 'P';
                (*c)--;
            }
            break;
        case 4:
            if (*c < COL-1 && board[*r][*c+1] != 'G') {
                board[*r][*c] = '-';
                board[*r][*c+1] = 'P';
                (*c)++;
            }
            break;
    }
}

// Function to move ghosts
void moveGhosts(char board[][COL], int pr, int pc) {
    int gr, gc;
    for (int g = 0; g < 3; g++) {
        bool moved = false;
        while (!moved) {
            int dir = rand() % 4 + 1;
            gr = rand() % ROW;
            gc = rand() % COL;
            if (dir == 1) {
                if (gr > 0 && board[gr-1][gc] != 'G' && gr-1 != pr) {
                    board[gr][gc] = '-';
                    board[gr-1][gc] = 'G';
                    moved = true;
                }
            }
            else if (dir == 2) {
                if (gr < ROW-1 && board[gr+1][gc] != 'G' && gr+1 != pr) {
                    board[gr][gc] = '-';
                    board[gr+1][gc] = 'G';
                    moved = true;
                }
            }
            else if (dir == 3) {
                if (gc > 0 && board[gr][gc-1] != 'G' && gc-1 != pc) {
                    board[gr][gc] = '-';
                    board[gr][gc-1] = 'G';
                    moved = true;
                }
            }
            else if (dir == 4) {
                if (gc < COL-1 && board[gr][gc+1] != 'G' && gc+1 != pc) {
                    board[gr][gc] = '-';
                    board[gr][gc+1] = 'G';
                    moved = true;
                }
            }
        }
    }
}

// Main function
int main() {
    char board[ROW][COL];
    int pacRow, pacCol;
    srand(time(0));
    initializeBoard(board);
    placePacman(board, &pacRow, &pacCol);
    placeGhosts(board);
    printBoard(board);
    while (true) {
        movePacman(board, &pacRow, &pacCol);
        moveGhosts(board, pacRow, pacCol);
        printBoard(board);
    }
    return 0;
}