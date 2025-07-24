//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 15
#define WIDTH 20
#define PACMAN 'P'
#define GHOST 'G'
#define WALL '#'
#define DOT '.'
#define POWER_PILL 'o'

int score = 0;
int direction;
bool powerPillActive = false;
bool gameWon = false;
char grid[HEIGHT][WIDTH];

void initializeGrid()
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1 || (i == HEIGHT/2 && j >= WIDTH/4 && j <= WIDTH - WIDTH/4))
            {
                grid[i][j] = WALL;
            }
            else if((i == 1 && j == 1) || (i == 1 && j == WIDTH-2) || (i == HEIGHT-2 && j == 1) || (i == HEIGHT-2 && j == WIDTH-2))
            {
                grid[i][j] = POWER_PILL;
            }
            else
            {
                grid[i][j] = DOT;
            }
        }
    }
    grid[HEIGHT/2][WIDTH/2] = ' ';
    direction = rand() % 4 + 1;
}

void printGrid()
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
}

void movePacman()
{
    int x, y;
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(grid[i][j] == PACMAN)
            {
                x = i;
                y = j;
            }
        }
    }
    switch(direction)
    {
        case 1:
            if(grid[x-1][y] != WALL)
            {
                if(grid[x-1][y] == DOT)
                {
                    score += 10;
                }
                else if(grid[x-1][y] == POWER_PILL)
                {
                    powerPillActive = true;
                    score += 50;
                }
                grid[x][y] = ' ';
                grid[x-1][y] = PACMAN;
            }
            break;
        case 2:
            if(grid[x+1][y] != WALL)
            {
                if(grid[x+1][y] == DOT)
                {
                    score += 10;
                }
                else if(grid[x+1][y] == POWER_PILL)
                {
                    powerPillActive = true;
                    score += 50;
                }
                grid[x][y] = ' ';
                grid[x+1][y] = PACMAN;
            }
            break;
        case 3:
            if(grid[x][y-1] != WALL)
            {
                if(grid[x][y-1] == DOT)
                {
                    score += 10;
                }
                else if(grid[x][y-1] == POWER_PILL)
                {
                    powerPillActive = true;
                    score += 50;
                }
                grid[x][y] = ' ';
                grid[x][y-1] = PACMAN;
            }
            break;
        case 4:
            if(grid[x][y+1] != WALL)
            {
                if(grid[x][y+1] == DOT)
                {
                    score += 10;
                }
                else if(grid[x][y+1] == POWER_PILL)
                {
                    powerPillActive = true;
                    score += 50;
                }
                grid[x][y] = ' ';
                grid[x][y+1] = PACMAN;
            }
            break;
    }
}

void moveGhost()
{
    int x, y;
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(grid[i][j] == GHOST)
            {
                x = i;
                y = j;
            }
        }
    }
    int ghostMoves[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int validMoves[4][2] = {0};

    int counter = 0;
    for (int i = 0; i < 4; i++) {
        if (x + ghostMoves[i][0] >= 1 && x + ghostMoves[i][0] < HEIGHT-1 &&
                y + ghostMoves[i][1] >= 1 && y + ghostMoves[i][1] < WIDTH-1 &&
                grid[x+ghostMoves[i][0]][y+ghostMoves[i][1]] != WALL) {
            validMoves[counter][0] = ghostMoves[i][0];
            validMoves[counter][1] = ghostMoves[i][1];
            counter++;
        }
    }

    if (powerPillActive) {
        int randomMove = rand() % counter;
        grid[x][y] = ' ';
        x += validMoves[randomMove][0];
        y += validMoves[randomMove][1];
        if(grid[x][y] == PACMAN)
        {
            gameWon = true;
        }
        grid[x][y] = GHOST;
    }
    else {
        int minDistance = HEIGHT+WIDTH;
        int bestMove = 0;
        for (int i = 0; i < counter; i++) {
            int dist = abs(x+validMoves[i][0]-1-HEIGHT/2) + abs(y+validMoves[i][1]-1-WIDTH/2);
            if (dist < minDistance) {
                minDistance = dist;
                bestMove = i;
            }
        }
        grid[x][y] = ' ';
        x += validMoves[bestMove][0];
        y += validMoves[bestMove][1];
        if(grid[x][y] == PACMAN)
        {
            gameWon = true;
        }
        grid[x][y] = GHOST;
    }
}

int main()
{
    srand(time(0));
    initializeGrid();
    while(true)
    {
        system("clear");
        if(gameWon)
        {
            printf("You won! Final score: %d\n", score);
            break;
        }
        if(score == WIDTH*HEIGHT/10*10)
        {
            printf("You cleared the board! Final score: %d\n", score);
            break;
        }

        printGrid();
        printf("Score: %d\t Power Pill Active: %s\n", score, powerPillActive ? "true" : "false");
        movePacman();
        if(rand() % 3 == 0) 
        {
            moveGhost();
        }
        if(powerPillActive)
        {
            powerPillActive = false;
        }
        sleep(1);
    }
    return 0;
}