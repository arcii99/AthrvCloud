//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum dimensions of the space grid
#define MAX_X 10
#define MAX_Y 10

// Define the character to represent the player's ship
#define PLAYER_SHIP 'P'

// Define the characters to represent other objects in space
#define EMPTY_SPACE '-'
#define ASTEROID '*'
#define ALIEN 'A'

// Define the starting coordinates for the player's ship
#define START_X 5
#define START_Y 5

// Define the maximum number of asteroids and aliens in the space grid
#define MAX_ASTEROIDS 10
#define MAX_ALIENS 5

// Define a struct to represent objects in space
typedef struct {
    char symbol;
    int x;
    int y;
} SpaceObject;

// Declare the functions used in the program
void initializeGrid(char grid[MAX_X][MAX_Y]);
void placeObject(char grid[MAX_X][MAX_Y], SpaceObject object);
void placePlayerShip(char grid[MAX_X][MAX_Y], int x, int y);
void movePlayerShip(char grid[MAX_X][MAX_Y], SpaceObject *playerShip, char input);
void generateObjects(char grid[MAX_X][MAX_Y], SpaceObject objects[], int maxObjects, char symbol);
void moveObjects(char grid[MAX_X][MAX_Y], SpaceObject objects[], int maxObjects);

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Declare the space grid and the player's ship
    char grid[MAX_X][MAX_Y];
    SpaceObject playerShip = {PLAYER_SHIP, START_X, START_Y};
    
    // Initialize the space grid and place the player's ship on it
    initializeGrid(grid);
    placePlayerShip(grid, playerShip.x, playerShip.y);
    
    // Generate the asteroids and aliens and place them on the space grid
    SpaceObject asteroids[MAX_ASTEROIDS];
    generateObjects(grid, asteroids, MAX_ASTEROIDS, ASTEROID);
    SpaceObject aliens[MAX_ALIENS];
    generateObjects(grid, aliens, MAX_ALIENS, ALIEN);
    
    // Print the initial state of the space grid
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Use WASD to move your ship, and avoid the asteroids and aliens!\n\n");
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            printf("%c ", grid[x][y]);
        }
        printf("\n");
    }
    
    // Enable the user to move the player's ship until the game is over
    char input;
    while (1) {
        printf("\n> ");
        scanf(" %c", &input);
        
        movePlayerShip(grid, &playerShip, input);
        moveObjects(grid, asteroids, MAX_ASTEROIDS);
        moveObjects(grid, aliens, MAX_ALIENS);
        
        // Check if the player's ship has collided with an asteroid or alien
        for (int i = 0; i < MAX_ASTEROIDS; i++) {
            if (playerShip.x == asteroids[i].x && playerShip.y == asteroids[i].y) {
                printf("\nYou collided with an asteroid! Game over.\n");
                return 0;
            }
        }
        for (int i = 0; i < MAX_ALIENS; i++) {
            if (playerShip.x == aliens[i].x && playerShip.y == aliens[i].y) {
                printf("\nYou were captured by an alien! Game over.\n");
                return 0;
            }
        }
        
        // Print the current state of the space grid
        printf("\n");
        for (int y = 0; y < MAX_Y; y++) {
            for (int x = 0; x < MAX_X; x++) {
                printf("%c ", grid[x][y]);
            }
            printf("\n");
        }
    }
}

// Initialize the space grid with empty spaces
void initializeGrid(char grid[MAX_X][MAX_Y]) {
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            grid[x][y] = EMPTY_SPACE;
        }
    }
}

// Place an object on the space grid
void placeObject(char grid[MAX_X][MAX_Y], SpaceObject object) {
    grid[object.x][object.y] = object.symbol;
}

// Place the player's ship on the space grid
void placePlayerShip(char grid[MAX_X][MAX_Y], int x, int y) {
    grid[x][y] = PLAYER_SHIP;
}

// Move the player's ship based on user input
void movePlayerShip(char grid[MAX_X][MAX_Y], SpaceObject *playerShip, char input) {
    int newX = playerShip->x;
    int newY = playerShip->y;
    
    switch (input) {
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
    
    // Check if the new coordinates are within the space grid
    if (newX >= 0 && newX < MAX_X && newY >= 0 && newY < MAX_Y) {
        // Clear the old position of the player's ship and place it in the new position
        grid[playerShip->x][playerShip->y] = EMPTY_SPACE;
        playerShip->x = newX;
        playerShip->y = newY;
        placePlayerShip(grid, playerShip->x, playerShip->y);
    }
}

// Generate a specified number of objects and place them on the space grid
void generateObjects(char grid[MAX_X][MAX_Y], SpaceObject objects[], int maxObjects, char symbol) {
    int numObjects = rand() % maxObjects + 1;
    
    for (int i = 0; i < numObjects; i++) {
        SpaceObject object = {symbol, rand() % MAX_X, rand() % MAX_Y};
        
        // Check if the generated object overlaps with an existing object or the player's ship
        while (grid[object.x][object.y] != EMPTY_SPACE || (object.x == START_X && object.y == START_Y)) {
            object.x = rand() % MAX_X;
            object.y = rand() % MAX_Y;
        }
        
        objects[i] = object;
        placeObject(grid, objects[i]);
    }
}

// Move objects in a random direction
void moveObjects(char grid[MAX_X][MAX_Y], SpaceObject objects[], int maxObjects) {
    for (int i = 0; i < maxObjects; i++) {
        int direction = rand() % 4;
        
        // Calculate the new coordinates based on the direction
        int newX = objects[i].x;
        int newY = objects[i].y;
        switch (direction) {
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
        
        // Check if the new coordinates are within the space grid
        if (newX >= 0 && newX < MAX_X && newY >= 0 && newY < MAX_Y) {
            // Clear the old position of the object and place it in the new position
            grid[objects[i].x][objects[i].y] = EMPTY_SPACE;
            objects[i].x = newX;
            objects[i].y = newY;
            placeObject(grid, objects[i]);
        }
    }
}