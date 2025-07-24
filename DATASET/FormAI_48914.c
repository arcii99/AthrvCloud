//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for the dimensions of the haunted house
#define HOUSE_WIDTH 20
#define HOUSE_HEIGHT 10

// Define constants for the different types of rooms
#define ROOM_TYPE_EMPTY 0
#define ROOM_TYPE_NORMAL 1
#define ROOM_TYPE_START 2
#define ROOM_TYPE_END 3

// Define a struct to represent a room in the haunted house
typedef struct Room {
    int type;
    bool visited;
} Room;

// Define a struct to represent the player
typedef struct Player {
    int x;
    int y;
} Player;

// Define a function to generate random numbers between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Create the haunted house
    Room house[HOUSE_WIDTH][HOUSE_HEIGHT];
    
    // Fill the house with empty rooms to start with
    for (int i = 0; i < HOUSE_WIDTH; i++) {
        for (int j = 0; j < HOUSE_HEIGHT; j++) {
            house[i][j].type = ROOM_TYPE_EMPTY;
            house[i][j].visited = false;
        }
    }
    
    // Define the starting room and mark it as visited
    int startX = generateRandomNumber(0, HOUSE_WIDTH - 1);
    int startY = generateRandomNumber(0, HOUSE_HEIGHT - 1);
    house[startX][startY].type = ROOM_TYPE_START;
    house[startX][startY].visited = true;
    
    // Define the ending room and mark it as unvisited
    int endX = generateRandomNumber(0, HOUSE_WIDTH - 1);
    int endY = generateRandomNumber(0, HOUSE_HEIGHT - 1);
    while (house[endX][endY].type != ROOM_TYPE_EMPTY) {
        endX = generateRandomNumber(0, HOUSE_WIDTH - 1);
        endY = generateRandomNumber(0, HOUSE_HEIGHT - 1);
    }
    house[endX][endY].type = ROOM_TYPE_END;
    house[endX][endY].visited = false;
    
    // Generate normal rooms randomly until at least 75% of the house is filled
    int numRooms = 0;
    while ((double) numRooms / (HOUSE_WIDTH * HOUSE_HEIGHT) < 0.75) {
        int roomX = generateRandomNumber(0, HOUSE_WIDTH - 1);
        int roomY = generateRandomNumber(0, HOUSE_HEIGHT - 1);
        if (!house[roomX][roomY].visited) {
            house[roomX][roomY].type = ROOM_TYPE_NORMAL;
            house[roomX][roomY].visited = true;
            numRooms++;
        }
    }
    
    // Define the player
    Player player;
    player.x = startX;
    player.y = startY;
    
    // Enter the game loop
    while (true) {
        // Print the haunted house
        for (int i = 0; i < HOUSE_WIDTH; i++) {
            for (int j = 0; j < HOUSE_HEIGHT; j++) {
                if (i == player.x && j == player.y) {
                    printf("P");
                } else if (house[i][j].visited) {
                    if (house[i][j].type == ROOM_TYPE_EMPTY) {
                        printf(" ");
                    } else if (house[i][j].type == ROOM_TYPE_NORMAL) {
                        printf(".");
                    } else if (house[i][j].type == ROOM_TYPE_START) {
                        printf("S");
                    } else if (house[i][j].type == ROOM_TYPE_END) {
                        printf("E");
                    }
                } else {
                    printf("?");
                }
            }
            printf("\n");
        }
        
        // Check if the player has won
        if (player.x == endX && player.y == endY) {
            printf("You have escaped the haunted house!\n");
            break;
        }
        
        // Get the player's input
        char input;
        printf("Enter your move (wasd): ");
        scanf(" %c", &input);
        
        // Move the player
        if (input == 'w' && player.y > 0 && house[player.x][player.y - 1].visited) {
            player.y--;
        } else if (input == 's' && player.y < HOUSE_HEIGHT - 1 && house[player.x][player.y + 1].visited) {
            player.y++;
        } else if (input == 'a' && player.x > 0 && house[player.x - 1][player.y].visited) {
            player.x--;
        } else if (input == 'd' && player.x < HOUSE_WIDTH - 1 && house[player.x + 1][player.y].visited) {
            player.x++;
        }
    }
    
    return 0;
}