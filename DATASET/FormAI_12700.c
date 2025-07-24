//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef enum {
    FLOOR,
    WALL,
    DOOR,
} TileType;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int width;
    int height;
} Room;

typedef struct Monster {
    char signature;
    Point position;
    int health;
    int damage;
    struct Monster* next;
} Monster;

typedef struct {
    TileType map[MAP_WIDTH][MAP_HEIGHT];
    Room rooms[MAX_ROOMS];
    int num_rooms;
    Monster* monsters;
} Map;

Point get_random_point(int width, int height) {
    Point point;
    point.x = rand() % width;
    point.y = rand() % height;
    return point;
}

void print_map(Map* map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            switch (map->map[x][y]) {
                case FLOOR:
                    printf(".");
                    break;
                case WALL:
                    printf("#");
                    break;
                case DOOR:
                    printf("+");
                    break;
            }
        }
        printf("\n");
    }
}

void generate_room(Map* map, Point position, int width, int height) {
    Room* room = &(map->rooms[map->num_rooms++]);
    room->position = position;
    room->width = width;
    room->height = height;
    
    for (int x = position.x; x < position.x + width; x++) {
        for (int y = position.y; y < position.y + height; y++) {
            if (x == position.x || x == position.x + width - 1 || y == position.y || y == position.y + height - 1) {
                map->map[x][y] = WALL;
            } else {
                map->map[x][y] = FLOOR;
            }
        }
    }
}

void generate_map(Map* map) {
    // Initialize map with all walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map->map[x][y] = WALL;
        }
    }
    
    // Generate rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % 8 + 4;
        int height = rand() % 6 + 3;
        Point position = get_random_point(MAP_WIDTH - width, MAP_HEIGHT - height);
        generate_room(map, position, width, height);
    }
    
    // Connect rooms with doors
    for (int i = 0; i < map->num_rooms - 1; i++) {
        Room room1 = map->rooms[i];
        Room room2 = map->rooms[i + 1];
        
        Point door1 = get_random_point(room1.width - 2, room1.height - 2);
        door1.x += room1.position.x + 1;
        door1.y += room1.position.y + 1;
        map->map[door1.x][door1.y] = DOOR;
        
        Point door2 = get_random_point(room2.width - 2, room2.height - 2);
        door2.x += room2.position.x + 1;
        door2.y += room2.position.y + 1;
        map->map[door2.x][door2.y] = DOOR;
        
        // Generate hallway
        int x = door1.x;
        int y = door1.y;
        while (x != door2.x || y != door2.y) {
            if (x != door2.x) {
                if (x < door2.x) {
                    x++;
                } else {
                    x--;
                }
            } else {
                if (y < door2.y) {
                    y++;
                } else {
                    y--;
                }
            }
            if (map->map[x][y] == WALL) {
                map->map[x][y] = FLOOR;
            }
        }
    }
}

void add_monster(Map* map, char signature, int health, int damage) {
    Monster* monster = malloc(sizeof(Monster));
    monster->signature = signature;
    monster->position = get_random_point(MAP_WIDTH, MAP_HEIGHT);
    while (map->map[monster->position.x][monster->position.y] == WALL) {
        monster->position = get_random_point(MAP_WIDTH, MAP_HEIGHT);
    }
    monster->health = health;
    monster->damage = damage;
    monster->next = map->monsters;
    map->monsters = monster;
}

void add_monsters(Map* map) {
    add_monster(map, 'O', 10, 3);
    add_monster(map, 'D', 15, 2);
    add_monster(map, 'G', 20, 5);
    add_monster(map, 'K', 30, 4);
    add_monster(map, 'T', 50, 10);
}

void print_monsters(Map* map) {
    Monster* monster = map->monsters;
    while (monster != NULL) {
        printf("%c: (%d,%d) %d hp, %d damage\n", monster->signature, monster->position.x, monster->position.y, monster->health, monster->damage);
        monster = monster->next;
    }
}

void move_monsters(Map* map) {
    Monster* monster = map->monsters;
    while (monster != NULL) {
        // Choose random direction
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        Point new_position = monster->position;
        new_position.x += dx;
        new_position.y += dy;
        
        // Check if new position is valid
        if (new_position.x >= 0 && new_position.x < MAP_WIDTH && new_position.y >= 0 && new_position.y < MAP_HEIGHT
            && map->map[new_position.x][new_position.y] != WALL) {
            // Update monster position
            monster->position = new_position;
        }
        monster = monster->next;
    }
}

int main() {
    srand(time(NULL));
    
    // Generate map
    Map map;
    map.num_rooms = 0;
    map.monsters = NULL;
    generate_map(&map);
    add_monsters(&map);
    
    // Game loop
    int player_health = 100;
    while (player_health > 0) {
        // Print map
        print_map(&map);
        
        // Print monsters
        print_monsters(&map);
        
        // Move monsters
        move_monsters(&map);
        
        // Wait for player input
        printf("Enter direction (x y): ");
        int x, y;
        scanf("%d %d", &x, &y);
        
        // Move player
        Point player_position = map.rooms[0].position;
        player_position.x += x;
        player_position.y += y;
        if (player_position.x >= 0 && player_position.x < MAP_WIDTH && player_position.y >= 0 && player_position.y < MAP_HEIGHT) {
            if (map.map[player_position.x][player_position.y] == FLOOR) {
                printf("You move to (%d,%d)\n", player_position.x, player_position.y);
            } else if (map.map[player_position.x][player_position.y] == DOOR) {
                printf("You open the door to (%d,%d)\n", player_position.x, player_position.y);
            } else {
                printf("Ouch! You bump into a wall at (%d,%d)\n", player_position.x, player_position.y);
                player_health -= 5;
            }
        } else {
            printf("Ouch! You bump into a wall at (%d,%d)\n", player_position.x, player_position.y);
            player_health -= 5;
        }
    }
    
    printf("Game over!\n");
    
    return 0;
}