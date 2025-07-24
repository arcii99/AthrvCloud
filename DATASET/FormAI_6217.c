//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 23
#define COLS 31
#define GHOSTS 4
#define PACMAN 'P'
#define EMPTY ' '
#define DOT '.'
#define GHOST 'G'

typedef struct {
    int x;
    int y;
} Coordinate;

void initializeBoard(char board[ROWS][COLS], int *score) {
    int i, j;
    *score = 0;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || (i == 11 && j > 10 && j < 20)) {
                board[i][j] = '#';
            } else if((i == 3 || i == 19) && j > 4 && j < 26) {
                board[i][j] = '-';
            } else if(i >= 4 && i <= 18 && (j == 5 || j == 25)) {
                board[i][j] = '|';
            } else if((i == 10 && j == 13) || (i == 12 && j == 17)) {
                board[i][j] = DOT;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(char board[ROWS][COLS], int score) {
    int i, j;
    system("clear");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

int validMove(char board[ROWS][COLS], Coordinate c) {
    return board[c.x][c.y] != '#';
}

Coordinate updateCoordinate(Coordinate c, char direction) {
    Coordinate newCoordinate = {c.x, c.y};
    switch(direction) {
        case 'w':
            newCoordinate.x--;
            break;
        case 'a':
            newCoordinate.y--;
            break;
        case 's':
            newCoordinate.x++;
            break;
        case 'd':
            newCoordinate.y++;
            break;
    }
    return newCoordinate;
}

int isDot(char c) {
    return c == DOT;
}

void moveGhost(char board[ROWS][COLS], Coordinate ghosts[GHOSTS]) {
    int i;
    for(i = 0; i < GHOSTS; i++) {
        Coordinate newCoordinate;
        do {
            int direction = rand() % 4;
            switch(direction) {
                case 0:
                    newCoordinate = updateCoordinate(ghosts[i], 'w');
                    break;
                case 1:
                    newCoordinate = updateCoordinate(ghosts[i], 'a');
                    break;
                case 2:
                    newCoordinate = updateCoordinate(ghosts[i], 's');
                    break;
                case 3:
                    newCoordinate = updateCoordinate(ghosts[i], 'd');
                    break;
            }
        } while(!validMove(board, newCoordinate));
        if(board[newCoordinate.x][newCoordinate.y] != PACMAN) {
            board[ghosts[i].x][ghosts[i].y] = EMPTY;
            ghosts[i] = newCoordinate;
            board[ghosts[i].x][ghosts[i].y] = GHOST;
        }
    }
}

int main() {
    char board[ROWS][COLS];
    Coordinate pacman = {11, 16};
    Coordinate ghosts[GHOSTS] = {{11, 14}, {11, 15}, {11, 17}, {11, 18}};
    int score;
    char direction;
    srand(time(NULL));
    initializeBoard(board, &score);
    board[pacman.x][pacman.y] = PACMAN;
    int numDots = 0;
    int dotsLeft = 0;
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(isDot(board[i][j])) {
                numDots++;
            }
        }
    }
    dotsLeft = numDots;
    while(score < 10 * numDots) {
        printBoard(board, score);
        direction = tolower(getchar());
        Coordinate newCoordinate = updateCoordinate(pacman, direction);
        if(validMove(board, newCoordinate)) {
            if(isDot(board[newCoordinate.x][newCoordinate.y])) {
                score++;
                dotsLeft--;
            }
            board[pacman.x][pacman.y] = EMPTY;
            pacman = newCoordinate;
            board[pacman.x][pacman.y] = PACMAN;
            if(!dotsLeft) {
                break;
            }
        }
        moveGhost(board, ghosts);
        for(i = 0; i < GHOSTS; i++) {
            if(board[ghosts[i].x][ghosts[i].y] == PACMAN) {
                printf("You lose!\n");
                return 0;
            }
        }
    }
    printf("You win!\n");
    return 0;
}