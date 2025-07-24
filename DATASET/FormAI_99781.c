//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare the space invaders map
int map[5][10] = {{0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,1,0,0,0,0},
                  {0,0,0,1,0,0,0,1,0,0},
                  {0,0,1,0,0,0,0,0,1,0},
                  {0,1,0,0,0,0,0,0,0,1}
                 };
int score = 0;
int moves = 0;
int playerRow = 4;
int playerCol = 5;

// Function that prints the current state of the game
void printGame() {
    printf("\nScore: %d | Moves: %d\n", score, moves);
    for(int i=0; i<5; i++) {
        for(int j=0; j<10; j++) {
            if(i == playerRow && j == playerCol) {
                printf("P ");
            } else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function that moves the player left
void moveLeft() {
    moves++;
    if(playerCol > 0) {
        playerCol--;
    }
    printGame();
}

// Function that moves the player right
void moveRight() {
    moves++;
    if(playerCol < 9) {
        playerCol++;
    }
    printGame();
}

// Function that shoots a missile at the current player location
void shoot() {
    moves++;
    for(int i=playerRow-1; i>=0; i--) {
        if(map[i][playerCol] == 1) {
            score += 10;
            map[i][playerCol] = 0;
            break;
        }
    }
    printGame();
}

int main() {
    printGame();
    bool gameOver = false;
    // Game loop starts
    while(!gameOver) {
        char input = getchar();
        // Check user input
        switch(input) {
            case 'a':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            case 's':
                shoot();
                break;
            default:
                printf("\nInvalid input!\n");
                printGame();
                break;
        }
        // Check if game is over
        bool win = true;
        for(int i=0; i<5; i++) {
            for(int j=0; j<10; j++) {
                if(map[i][j] == 1) {
                    win = false;
                    break;
                }
            }
            if(!win) {
                break;
            }
        }
        if(win) {
            printf("\nCongratulations, you have won the game!\n");
            printf("Final Score: %d | Total Moves: %d\n", score, moves);
            gameOver = true;
        }
    }
    return 0;
}