//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Map constants
#define MAP_WIDTH 20
#define MAP_HEIGHT 10

// Character constants
#define HERO '@'
#define WALL '#'
#define FLOOR '.'
#define GOBLIN 'G'
#define GOBLIN_COUNT 3

// Function prototypes
void generateMap(char map[MAP_HEIGHT][MAP_WIDTH]);
void placeHero(char map[MAP_HEIGHT][MAP_WIDTH], int* heroX, int* heroY);
void placeGoblins(char map[MAP_HEIGHT][MAP_WIDTH]);
void printMap(char map[MAP_HEIGHT][MAP_WIDTH]);
void moveHero(char map[MAP_HEIGHT][MAP_WIDTH], int* heroX, int* heroY);
void moveGoblins(char map[MAP_HEIGHT][MAP_WIDTH]);

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize map
    char map[MAP_HEIGHT][MAP_WIDTH];
    generateMap(map);
    
    // Place hero
    int heroX, heroY;
    placeHero(map, &heroX, &heroY);
    
    // Place goblins
    placeGoblins(map);
    
    // Print initial map
    printMap(map);
    
    // Game loop
    int gameOver = 0;
    while (!gameOver)
    {
        // Hero turn
        moveHero(map, &heroX, &heroY);
        printMap(map);
        
        // Check for game over
        if (map[heroY][heroX] == GOBLIN)
        {
            printf("Game over! You have been killed by a goblin!\n");
            gameOver = 1;
        }
        
        // Goblins turn
        moveGoblins(map);
        printMap(map);
        
        // Check for game over
        if (map[heroY][heroX] == GOBLIN)
        {
            printf("Game over! You have been killed by a goblin!\n");
            gameOver = 1;
        }
    }
    
    return 0;
}

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Initialize with walls
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = WALL;
        }
    }
    
    // Carve out rooms and corridors
    // ...
}

void placeHero(char map[MAP_HEIGHT][MAP_WIDTH], int* heroX, int* heroY)
{
    // Find random empty location
    int x, y;
    do
    {
        x = rand() % MAP_WIDTH;
        y = rand() % MAP_HEIGHT;
    } while (map[y][x] != FLOOR);
    
    // Place hero at location
    map[y][x] = HERO;
    *heroX = x;
    *heroY = y;
}

void placeGoblins(char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Place goblins randomly on floor tiles
    int count = 0;
    while (count < GOBLIN_COUNT)
    {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        if (map[y][x] == FLOOR)
        {
            map[y][x] = GOBLIN;
            count++;
        }
    }
}

void printMap(char map[MAP_HEIGHT][MAP_WIDTH])
{
    // Clear screen
    system("clear");
    
    // Print map
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void moveHero(char map[MAP_HEIGHT][MAP_WIDTH], int* heroX, int* heroY)
{
    // Get movement direction from user input
    char direction;
    printf("Enter movement direction (w, a, s, d): ");
    scanf(" %c", &direction);
    
    // Move hero if possible
    int newX = *heroX;
    int newY = *heroY;
    switch (direction)
    {
        case 'w':
            newY--;
            break;
        case 'a':
            newX--;
            break;
        case 's':
            newY++;
            break;
        case 'd':
            newX++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
    
    if (map[newY][newX] == FLOOR)
    {
        map[*heroY][*heroX] = FLOOR;
        map[newY][newX] = HERO;
        *heroX = newX;
        *heroY = newY;
    }
    else
    {
        printf("Cannot move there!\n");
    }
}

void moveGoblins(char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (map[i][j] == GOBLIN)
            {
                // Move goblin randomly
                int newX, newY;
                do
                {
                    newX = j + rand() % 3 - 1;
                    newY = i + rand() % 3 - 1;
                } while (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT || map[newY][newX] == WALL);
                
                // Attack hero if adjacent
                if ((newX == j - 1 && newY == i) ||
                    (newX == j + 1 && newY == i) ||
                    (newX == j && newY == i - 1) ||
                    (newX == j && newY == i + 1))
                {
                    printf("A goblin attacks you!\n");
                    map[newY][newX] = FLOOR;
                    return;
                }
                
                map[i][j] = FLOOR;
                map[newY][newX] = GOBLIN;
            }
        }
    }
}