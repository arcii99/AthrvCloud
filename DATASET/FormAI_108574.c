//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAP_SIZE 10
#define MAX_MOVES 15

// Function Prototypes
void generateMap(char map[MAP_SIZE][MAP_SIZE]);
void printMap(char map[MAP_SIZE][MAP_SIZE]);
void navigate(char map[MAP_SIZE][MAP_SIZE], int *x, int *y, int *movesLeft);
int checkMove(char map[MAP_SIZE][MAP_SIZE], int x, int y, int newX, int newY);

// Main Function
int main()
{
    // Seed RNG
    srand(time(NULL));
    
    // Initialize Map
    char map[MAP_SIZE][MAP_SIZE];
    generateMap(map);
    
    // Starting Position
    int x = rand() % MAP_SIZE;
    int y = rand() % MAP_SIZE;
    
    // Starting Moves
    int movesLeft = MAX_MOVES;
    
    // Print Starting Map
    printf("Starting Map:\n");
    printMap(map);
    
    // Navigation Loop
    while(movesLeft > 0)
    {
        printf("You have %d moves left.\n", movesLeft);
        printf("Current Position: (%d, %d)\n", x, y);
        
        navigate(map, &x, &y, &movesLeft);
        movesLeft--;
        
        if(map[x][y] == 'X')
        {
            printf("Congrats! You have reached your destination!\n");
            break;
        }
        else if(movesLeft == 0)
        {
            printf("Oops! You have run out of moves. Game Over.\n");
            break;
        }
    }
    
    return 0;
}

// Function Definitions
void generateMap(char map[MAP_SIZE][MAP_SIZE])
{
    int i, j, randVal;
    
    for(i=0; i<MAP_SIZE; i++)
    {
        for(j=0; j<MAP_SIZE; j++)
        {
            randVal = rand() % 3;
            
            if(randVal == 0)
            {
                map[i][j] = '.';
            }
            else if(randVal == 1)
            {
                map[i][j] = 'O';
            }
            else if(randVal == 2)
            {
                map[i][j] = 'X';
            }
        }
    }
}

void printMap(char map[MAP_SIZE][MAP_SIZE])
{
    int i, j;
    
    for(i=0; i<MAP_SIZE; i++)
    {
        for(j=0; j<MAP_SIZE; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void navigate(char map[MAP_SIZE][MAP_SIZE], int *x, int *y, int *movesLeft)
{
    int newX, newY, isValidMove = 0;
    
    while(!isValidMove)
    {
        printf("Enter Direction (W/A/S/D): ");
        char direction;
        scanf(" %c", &direction);
        
        if(direction == 'W')
        {
            newX = *x - 1;
            newY = *y;
        }
        else if(direction == 'A')
        {
            newX = *x;
            newY = *y - 1;
        }
        else if(direction == 'S')
        {
            newX = *x + 1;
            newY = *y;
        }
        else if(direction == 'D')
        {
            newX = *x;
            newY = *y + 1;
        }
        else
        {
            printf("Invalid Direction. Try Again.\n");
            continue;
        }
        
        isValidMove = checkMove(map, *x, *y, newX, newY);
        
        if(!isValidMove)
        {
            printf("Invalid Move. Try Again.\n");
        }
        else
        {
            *x = newX;
            *y = newY;
            system("clear");
            printf("Updated Map:\n");
            printMap(map);
        }
    }
}

int checkMove(char map[MAP_SIZE][MAP_SIZE], int x, int y, int newX, int newY)
{
    if(newX < 0 || newX >= MAP_SIZE || newY < 0 || newY >= MAP_SIZE)
    {
        return 0;
    }
    else if(map[newX][newY] == 'O')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}