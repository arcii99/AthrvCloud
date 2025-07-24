//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

char map[HEIGHT][WIDTH];
int playerX, playerY;

void generateMap() {
    srand(time(NULL));   // Seed the random number generator with the current time
    int numRooms = rand() % 5 + 5;   // Generate 5 to 10 rooms
    int rooms[numRooms][4];   // Array to store room coordinates

    // Initialize the map with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Generate the rooms
    for (int i = 0; i < numRooms; i++) {
        int roomWidth = rand() % 6 + 5;   // Generate 5 to 10 room width
        int roomHeight = rand() % 6 + 5;   // Generate 5 to 10 room height
        int roomX = rand() % (WIDTH - roomWidth - 2) + 1;   // Generate room X coordinate
        int roomY = rand() % (HEIGHT - roomHeight - 2) + 1;   // Generate room Y coordinate

        // Check if the room overlaps with any existing rooms
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (roomX < rooms[j][0] + rooms[j][2] && roomX + roomWidth > rooms[j][0] && roomY < rooms[j][1] + rooms[j][3] && roomY + roomHeight > rooms[j][1]) {
                overlap = 1;
                break;
            }
        }

        // Generate the room if there is no overlap
        if (!overlap) {
            for (int y = roomY; y < roomY + roomHeight; y++) {
                for (int x = roomX; x < roomX + roomWidth; x++) {
                    if (y == roomY || y == roomY + roomHeight - 1 || x == roomX || x == roomX + roomWidth - 1) {
                        map[y][x] = '*';   // Place walls around the room
                    } else {
                        map[y][x] = '.';   // Place floor tiles inside the room
                    }
                }
            }
            rooms[i][0] = roomX;
            rooms[i][1] = roomY;
            rooms[i][2] = roomWidth;
            rooms[i][3] = roomHeight;
        } else {
            i--;   // Retry generating the room
        }
    }

    // Generate corridors between the rooms
    for (int i = 0; i < numRooms - 1; i++) {
        int x1 = rooms[i][0] + rooms[i][2] / 2;
        int y1 = rooms[i][1] + rooms[i][3] / 2;
        int x2 = rooms[i + 1][0] + rooms[i + 1][2] / 2;
        int y2 = rooms[i + 1][1] + rooms[i + 1][3] / 2;

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            if (map[y1][x1] == '#') {
                map[y1][x1] = '.';
            }
        }
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            if (map[y1][x1] == '#') {
                map[y1][x1] = '.';
            }
        }
    }

    // Place the player randomly in a room
    int roomIndex = rand() % numRooms;
    int roomX = rooms[roomIndex][0] + 1 + rand() % (rooms[roomIndex][2] - 2);
    int roomY = rooms[roomIndex][1] + 1 + rand() % (rooms[roomIndex][3] - 2);
    playerX = roomX;
    playerY = roomY;
    map[playerY][playerX] = '@';
}

void displayMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    displayMap();
    return 0;
}