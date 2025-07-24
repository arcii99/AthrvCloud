//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[21][61]; // 20x60 playable area
int playerX, playerY;

void generateMap() {
    // Fill the map with walls
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 61; j++) {
            map[i][j] = '#';
        }
    }

    // Dig out the rooms
    srand(time(NULL));
    int numRooms = rand() % 6 + 5; // Randomly generate 5-10 rooms

    for(int r = 0; r < numRooms; r++) {
        // Randomly generate room dimensions
        int roomWidth = rand() % 10 + 5;
        int roomHeight = rand() % 7 + 3;
        int roomX = rand() % 51;
        int roomY = rand() % 13;

        // Ensure the room isn't out of bounds
        if(roomX + roomWidth > 60) {
            roomX = 60 - roomWidth;
        }

        if(roomY + roomHeight > 20) {
            roomY = 20 - roomHeight;
        }

        // Dig out the room
        for(int i = roomY; i < roomY + roomHeight; i++) {
            for(int j = roomX; j < roomX + roomWidth; j++) {
                map[i][j] = '.';
            }
        }
    }

    // Add corridors between the rooms
    for(int i = 1; i < numRooms; i++) {
        // Choose the coordinates of the previous and current rooms
        int prevRoomX, prevRoomY, roomX, roomY;

        do {
            prevRoomX = rand() % 56 + 2; // Avoid the edges of the map
            prevRoomY = rand() % 18 + 2;
        } while(map[prevRoomY][prevRoomX] != '.');

        do {
            roomX = rand() % 56 + 2;
            roomY = rand() % 18 + 2;
        } while(map[roomY][roomX] != '.' || (roomX == prevRoomX && roomY == prevRoomY));

        // Dig out the corridor
        while(prevRoomX != roomX) {
            if(prevRoomX < roomX) {
                prevRoomX++;
            } else {
                prevRoomX--;
            }

            map[prevRoomY][prevRoomX] = '.';
        }

        while(prevRoomY != roomY) {
            if(prevRoomY < roomY) {
                prevRoomY++;
            } else {
                prevRoomY--;
            }

            map[prevRoomY][prevRoomX] = '.';
        }
    }
}

void placePlayer() {
    // Choose a random spot in a room
    do {
        playerX = rand() % 60;
        playerY = rand() % 20;
    } while(map[playerY][playerX] != '.');
}

void printMap() {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 61; j++) {
            printf("%c", map[i][j]);
        }

        printf("\n");
    }
}

int main() {
    printf("Welcome to Rogue-like!\n");

    // Generate the map and place the player
    generateMap();
    placePlayer();

    while(1) {
        // Print the map and player location
        printf("\n");
        printMap();
        printf("\nPlayer location: (%d, %d)\n", playerX, playerY);

        // Get user input
        char input;
        printf("Enter a direction to move (WASD), or Q to quit: ");
        scanf(" %c", &input);

        // Handle movement input
        switch(input) {
            case 'w':
            case 'W':
                if(map[playerY-1][playerX] == '.') {
                    playerY--;
                }

                break;
            case 'a':
            case 'A':
                if(map[playerY][playerX-1] == '.') {
                    playerX--;
                }

                break;
            case 's':
            case 'S':
                if(map[playerY+1][playerX] == '.') {
                    playerY++;
                }

                break;
            case 'd':
            case 'D':
                if(map[playerY][playerX+1] == '.') {
                    playerX++;
                }

                break;
            case 'q':
            case 'Q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid input!\n");
        }
    }
}