//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    char symbol;
} Monster;

typedef struct {
    Position pos;
    int width;
    int height;
} Room;

char map[MAP_HEIGHT][MAP_WIDTH];
Room rooms[MAX_ROOMS];
Monster monsters[MAX_MONSTERS];
int num_rooms, num_monsters;

void initialize_map();
void print_map();
void generate_rooms();
void connect_rooms();
void generate_monsters();
void place_monsters();

int main() {
    // Seed random number generator
    srand(time(NULL));

    initialize_map();
    generate_rooms();
    connect_rooms();
    generate_monsters();
    place_monsters();

    print_map();

    return 0;
}

void initialize_map() {
    // Set all positions to wall
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generate_rooms() {
    // Generate random rooms
    num_rooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % 8 + 4;
        int height = rand() % 8 + 4;
        int x = rand() % (MAP_WIDTH - width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - height - 1) + 1;

        Room new_room = { {x, y}, width, height };
        rooms[num_rooms] = new_room;
        num_rooms++;

        // Place room on map
        for (int j = y; j < y + height; j++) {
            for (int k = x; k < x + width; k++) {
                map[j][k] = ' ';
            }
        }
    }
}

void connect_rooms() {
    // Connect all rooms
    for (int i = 0; i < num_rooms - 1; i++) {
        Position center1 = { rooms[i].pos.x + rooms[i].width/2, rooms[i].pos.y + rooms[i].height/2 };
        Position center2 = { rooms[i+1].pos.x + rooms[i+1].width/2, rooms[i+1].pos.y + rooms[i+1].height/2 };

        // Draw tunnel between rooms
        int x = center1.x, y = center1.y;
        while (x != center2.x) {
            map[y][x] = '.';
            if (x < center2.x) {
                x++;
            } else {
                x--;
            }
        }
        while (y != center2.y) {
            map[y][x] = '.';
            if (y < center2.y) {
                y++;
            } else {
                y--;
            }
        }
    }
}

void generate_monsters() {
    // Generate random monsters
    num_monsters = 0;
    for (int i = 0; i < MAX_MONSTERS; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        char symbol = 'M';
        int health = rand() % 10 + 1;

        Monster new_monster = { {x, y}, health, symbol };
        monsters[num_monsters] = new_monster;
        num_monsters++;

        // Place monster on map
        map[y][x] = symbol;
    }
}

void place_monsters() {
    // Place monsters in rooms
    for (int i = 0; i < num_rooms; i++) {
        int num_monsters_in_room = rand() % (num_monsters / num_rooms + 1);
        for (int j = 0; j < num_monsters_in_room; j++) {
            int index = rand() % num_monsters;
            while (monsters[index].pos.x < rooms[i].pos.x ||
                   monsters[index].pos.x >= rooms[i].pos.x + rooms[i].width ||
                   monsters[index].pos.y < rooms[i].pos.y ||
                   monsters[index].pos.y >= rooms[i].pos.y + rooms[i].height) {
                index = rand() % num_monsters;
            }
            map[monsters[index].pos.y][monsters[index].pos.x] = ' ';
            monsters[index].pos.x = rand() % rooms[i].width + rooms[i].pos.x;
            monsters[index].pos.y = rand() % rooms[i].height + rooms[i].pos.y;
            map[monsters[index].pos.y][monsters[index].pos.x] = monsters[index].symbol;
        }
    }
}