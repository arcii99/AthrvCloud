//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct Room Room;
struct Room {
    int x, y; // starting coordinates of the room
    int width, height; // dimensions of the room
};

Room rooms[MAX_ROOMS]; // an array of rooms

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // generate the first room in the center of the screen
    rooms[0].x = 20; // define starting coordinates
    rooms[0].y = 15;
    rooms[0].width = 15; // define dimensions
    rooms[0].height = 10;
    
    // generate the remaining rooms
    for (int i = 1; i < MAX_ROOMS; i++) {
        rooms[i].width = rand() % 10 + 5; // define random dimensions
        rooms[i].height = rand() % 7 + 4;
        
        // place the room randomly within the bounds of the screen
        rooms[i].x = rand() % (40 - rooms[i].width - 2) + 1;
        rooms[i].y = rand() % (25 - rooms[i].height - 2) + 1;
        
        // check if this room intersects with any other room
        for (int j = 0; j < i; j++) {
            if (intersects(rooms[i], rooms[j])) { // if there's intersection, regenerate the room
                i--;
                break;
            }
        }
    }
    
    // print the coordinates and dimensions of each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: x=%d, y=%d, width=%d, height=%d\n", i+1, rooms[i].x, rooms[i].y, rooms[i].width, rooms[i].height);
    }
    
    return 0;
}

// helper function to check if two rooms intersect
int intersects(Room a, Room b) {
    return (a.x <= b.x + b.width && a.x + a.width >= b.x && a.y <= b.y + b.height && a.y + a.height >= b.y);
}