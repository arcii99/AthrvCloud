//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants for map dimensions */
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

/* Constants for room sizes */
#define MIN_ROOM_WIDTH 3
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 10

/* Constants for map tiles */
#define TILE_EMPTY ' '
#define TILE_WALL '#'
#define TILE_PLAYER '@'
#define TILE_ENEMY 'E'
#define TILE_TREASURE '$'

/* Player attributes */
int playerX = 0;
int playerY = 0;
int playerHealth = 10;
int playerGold = 0;

/* Enemy attributes */
int enemyX = 0;
int enemyY = 0;
int enemyHealth = 5;

/* Map data */
char map[MAP_WIDTH][MAP_HEIGHT];

/* Function declarations */
void generateMap();
void generateRooms();
void fillMap(char tile);
void placePlayer();
void placeEnemy();
void placeTreasure();
void printMap();
void movePlayer();
void moveEnemy();

/* Function definitions */

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    generateMap();     // Generate the map
    printMap();        // Print the initial map
    while (1)
    {
        movePlayer(); // Player's turn
        moveEnemy();  // Enemy's turn
        printMap();   // Print the updated map
        if (playerHealth <= 0)
        {
            printf("Game over!\n");
            break;
        }
    }
    return 0;
}

void generateMap()
{
    fillMap(TILE_WALL); // Fill the map with walls
    generateRooms();    // Generate the rooms
    placePlayer();      // Place the player
    placeEnemy();       // Place the enemy
    placeTreasure();    // Place the treasure
}

void fillMap(char tile)
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            map[x][y] = tile;
        }
    }
}

void generateRooms()
{
    int numRooms = rand() % 5 + 5; // Generate a random number of rooms between 5 and 10
    for (int i = 0; i < numRooms; i++)
    {
        int roomX = rand() % (MAP_WIDTH - MAX_ROOM_WIDTH - 1) + 1;     // Generate a random x position for the room
        int roomY = rand() % (MAP_HEIGHT - MAX_ROOM_HEIGHT - 1) + 1;   // Generate a random y position for the room
        int roomWidth = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;   // Generate a random width for the room
        int roomHeight = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT; // Generate a random height for the room
        for (int x = roomX; x < roomX + roomWidth; x++)
        {
            for (int y = roomY; y < roomY + roomHeight; y++)
            {
                map[x][y] = TILE_EMPTY; // Fill the room with empty tiles
            }
        }
    }
}

void placePlayer()
{
    while (1)
    {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        if (map[x][y] == TILE_EMPTY)
        {
            playerX = x;
            playerY = y;
            map[x][y] = TILE_PLAYER;
            break;
        }
    }
}

void placeEnemy()
{
    while (1)
    {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        if (map[x][y] == TILE_EMPTY)
        {
            enemyX = x;
            enemyY = y;
            map[x][y] = TILE_ENEMY;
            break;
        }
    }
}

void placeTreasure()
{
    int numTreasures = rand() % 3 + 1; // Generate a random number of treasures between 1 and 3
    for (int i = 0; i < numTreasures; i++)
    {
        while (1)
        {
            int x = rand() % MAP_WIDTH;
            int y = rand() % MAP_HEIGHT;
            if (map[x][y] == TILE_EMPTY)
            {
                map[x][y] = TILE_TREASURE; // Place the treasure on an empty tile
                break;
            }
        }
    }
}

void printMap()
{
    system("clear"); // Clear the screen
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
    printf("Health: %d\n", playerHealth);
    printf("Gold: %d\n", playerGold);
}

void movePlayer()
{
    char input;
    printf("Enter a direction to move (w/a/s/d): ");
    scanf(" %c", &input);
    int newX = playerX;
    int newY = playerY;
    switch (input)
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
            break;
    }
    if (map[newX][newY] == TILE_ENEMY)
    {
        printf("You encounter an enemy!\n");
        enemyHealth -= rand() % 3 + 1; // Enemy takes between 1 and 3 damage
        if (enemyHealth <= 0)
        {
            printf("You defeated the enemy and gained 1 gold!\n");
            playerGold++;
            placeEnemy(); // Respawn the enemy
            enemyHealth = 5; // Reset the enemy's health
        }
        else
        {
            printf("The enemy attacks you and deals %d damage!\n", rand() % 3 + 1); // Enemy deals between 1 and 3 damage
            playerHealth -= rand() % 3 + 1; // Player takes between 1 and 3 damage
        }
    }
    else if (map[newX][newY] == TILE_TREASURE)
    {
        printf("You found a treasure!\n");
        playerGold++; // Pick up the treasure, which adds 1 gold
        map[newX][newY] = TILE_EMPTY; // Remove the treasure from the map
    }
    else if (map[newX][newY] == TILE_EMPTY)
    {
        playerX = newX;
        playerY = newY;
        map[newX][newY] = TILE_PLAYER; // Move the player
    }
    else
    {
        printf("You cannot move there!\n");
    }
}

void moveEnemy()
{
    int direction = rand() % 4; // Generate a random direction for the enemy to move in
    int newX = enemyX;
    int newY = enemyY;
    switch (direction)
    {
        case 0:
            newY--;
            break;
        case 1:
            newX--;
            break;
        case 2:
            newY++;
            break;
        case 3:
            newX++;
            break;
        default:
            break;
    }
    if (map[newX][newY] == TILE_PLAYER)
    {
        printf("An enemy attacks you and deals %d damage!\n", rand() % 3 + 1); // Enemy deals between 1 and 3 damage
        playerHealth -= rand() % 3 + 1; // Player takes between 1 and 3 damage
    }
    else if (map[newX][newY] == TILE_EMPTY)
    {
        enemyX = newX;
        enemyY = newY;
        map[newX][newY] = TILE_ENEMY; // Move the enemy
        map[enemyX][enemyY] = TILE_EMPTY;
    }
}