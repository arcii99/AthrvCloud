//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 8

struct Room {
    int x;
    int y;
    int width;
    int height;
};

void drawMap(char map[][MAP_WIDTH], struct Room rooms[], int numRooms);
void placeRoom(char map[][MAP_WIDTH], struct Room *room);
int intersects(struct Room *room, struct Room rooms[], int numRooms);
void connectRooms(char map[][MAP_WIDTH], struct Room *roomA, struct Room *roomB);
void generateMap(char map[][MAP_WIDTH], struct Room rooms[], int numRooms);

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    struct Room rooms[MAX_ROOMS];

    srand(time(NULL)); // Seed the RNG with the current time

    generateMap(map, rooms, MAX_ROOMS); // Generate the map and rooms
    drawMap(map, rooms, MAX_ROOMS); // Draw the map on the console

    return 0;
}

void generateMap(char map[][MAP_WIDTH], struct Room rooms[], int numRooms) {
    // Fill the map with wall tiles
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // Place randomly-sized rooms in random locations
    for (int i = 0; i < numRooms; i++) {
        struct Room room;
        room.width = rand() % 6 + 5; // Width between 5 and 10 tiles
        room.height = rand() % 4 + 3; // Height between 3 and 6 tiles
        room.x = rand() % (MAP_WIDTH - room.width - 1) + 1; // Random x position within the map bounds
        room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1; // Random y position within the map bounds

        if (!intersects(&room, rooms, i)) {
            placeRoom(map, &room); // Place the room on the map if it doesn't intersect with any other rooms
            rooms[i] = room; // Add the room to the array of rooms
        }
    }

    // Connect the rooms with randomly-placed corridors
    for (int i = 0; i < numRooms - 1; i++) {
        connectRooms(map, &rooms[i], &rooms[i+1]);
    }
}

void drawMap(char map[][MAP_WIDTH], struct Room rooms[], int numRooms) {
    // Draw the rooms
    for (int i = 0; i < numRooms; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                map[y][x] = '.';
            }
        }
    }

    // Draw the map on the console
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void placeRoom(char map[][MAP_WIDTH], struct Room *room) {
    // Fill the room with floor tiles
    for (int y = room->y; y < room->y + room->height; y++) {
        for (int x = room->x; x < room->x + room->width; x++) {
            map[y][x] = '.';
        }
    }
}

int intersects(struct Room *room, struct Room rooms[], int numRooms) {
    // Check if the room intersects with any other rooms
    for (int i = 0; i < numRooms; i++) {
        if (room->x < rooms[i].x + rooms[i].width &&
            room->x + room->width > rooms[i].x &&
            room->y < rooms[i].y + rooms[i].height &&
            room->y + room->height > rooms[i].y) {
            return 1; // Intersects with another room
        }
    }

    return 0; // Does not intersect with any other rooms
}

void connectRooms(char map[][MAP_WIDTH], struct Room *roomA, struct Room *roomB) {
    int x = roomA->x + roomA->width / 2; // Horizontal center of room A
    int y = roomA->y + roomA->height / 2; // Vertical center of room A

    while (x != roomB->x + roomB->width / 2 || y != roomB->y + roomB->height / 2) {
        if (x < roomB->x + roomB->width / 2) {
            x++;
        } else if (x > roomB->x + roomB->width / 2) {
            x--;
        }

        if (y < roomB->y + roomB->height / 2) {
            y++;
        } else if (y > roomB->y + roomB->height / 2) {
            y--;
        }

        if (map[y][x] != '.') {
            map[y][x] = '#'; // Place a corridor tile if it's not already a floor tile
        }
    }
}