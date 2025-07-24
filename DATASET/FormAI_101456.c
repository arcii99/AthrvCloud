//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Snake game implementation
int main()
{
    // Game board dimensions
    const int width = 30;
    const int height = 15;

    // Initialize the game board as a 2D character array
    char gameBoard[height][width];

    // Initialize the snake at the center of the board
    int snakeX = width / 2;
    int snakeY = height / 2;

    // Initialize the apple at a random position on the board
    int appleX = rand() % width;
    int appleY = rand() % height;

    // Initialize the snake direction to be up
    enum Direction {UP, DOWN, LEFT, RIGHT};
    enum Direction currDirection = UP;

    // Initialize the game loop
    bool gameOver = false;
    int score = 0;
    while(!gameOver)
    {
        // Clear the game board
        system("clear");

        // Draw the game board border
        for (int col = 0; col < width; col++)
        {
            gameBoard[0][col] = '#';
            gameBoard[height-1][col] = '#';
        }
        for (int row = 1; row < height-1; row++)
        {
            gameBoard[row][0] = '#';
            gameBoard[row][width-1] = '#';
        }

        // Draw the snake and apple
        gameBoard[snakeY][snakeX] = 'O';
        gameBoard[appleY][appleX] = 'X';

        // Print the game board
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                printf("%c", gameBoard[row][col]);
            }
            printf("\n");
        }

        // Handle user input
        char userMove;
        printf("Score: %d\n", score);
        printf("Use arrow keys to move the snake. Press q to quit.\n");
        scanf(" %c", &userMove);

        switch(userMove)
        {
            case 'q':
                gameOver = true;
                break;
            case 'w':
                currDirection = UP;
                break;
            case 's':
                currDirection = DOWN;
                break;
            case 'a':
                currDirection = LEFT;
                break;
            case 'd':
                currDirection = RIGHT;
                break;
        }

        // Move the snake
        switch(currDirection)
        {
            case UP:
                snakeY--;
                break;
            case DOWN:
                snakeY++;
                break;
            case LEFT:
                snakeX--;
                break;
            case RIGHT:
                snakeX++;
                break;
        }

        // Check for collisions
        if (snakeX == 0 || snakeX == width-1 || snakeY == 0 || snakeY == height-1)
        {
            gameOver = true;
        }
        else if (snakeX == appleX && snakeY == appleY)
        {
            score++;
            appleX = rand() % width;
            appleY = rand() % height;
        }

        // Slow down the game for better user experience
        usleep(100000);
    }

    // Game over
    printf("Game over! Your final score was %d.\n", score);
    return 0;
}