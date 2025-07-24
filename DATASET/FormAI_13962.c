//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: funny
#include <stdio.h>

int main ()
{
    printf("Welcome to the 'Spacex Invaders' game clone!\n");
    
    printf("Instructions:\n");
    printf("Use arrow keys to move your rocket 'Elon' around and shoot the aliens with the space key.\n");
    printf("The game will end if you lose all your lives or defeat all the aliens in level 10.\n");
    
    // Setting up the game board
    char board[20][40];
    int numRows = sizeof(board) / sizeof(board[0]);
    int numCols = sizeof(board[0]);
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == numRows - 1) {
                board[i][j] = '_';
            } else if (j == 0 || j == numCols - 1) {
                board[i][j] = '|';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    
    // Initial position of 'Elon'
    int elonRow = numRows - 2;
    int elonCol = numCols / 2;
    
    // Print the initial game board
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
    // Variables for the game loop
    int level = 1;
    int score = 0;
    int lives = 3;
    int alienSpeed = 1;
    int numAliens = 10;
    int alienRows = 3;
    char alien = '<';
    
    while (numAliens > 0 && lives > 0 && level <= 10) {
        // Move Elon based on user input
        char input = getchar();
        if (input == '\033') {
            getchar(); 
            switch(getchar()) {
                case 'A':
                    if (elonRow > 0) {
                        elonRow--;
                    }
                    break;
                case 'B':
                    if (elonRow < numRows - 2) {
                        elonRow++;
                    }
                    break;
                case 'C':
                    if (elonCol < numCols - 2) {
                        elonCol++;
                    }
                    break;
                case 'D':
                    if (elonCol > 1) {
                        elonCol--;
                    }
                    break;
            }
        } else if (input == ' ') {
            // Add a rocket to the board and check for collisions with aliens
            board[elonRow - 1][elonCol] = '^';
            for (int i = 0; i < alienRows; i++) {
                for (int j = 1; j <= numAliens; j++) {
                    if (board[i][j] == alien) {
                        if (elonRow - 1 == i && elonCol == j) {
                            lives--;
                            printf("Elon has been hit! You have %d lives left.\n", lives);
                        }
                        board[i][j] = ' ';
                        score++;
                        numAliens--;
                    }
                }
            }
        }
        
        // Move the aliens down, increase their speed, and check for collisions with Elon
        for (int i = 0; i < alienRows; i++) {
            for (int j = 1; j <= numAliens; j++) {
                if (board[i][j] == alien) {
                    if (i == numRows - 2) {
                        lives--;
                        printf("A rocket has hit your base! You have %d lives left.\n", lives);
                        board[i][j] = ' ';
                        numAliens--;
                    } else {
                        board[i][j] = ' ';
                        board[i + alienSpeed][j] = alien;
                        if (i + alienSpeed == elonRow && j == elonCol) {
                            lives--;
                            printf("Elon has been hit! You have %d lives left.\n", lives);
                        }
                    }
                }
            }
        }
        
        // Print the updated game board and display game stats
        printf("Level %d | Score: %d | Lives: %d | Aliens: %d\n", level, score, lives, numAliens);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
    }
    
    // Determine the end of game status
    if (numAliens == 0) {
        printf("Congratulations, Elon! You have defeated all the aliens and saved planet Earth!\n");
    } else if (lives == 0) {
        printf("Game over, Elon. You have let the aliens invade planet Earth. Try again and don't mess it up this time!\n");
    } else {
        printf("You have successfully completed the game! We hope you had fun playing 'Spacex Invaders'!\n");
    }
    
    return 0;
}