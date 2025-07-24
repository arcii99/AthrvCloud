//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: scalable
#include <stdio.h>

// Constants
#define ROWS 20
#define COLUMNS 20
#define EMPTY 0
#define PACMAN 1
#define DOT 2

// Directions
enum directions { UP, DOWN, LEFT, RIGHT };

// Global variables
int board[ROWS][COLUMNS];
int score = 0;
int xPacman, yPacman;
int dotsRemaining = 0;

// Function prototypes
void initBoard();
void printBoard();
int tryMove(int direction);
void movePacman(int direction);
void eatDot(int row, int column);

int main() {
    initBoard();
    printBoard();

    int gameover = 0;
    while (!gameover) {
        int direction;
        printf("Enter direction (0=up, 1=down, 2=left, 3=right): ");
        scanf("%d", &direction);

        int canMove = tryMove(direction);
        if (canMove) {
            movePacman(direction);

            if (board[xPacman][yPacman] == DOT) {
                eatDot(xPacman, yPacman);
                dotsRemaining--;
                score++;

                if (dotsRemaining == 0) {
                    printf("You win! Final score: %d\n", score);
                    gameover = 1;
                }
            }

            printBoard();
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}

void initBoard() {
    // Initialize board to all empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Create walls around the edges
    for (int i = 0; i < ROWS; i++) {
        board[i][0] = 1;
        board[i][COLUMNS-1] = 1;
    }
    for (int i = 0; i < COLUMNS; i++) {
        board[0][i] = 1;
        board[ROWS-1][i] = 1;
    }

    // Create dots for Pac-Man to eat
    for (int i = 1; i < ROWS-1; i++) {
        for (int j = 1; j < COLUMNS-1; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i][j] = DOT;
                dotsRemaining++;
            }
        }
    }

    // Place Pac-Man in the center
    xPacman = ROWS / 2;
    yPacman = COLUMNS / 2;
    board[xPacman][yPacman] = PACMAN;
}

void printBoard() {
    system("clear"); // Clear screen

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == EMPTY) {
                printf(" ");
            } else if (board[i][j] == PACMAN) {
                printf("C");
            } else if (board[i][j] == DOT) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

int tryMove(int direction) {
    int xNew = xPacman;
    int yNew = yPacman;

    if (direction == UP) {
        xNew--;
    } else if (direction == DOWN) {
        xNew++;
    } else if (direction == LEFT) {
        yNew--;
    } else if (direction == RIGHT) {
        yNew++;
    }

    if (board[xNew][yNew] == 1) {
        return 0; // hit a wall
    } else {
        return 1; // can move
    }
}

void movePacman(int direction) {
    board[xPacman][yPacman] = EMPTY;

    if (direction == UP) {
        xPacman--;
    } else if (direction == DOWN) {
        xPacman++;
    } else if (direction == LEFT) {
        yPacman--;
    } else if (direction == RIGHT) {
        yPacman++;
    }

    board[xPacman][yPacman] = PACMAN;
}

void eatDot(int row, int column) {
    board[row][column] = EMPTY;
}