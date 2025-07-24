//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <time.h>

#define ROOM_MIN_SIZE 6
#define ROOM_MAX_SIZE 10
#define MAP_WIDTH 80
#define MAP_HEIGHT 25

// Tile types
enum TileType {
    WALL,
    FLOOR
};

// Node struct for linked-list of rooms
typedef struct Node {
    int x, y, w, h;
    struct Node* next;
} Node;

Node* head = NULL; // head of the linked-list of rooms

// Create a new room
Node* new_room(int x, int y, int w, int h) {
    Node* room = (Node*)malloc(sizeof(Node));
    room->x = x;
    room->y = y;
    room->w = w;
    room->h = h;
    room->next = NULL;
    return room;
}

// Add a room to the linked-list
void add_room(Node* room) {
    if (head == NULL) {
        head = room;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = room;
}

// Generate the map
void generate_map(char map[][MAP_WIDTH], int map_width, int map_height) {
    srand(time(NULL));
    // Fill entire map with walls
    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            map[y][x] = WALL;
        }
    }
    // Generate rooms and paths between them
    int num_rooms = rand() % 5 + 5; // Generate 5 to 9 rooms
    for (int i = 0; i < num_rooms; i++) {
        // Generate a new room
        int room_width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int room_height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int room_x = rand() % (map_width - room_width - 1) + 1;
        int room_y = rand() % (map_height - room_height - 1) + 1;
        Node* room = new_room(room_x, room_y, room_width, room_height);
        bool intersects = false;
        // Check if new room intersects with existing rooms
        Node* current = head;
        while (current != NULL) {
            if (room_x < current->x + current->w + 1 &&
                room_x + room_width + 1 > current->x &&
                room_y < current->y + current->h + 1 &&
                room_y + room_height + 1 > current->y) {
                intersects = true;
                break;
            }
            current = current->next;
        }
        if (intersects) {
            free(room);
        }
        else {
            // Add room to linked-list and fill it with floor tiles
            add_room(room);
            for (int y = room_y; y < room_y + room_height; y++) {
                for (int x = room_x; x < room_x + room_width; x++) {
                    map[y][x] = FLOOR;
                }
            }
        }
    }
    // Connect rooms with paths
    Node* current = head;
    while (current->next != NULL) {
        int x1 = current->x + current->w / 2;
        int y1 = current->y + current->h / 2;
        int x2 = current->next->x + current->next->w / 2;
        int y2 = current->next->y + current->next->h / 2;
        // Draw a horizontal line
        if (y1 == y2) {
            for (int x = x1; x < x2; x++) {
                map[y1][x] = FLOOR;
            }
            for (int x = x2; x < x1; x++) {
                map[y1][x] = FLOOR;
            }
        }
        // Draw a vertical line
        else {
            for (int y = y1; y < y2; y++) {
                map[y][x1] = FLOOR;
            }
            for (int y = y2; y < y1; y++) {
                map[y][x1] = FLOOR;
            }
        }
        current = current->next;
    }
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    generate_map(map, MAP_WIDTH, MAP_HEIGHT);
    // Print the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
    // Free memory used by linked-list of rooms
    Node* current = head;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    return 0;
}