//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    char content;
} Tile;

void createLevel(Tile* level, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            level[i * width + j].x = j;
            level[i * width + j].y = i;
            // Fill level with walls initially
            level[i * width + j].content = '#';
        }
    }
    // Generate random rooms
    int numRooms = rand() % 5 + 10; // 10 - 15 rooms randomly
    for(i = 0; i < numRooms; i++) {
        int roomWidth = rand() % 6 + 4; // 4 - 9 room width randomly
        int roomHeight = rand() % 6 + 4; // 4 - 9 room height randomly
        int roomX = rand() % (width - roomWidth - 1) + 1; // Random x within bounds
        int roomY = rand() % (height - roomHeight - 1) + 1; // Random y within bounds
        // Make sure the room doesn't overlap with other rooms
        int isOverlap = 0;
        int x, y;
        for(y = roomY - 1; y <= roomY + roomHeight; y++) {
            for(x = roomX - 1; x <= roomX + roomWidth; x++) {
                if(level[y * width + x].content != '#') {
                    isOverlap = 1;
                    break;
                }
            }
            if(isOverlap) {
                break;
            }
        }
        // If the room doesn't overlap, add it to the level
        if(!isOverlap) {
            for(y = roomY; y < roomY + roomHeight; y++) {
                for(x = roomX; x < roomX + roomWidth; x++) {
                    if(y == roomY || y == roomY + roomHeight - 1) { // Top and bottom walls
                        level[y * width + x].content = '-';
                    } else if(x == roomX || x == roomX + roomWidth - 1) { // Left and right walls
                        level[y * width + x].content = '|';
                    } else { // The middle of the room is empty
                        level[y * width + x].content = '.';
                    }
                }
            }
        }
    }
    // Generate random paths between the rooms
    int numPaths = rand() % numRooms + 2; // Connect at least all rooms
    for(i = 0; i < numPaths; i++) {
        int startX, startY, endX, endY;
        // Choose two random rooms to connect
        do {
            startX = rand() % (width - 2) + 1; // Random x within bounds except walls
            startY = rand() % (height - 2) + 1; // Random y within bounds except walls
        } while(level[startY * width + startX].content != '.');
        do {
            endX = rand() % (width - 2) + 1; // Random x within bounds except walls
            endY = rand() % (height - 2) + 1; // Random y within bounds except walls
        } while(level[endY * width + endX].content != '.' || (startX == endX && startY == endY));
        // Connect the two rooms with a path
        int currX = startX;
        int currY = startY;
        while(currX != endX || currY != endY) {
            level[currY * width + currX].content = '.';
            // Move towards the target room
            if(currX < endX) {
                currX++;
            } else if(currX > endX) {
                currX--;
            }
            if(currY < endY) {
                currY++;
            } else if(currY > endY) {
                currY--;
            }
        }
    }
}

void printLevel(Tile* level, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%c", level[i * width + j].content);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int width = 80;
    int height = 25;
    Tile level[width * height];
    createLevel(level, width, height);
    printLevel(level, width, height);
    return 0;
}