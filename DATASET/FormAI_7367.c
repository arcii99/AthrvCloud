//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 8
#define MIN_ROOM_SIZE 3

// Struct for the player
typedef struct {
    int x;
    int y;
    int health;
    int gold;
} Player;

// Enum for terrain types
enum Terrain {
    WALL = '#',
    FLOOR = '.',
    STAIRS_UP = '<',
    STAIRS_DOWN = '>'
};

// Struct for a room
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// Function to draw the map
void drawMap(char map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly generate rooms
void generateRooms(Room rooms[]) {
    int numRooms = 0;
    while (numRooms < MAX_ROOMS) {
        int x = rand() % (WIDTH - MAX_ROOM_SIZE - 1) + 1;
        int y = rand() % (HEIGHT - MAX_ROOM_SIZE - 1) + 1;
        int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        Room newRoom = {x, y, width, height};

        int intersects = 0;
        for (int i = 0; i < numRooms; i++) {
            if (newRoom.x < rooms[i].x + rooms[i].width &&
                newRoom.x + newRoom.width > rooms[i].x &&
                newRoom.y < rooms[i].y + rooms[i].height &&
                newRoom.y + newRoom.height > rooms[i].y) {
                intersects = 1;
                break;
            }
        }

        if (!intersects) {
            rooms[numRooms] = newRoom;
            numRooms++;
        }
    }
}

// Function to connect the rooms with corridors
void connectRooms(char map[HEIGHT][WIDTH], Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int startX = rooms[i].x + rooms[i].width / 2;
        int startY = rooms[i].y + rooms[i].height / 2;
        int endX = rooms[i + 1].x + rooms[i + 1].width / 2;
        int endY = rooms[i + 1].y + rooms[i + 1].height / 2;

        while (startX != endX) {
            if (startX < endX) {
                startX++;
            } else {
                startX--;
            }
            map[startY][startX] = FLOOR;
        }

        while (startY != endY) {
            if (startY < endY) {
                startY++;
            } else {
                startY--;
            }
            map[startY][startX] = FLOOR;
        }
    }
}

// Function to place the player
void placePlayer(char map[HEIGHT][WIDTH], Player *player, Room rooms[]) {
    int roomIndex = rand() % MAX_ROOMS;
    player->x = rooms[roomIndex].x + rooms[roomIndex].width / 2;
    player->y = rooms[roomIndex].y + rooms[roomIndex].height / 2;
    map[player->y][player->x] = '@';
}

// Function to place the stairs
void placeStairs(char map[HEIGHT][WIDTH], Room rooms[]) {
    int upRoomIndex = rand() % MAX_ROOMS;
    int downRoomIndex = rand() % MAX_ROOMS;
    while (downRoomIndex == upRoomIndex) {
        downRoomIndex = rand() % MAX_ROOMS;
    }

    int upX = rooms[upRoomIndex].x + rooms[upRoomIndex].width / 2;
    int upY = rooms[upRoomIndex].y + rooms[upRoomIndex].height / 2;
    int downX = rooms[downRoomIndex].x + rooms[downRoomIndex].width / 2;
    int downY = rooms[downRoomIndex].y + rooms[downRoomIndex].height / 2;

    map[upY][upX] = STAIRS_UP;
    map[downY][downX] = STAIRS_DOWN;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize map
    char map[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = WALL;
        }
    }

    // Generate rooms and connect them with corridors
    Room rooms[MAX_ROOMS];
    generateRooms(rooms);
    connectRooms(map, rooms);

    // Place player and stairs
    Player player = {0, 0, 100, 0};
    placePlayer(map, &player, rooms);
    placeStairs(map, rooms);

    // Draw map and player info
    printf("Welcome to the Rogue-like game!\n\n");
    printf("Controls: Arrow keys to move, q to quit\n\n");
    printf("Player Info: Health - %d, Gold - %d\n\n", player.health, player.gold);
    drawMap(map);

    // Main game loop
    int gameOver = 0;
    while (!gameOver) {
        // Update player info
        printf("\nPlayer Info: Health - %d, Gold - %d\n\n", player.health, player.gold);

        // Get input
        char input = getchar();

        // Move player
        int newX = player.x;
        int newY = player.y;
        switch (input) {
            case 'q':
                gameOver = 1;
                break;
            case 'w':
            case 'W':
                newY--;
                break;
            case 'a':
            case 'A':
                newX--;
                break;
            case 's':
            case 'S':
                newY++;
                break;
            case 'd':
            case 'D':
                newX++;
                break;
        }

        // Check for collision with wall
        if (map[newY][newX] == WALL) {
            printf("You bump into a wall!\n");
        } else {
            // Move player
            map[player.y][player.x] = FLOOR;
            player.x = newX;
            player.y = newY;
            map[player.y][player.x] = '@';

            // Check for collision with stairs
            if (map[player.y][player.x] == STAIRS_UP) {
                printf("You climb up the stairs!\n");
                gameOver = 1;
            } else if (map[player.y][player.x] == STAIRS_DOWN) {
                printf("You climb down the stairs!\n");
                gameOver = 1;
            }
        }
    }

    return 0;
}