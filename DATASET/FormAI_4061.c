//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 50

void printScreen(char screen[][COL]);
int generateRandomInt(int min, int max);

int main()
{
    char screen[ROW][COL];
    int playerPosRow = ROW-1;
    int playerPosCol = COL/2;
    int ghostPosRow = 0;
    int ghostPosCol = generateRandomInt(0, COL-1);
    int score = 0;

    // Initialize screen
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            screen[i][j] = '.';
        }
    }

    // Place player and ghost
    screen[playerPosRow][playerPosCol] = 'P';
    screen[ghostPosRow][ghostPosCol] = 'G';

    // Game loop
    while (1) {
        // Print screen
        printf("Score: %d\n", score);
        printScreen(screen);

        // Get user input
        printf("Enter command (w/a/s/d to move, q to quit): ");
        char input;
        scanf(" %c", &input);

        // Process user input
        if (input == 'w') {
            // Move player up
            if (playerPosRow > 0) {
                screen[playerPosRow][playerPosCol] = '.';
                playerPosRow--;
                screen[playerPosRow][playerPosCol] = 'P';
            }
        } else if (input == 'a') {
            // Move player left
            if (playerPosCol > 0) {
                screen[playerPosRow][playerPosCol] = '.';
                playerPosCol--;
                screen[playerPosRow][playerPosCol] = 'P';
            }
        } else if (input == 's') {
            // Move player down
            if (playerPosRow < ROW-1) {
                screen[playerPosRow][playerPosCol] = '.';
                playerPosRow++;
                screen[playerPosRow][playerPosCol] = 'P';
            }
        } else if (input == 'd') {
            // Move player right
            if (playerPosCol < COL-1) {
                screen[playerPosRow][playerPosCol] = '.';
                playerPosCol++;
                screen[playerPosRow][playerPosCol] = 'P';
            }
        } else if (input == 'q') {
            // Quit game
            printf("Game over! Final score: %d\n", score);
            break;
        }

        // Move ghost
        int ghostDirection = generateRandomInt(0, 2);
        if (ghostDirection == 0 && ghostPosRow > 0) {
            screen[ghostPosRow][ghostPosCol] = '.';
            ghostPosRow--;
        } else if (ghostDirection == 1 && ghostPosCol > 0) {
            screen[ghostPosRow][ghostPosCol] = '.';
            ghostPosCol--;
        } else if (ghostDirection == 2 && ghostPosCol < COL-1) {
            screen[ghostPosRow][ghostPosCol] = '.';
            ghostPosCol++;
        }
        screen[ghostPosRow][ghostPosCol] = 'G';

        // Check collision
        if (playerPosRow == ghostPosRow && playerPosCol == ghostPosCol) {
            printf("You got caught by the ghost! Final score: %d\n", score);
            break;
        }

        // Increase score
        score++;
    }

    return 0;
}

void printScreen(char screen[][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int generateRandomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}