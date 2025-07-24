//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 21
#define COLUMNS 19

// Global variables
char maze[ROWS][COLUMNS] = {
    {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'},
    {'|', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '-', '+', '-', '-', '-', '-', '-', '+', ' ', '|'},
    {'|', '-', '|', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', '|', '|'},
    {'|', ' ', '+', '-', '-', '+', '|', ' ', '|', ' ', '+', '-', '+', ' ', '+', '-', '-', '+', '-', '+'},
    {'|', '-', '-', '-', '-', '|', '|', ' ', '-', '-', '-', '-', '+', ' ', '|', ' ', '|', ' ', ' ', '|'},
    {'|', ' ', '+', '-', '-', '+', '|', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '+', '|'},
    {'|', ' ', '|', ' ', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', '|'},
    {'+', '-', '-', '-', '-', '+', '+', '-', '+', '-', '+', '-', '+', '-', '-', '-', '+', '-', '-', '+'},
    {' ', ' ', ' ', ' ', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {'+', '-', '-', '-', '-', '+', '+', '-', '+', '-', '+', '-', '+', '-', '-', '-', '+', '-', '-', '+'},
    {'|', ' ', ' ', ' ', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '|'},
    {'|', '-', '-', '-', '-', '+', '+', '-', '+', '-', '+', '-', '+', '-', '-', '-', '+', '-', '-', '+'},
    {'|', ' ', ' ', ' ', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '+', '-', '+', '-', '+'},
    {'+', '-', '-', '-', '-', '+', '|', ' ', '+', '-', '-', '-', '+', '-', '-', '|', ' ', '|', ' ', '|'},
    {' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '+', '-', '+', '-', '+'},
    {'+', '-', '-', '-', '-', '+', '|', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '-', '-', '-', '+'},
    {'|', ' ', ' ', ' ', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', '-', '-', '-', '-', '+', '|', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '-', '-', '-', '+'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '-', '-', '+'}
};

int lives = 3;
int score = 0;
int pac_x = 9, pac_y = 14; // Starting position of Pac-Man
int ghost_x = 9, ghost_y = 9; // Starting position of Ghost

// Function prototypes
void displayMaze();
void movePacman();
void moveGhost();
bool checkForCollision(int x, int y);
void updateScore(int numDotsEaten);

int main()
{
    // Setting the seed for random number generation
    srand(time(NULL));

    while(lives > 0)
    {
        displayMaze(); // Display the maze
        movePacman(); // Move Pac-Man
        moveGhost(); // Move Ghost

        // Check for collision with Ghost
        if(pac_x == ghost_x && pac_y == ghost_y)
        {
            lives--;
            printf("\nOops! You collided with the Ghost. You now have %d lives remaining.\n\n", lives);
            pac_x = 9;
            pac_y = 14;
            ghost_x = 9;
            ghost_y = 9;
        }

        // Check for collision with dots
        if(maze[pac_x][pac_y] == '.')
        {
            score += 10;
            updateScore(1);
            maze[pac_x][pac_y] = ' ';
        }
    }

    printf("Game Over! Your score is: %d", score);

    return 0;
}

void displayMaze()
{
    // Clear the screen
    system("cls");

    // Display the maze
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nScore: %d\nLives: %d", score, lives);
}

void movePacman()
{
    char input;
    fflush(stdin); // Clears the input buffer on Unix-based systems

    printf("\nUse arrow keys to move Pac-Man. Press Enter to confirm.\n");

    // Take input from the user
    input = getchar();

    switch(input)
    {
        case 'w':
            if(pac_x > 0 && maze[pac_x - 1][pac_y] != '|')
            {
                pac_x--;
            }
            break;
        case 'a':
            if(pac_y > 0 && maze[pac_x][pac_y - 1] != '+')
            {
                pac_y--;
            }
            break;
        case 's':
            if(pac_x < ROWS - 1 && maze[pac_x + 1][pac_y] != '|')
            {
                pac_x++;
            }
            break;
        case 'd':
            if(pac_y < COLUMNS - 1 && maze[pac_x][pac_y + 1] != '+')
            {
                pac_y++;
            }
            break;
    }
}

void moveGhost()
{
    // Randomly determine the direction of the Ghost
    int direction = rand() % 4;

    switch(direction)
    {
        case 0:
            if(ghost_x > 0 && maze[ghost_x - 1][ghost_y] != '|')
            {
                ghost_x--;
            }
            break;
        case 1:
            if(ghost_y > 0 && maze[ghost_x][ghost_y - 1] != '+')
            {
                ghost_y--;
            }
            break;
        case 2:
            if(ghost_x < ROWS - 1 && maze[ghost_x + 1][ghost_y] != '|')
            {
                ghost_x++;
            }
            break;
        case 3:
            if(ghost_y < COLUMNS - 1 && maze[ghost_x][ghost_y + 1] != '+')
            {
                ghost_y++;
            }
            break;
    }
}

bool checkForCollision(int x, int y)
{
    // Check for collision with walls
    if(maze[x][y] == '|' || maze[x][y] == '+')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void updateScore(int numDotsEaten)
{
    printf("\nCongrats! You ate %d dot(s) and scored %d points!", numDotsEaten, numDotsEaten * 10);
}