//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game variables
#define MAP_WIDTH 80
#define MAP_HEIGHT 25
#define MAX_ROOMS 12
#define MAX_ROOM_SIZE 15
#define MIN_ROOM_SIZE 5
#define MAX_MONSTERS 8

// Define structs for game objects
struct Coordinate {
    int x;
    int y;
};

struct Room {
    struct Coordinate position;
    int width;
    int height;
};

struct Monster {
    struct Coordinate position;
    char symbol;
    int health;
};

// Declare global variables
char map[MAP_HEIGHT][MAP_WIDTH];
struct Room rooms[MAX_ROOMS];
int numRooms = 0;
struct Monster monsters[MAX_MONSTERS];
int numMonsters = 0;

// Function prototypes
void generateMap();
void placeRooms();
void addRoom(int x, int y, int width, int height);
void connectRooms();
void placePlayer(struct Coordinate *player);
void placeMonsters();
void drawMap(struct Coordinate player);
void movePlayer(struct Coordinate *player, int deltaX, int deltaY);
void moveMonsters();

int main() {
    // Seed the RNG
    srand(time(NULL));
    
    // Generate the map and place objects
    generateMap();
    struct Coordinate player;
    placePlayer(&player);
    placeMonsters();
    
    // Main game loop
    while(1) {
        // Draw the map and wait for user input
        drawMap(player);
        printf("Move with WASD. Q to quit.\n");
        char input = getchar();
        getchar();  // Consume the newline character
        
        // Handle user input
        int deltaX = 0, deltaY = 0;
        switch(input) {
            case 'w':
                deltaY = -1;
                break;
            case 's':
                deltaY = 1;
                break;
            case 'a':
                deltaX = -1;
                break;
            case 'd':
                deltaX = 1;
                break;
            case 'q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }
        
        // Move the player
        movePlayer(&player, deltaX, deltaY);
        
        // Move the monsters
        moveMonsters();
    }
}

void generateMap() {
    // Initialize the map to be empty
    for(int y = 0; y < MAP_HEIGHT; y++) {
        for(int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = ' ';
        }
    }
    
    // Place rooms
    placeRooms();
    
    // Connect rooms with tunnels
    connectRooms();
}

void placeRooms() {
    for(int i = 0; i < MAX_ROOMS; i++) {
        // Choose a random position and size for the room
        int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;
        
        // Add the new room to the list of rooms
        addRoom(x, y, width, height);
    }
}

void addRoom(int x, int y, int width, int height) {
    // Initialize the new room struct
    struct Room room = {
        .position = { .x = x, .y = y },
        .width = width,
        .height = height
    };
    
    // Check if the new room overlaps with any existing rooms
    for(int i = 0; i < numRooms; i++) {
        // Calculate the coordinates of the intersection between the two rooms
        int top = room.position.y - 1;
        int bottom = room.position.y + room.height;
        int left = room.position.x - 1;
        int right = room.position.x + room.width;
        
        int existingTop = rooms[i].position.y - 1;
        int existingBottom = rooms[i].position.y + rooms[i].height;
        int existingLeft = rooms[i].position.x - 1;
        int existingRight = rooms[i].position.x + rooms[i].width;
        
        // If there is any overlap, abort before adding the new room
        if(bottom >= existingTop && top <= existingBottom && right >= existingLeft && left <= existingRight) {
            return;
        }
    }
    
    // If there is no overlap, add the new room to the list
    rooms[numRooms++] = room;
    
    // Carve out the room in the map
    for(int y = room.position.y; y < room.position.y + room.height; y++) {
        for(int x = room.position.x; x < room.position.x + room.width; x++) {
            map[y][x] = '.';
        }
    }
}

void connectRooms() {
    // Connect all rooms in order
    for(int i = 0; i < numRooms - 1; i++) {
        int startX = rooms[i].position.x + rooms[i].width / 2;
        int startY = rooms[i].position.y + rooms[i].height / 2;
        int endX = rooms[i+1].position.x + rooms[i+1].width / 2;
        int endY = rooms[i+1].position.y + rooms[i+1].height / 2;
        
        // Carve out the tunnel in the map
        int x = startX, y = startY;
        while(x != endX) {
            x += (x < endX ? 1 : -1);
            map[y][x] = '#';
        }
        while(y != endY) {
            y += (y < endY ? 1 : -1);
            map[y][x] = '#';
        }
    }
}

void placePlayer(struct Coordinate *player) {
    // Choose a random room
    int roomIndex = rand() % numRooms;
    struct Room room = rooms[roomIndex];
    
    // Place the player in the center of the room
    player->x = room.position.x + room.width / 2;
    player->y = room.position.y + room.height / 2;
}

void placeMonsters() {
    for(int i = 0; i < MAX_MONSTERS; i++) {
        // Choose a random room
        int roomIndex = rand() % numRooms;
        struct Room room = rooms[roomIndex];

        // Place the monster in a random location in the room
        int x = room.position.x + rand() % room.width;
        int y = room.position.y + rand() % room.height;
        
        // Initialize the new monster struct
        struct Monster monster = {
            .position = { .x = x, .y = y },
            .symbol = 'M',
            .health = 5
        };
        
        // Add the new monster to the list of monsters
        monsters[numMonsters++] = monster;
        
        // Carve out the monster in the map
        map[y][x] = monster.symbol;
    }
}

void drawMap(struct Coordinate player) {
    // Clear the screen
    system("clear");
    
    // Draw the map
    for(int y = 0; y < MAP_HEIGHT; y++) {
        for(int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    
    // Draw the player location
    printf("Player: @ (%d,%d)\n", player.x, player.y);
    
    // Draw the monster locations
    for(int i = 0; i < numMonsters; i++) {
        printf("Monster %d: %c (%d,%d)\n", i+1, monsters[i].symbol, monsters[i].position.x, monsters[i].position.y);
    }
}

void movePlayer(struct Coordinate *player, int deltaX, int deltaY) {
    // Calculate the new player position, and check if it is valid
    int newX = player->x + deltaX;
    int newY = player->y + deltaY;
    if(newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT) {
        return;
    }
    if(map[newY][newX] == '#') {
        return;
    }
    
    // Update the player position and carve out the new location in the map
    map[player->y][player->x] = ' ';
    player->x = newX;
    player->y = newY;
    map[player->y][player->x] = '@';
}

void moveMonsters() {
    for(int i = 0; i < numMonsters; i++) {
        // Choose a random direction to move
        int deltaX = rand() % 3 - 1;
        int deltaY = rand() % 3 - 1;
        
        // Calculate the new monster position, and check if it is valid
        int newX = monsters[i].position.x + deltaX;
        int newY = monsters[i].position.y + deltaY;
        if(newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT) {
            continue;
        }
        if(map[newY][newX] == '#') {
            continue;
        }
        
        // Update the monster position and carve out the new location in the map
        map[monsters[i].position.y][monsters[i].position.x] = ' ';
        monsters[i].position.x = newX;
        monsters[i].position.y = newY;
        map[monsters[i].position.y][monsters[i].position.x] = monsters[i].symbol;
    }
}