//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: interoperable
#include <stdio.h>

#define ROWS 9
#define COLS 15

enum Direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

char gameBoard[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
        {'#','#','#',' ','#',' ','#','#','#',' ',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#','#'},
        {'#',' ','#','#','#','#','#',' ','#',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ','#',' ','#',' ','#','#','#',' ','#'},
        {'#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

void drawBoard() {
    // Display the game board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int pacmanRow = 4, pacmanCol = 8;
    int ghostRow = 4, ghostCol = 6;
    enum Direction pacmanDir = LEFT;

    // Draw the initial game board
    drawBoard();
    
    // Game loop
    while(1) {
        // Move pacman
        if(pacmanDir == LEFT) {
            if(gameBoard[pacmanRow][pacmanCol-1] != '#') {
                gameBoard[pacmanRow][pacmanCol] = ' ';
                pacmanCol--;
                gameBoard[pacmanRow][pacmanCol] = 'C';
            }
        }
        else if(pacmanDir == RIGHT) {
            if(gameBoard[pacmanRow][pacmanCol+1] != '#') {
                gameBoard[pacmanRow][pacmanCol] = ' ';
                pacmanCol++;
                gameBoard[pacmanRow][pacmanCol] = 'C';
            }
        }
        else if(pacmanDir == UP) {
            if(gameBoard[pacmanRow-1][pacmanCol] != '#') {
                gameBoard[pacmanRow][pacmanCol] = ' ';
                pacmanRow--;
                gameBoard[pacmanRow][pacmanCol] = 'C';
            }
        }
        else if(pacmanDir == DOWN) {
            if(gameBoard[pacmanRow+1][pacmanCol] != '#') {
                gameBoard[pacmanRow][pacmanCol] = ' ';
                pacmanRow++;
                gameBoard[pacmanRow][pacmanCol] = 'C';
            }
        }

        // Move ghost
        if(ghostCol < pacmanCol) {
            if(gameBoard[ghostRow][ghostCol+1] != '#') {
                gameBoard[ghostRow][ghostCol] = ' ';
                ghostCol++;
                gameBoard[ghostRow][ghostCol] = 'G';
            }
        }
        else if(ghostCol > pacmanCol) {
            if(gameBoard[ghostRow][ghostCol-1] != '#') {
                gameBoard[ghostRow][ghostCol] = ' ';
                ghostCol--;
                gameBoard[ghostRow][ghostCol] = 'G';
            }
        }
        else if(ghostRow < pacmanRow) {
            if(gameBoard[ghostRow+1][ghostCol] != '#') {
                gameBoard[ghostRow][ghostCol] = ' ';
                ghostRow++;
                gameBoard[ghostRow][ghostCol] = 'G';
            }
        }
        else if(ghostRow > pacmanRow) {
            if(gameBoard[ghostRow-1][ghostCol] != '#') {
                gameBoard[ghostRow][ghostCol] = ' ';
                ghostRow--;
                gameBoard[ghostRow][ghostCol] = 'G';
            }
        }

        // Check for collision
        if(pacmanRow == ghostRow && pacmanCol == ghostCol) {
            printf("\nGame Over!\n");
            break;
        }

        // Draw the updated game board
        printf("\033[2J\033[1;1H"); // Clear the console
        drawBoard();

        // Get user input
        char input;
        scanf(" %c", &input);
        if(input == 'q') break; // Quit the game
        else if(input == 'h') pacmanDir = LEFT;
        else if(input == 'l') pacmanDir = RIGHT;
        else if(input == 'k') pacmanDir = UP;
        else if(input == 'j') pacmanDir = DOWN;
    }

    return 0;
}