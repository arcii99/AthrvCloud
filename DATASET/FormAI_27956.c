//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_ROWS 20
#define BOARD_COLS 20
#define PACMAN_ROW 10
#define PACMAN_COL 10
#define GHOST_ROW 5
#define GHOST_COL 5

// Define the game board and initialize it with dots
char board[BOARD_ROWS][BOARD_COLS] = {
    {"###################"},
    {"#.................#"},
    {"#.###.#.###.#.###.#"},
    {"#.#...#...#.#.#...#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.......#...#.#.#.#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.#...#.#.#.#...#.#"},
    {"#.###.#.#.#.#.###.#"},
    {"#........P........#"},
    {"#.###.#.#.#.#.###.#"},
    {"#.#...#.#.#.#...#.#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#...........#.#.#.#"},
    {"#.#########.#.#.#.#"},
    {"#.#.............#.#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.....#.#.#.#.#...#"},
    {"###.#.#.#.#.#.#.#.#"},
    {"###...............#"},
};

// Define the Pac-Man and ghost positions
int pacmanRow = PACMAN_ROW;
int pacmanCol = PACMAN_COL;
int ghostRow = GHOST_ROW;
int ghostCol = GHOST_COL;

// Define the game loop
int playGame() {
    int dotsRemaining = 0;
    int score = 0;

    // Count the number of dots remaining on the board
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            if (board[i][j] == '.') {
                dotsRemaining++;
            }
        }
    }

    // Play the game until all dots are eaten
    while (dotsRemaining > 0) {
        // Print the board
        for (int i = 0; i < BOARD_ROWS; i++) {
            printf("%s\n", board[i]);
        }
        printf("Score: %d\n", score);

        // Move the Pac-Man
        char direction;
        printf("Move Pac-Man (w,a,s,d): ");
        scanf(" %c", &direction);
        switch (direction) {
            case 'w':
                if (board[pacmanRow - 1][pacmanCol] != '#') {
                    if (board[pacmanRow - 1][pacmanCol] == '.') {
                        score += 10;
                        dotsRemaining--;
                    }
                    board[pacmanRow][pacmanCol] = ' ';
                    pacmanRow--;
                    board[pacmanRow][pacmanCol] = 'P';
                }
                break;
            case 'a':
                if (board[pacmanRow][pacmanCol - 1] != '#') {
                    if (board[pacmanRow][pacmanCol - 1] == '.') {
                        score += 10;
                        dotsRemaining--;
                    }
                    board[pacmanRow][pacmanCol] = ' ';
                    pacmanCol--;
                    board[pacmanRow][pacmanCol] = 'P';
                }
                break;
            case 's':
                if (board[pacmanRow + 1][pacmanCol] != '#') {
                    if (board[pacmanRow + 1][pacmanCol] == '.') {
                        score += 10;
                        dotsRemaining--;
                    }
                    board[pacmanRow][pacmanCol] = ' ';
                    pacmanRow++;
                    board[pacmanRow][pacmanCol] = 'P';
                }
                break;
            case 'd':
                if (board[pacmanRow][pacmanCol + 1] != '#') {
                    if (board[pacmanRow][pacmanCol + 1] == '.') {
                        score += 10;
                        dotsRemaining--;
                    }
                    board[pacmanRow][pacmanCol] = ' ';
                    pacmanCol++;
                    board[pacmanRow][pacmanCol] = 'P';
                }
                break;
        }

        // Move the ghost
        srand(time(NULL));
        int randomDirection = rand() % 4; // 0-3
        switch (randomDirection) {
            case 0:
                if (board[ghostRow - 1][ghostCol] != '#') {
                    board[ghostRow][ghostCol] = ' ';
                    ghostRow--;
                    board[ghostRow][ghostCol] = 'G';
                }
                break;
            case 1:
                if (board[ghostRow][ghostCol - 1] != '#') {
                    board[ghostRow][ghostCol] = ' ';
                    ghostCol--;
                    board[ghostRow][ghostCol] = 'G';
                }
                break;
            case 2:
                if (board[ghostRow + 1][ghostCol] != '#') {
                    board[ghostRow][ghostCol] = ' ';
                    ghostRow++;
                    board[ghostRow][ghostCol] = 'G';
                }
                break;
            case 3:
                if (board[ghostRow][ghostCol + 1] != '#') {
                    board[ghostRow][ghostCol] = ' ';
                    ghostCol++;
                    board[ghostRow][ghostCol] = 'G';
                }
                break;
        }

        // Check for collision
        if (pacmanRow == ghostRow && pacmanCol == ghostCol) {
            return score;
        }
    }

    return score;
}

// Define the main function
int main() {
    printf("Welcome to Pac-Man!\n");

    int score = playGame();

    printf("Game over! Final score: %d\n", score);

    return 0;
}