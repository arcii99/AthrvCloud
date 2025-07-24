//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 25
#define ROOM_MAX_SIZE 10
#define ROOM_MIN_SIZE 5
#define MAX_ROOMS 8

typedef struct {
    int x, y, width, height;
} Room;

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    int x, y;
    char symbol;
    int is_walkable;
    Entity *entity;
} Tile;

typedef struct {
    Tile map[MAP_SIZE][MAP_SIZE];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} GameMap;

void create_room(GameMap *game_map, int index) {
    int room_width = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE);
    int room_height = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE);
    int room_x = rand() % (MAP_SIZE - room_width - 1) + 1;
    int room_y = rand() % (MAP_SIZE - room_height - 1) + 1;
    game_map->rooms[index].x = room_x;
    game_map->rooms[index].y = room_y;
    game_map->rooms[index].width = room_width;
    game_map->rooms[index].height = room_height;
}

int is_intersecting(Room room1, Room room2) {
    return (room1.x < room2.x + room2.width &&
            room1.x + room1.width > room2.x &&
            room1.y < room2.y + room2.height &&
            room1.y + room1.height > room2.y);
}

void create_h_tunnel(GameMap *game_map, int x_start, int x_end, int y) {
    int x_min = x_start < x_end ? x_start : x_end;
    int x_max = x_start > x_end ? x_start : x_end;
    for (int x = x_min; x < x_max + 1; x++) {
        game_map->map[x][y].is_walkable = 1;
        game_map->map[x][y].symbol = '.';
    }
}

void create_v_tunnel(GameMap *game_map, int y_start, int y_end, int x) {
    int y_min = y_start < y_end ? y_start : y_end;
    int y_max = y_start > y_end ? y_start : y_end;
    for (int y = y_min; y < y_max + 1; y++) {
        game_map->map[x][y].is_walkable = 1;
        game_map->map[x][y].symbol = '.';
    }
}

void create_corridors(GameMap *game_map) {
    for (int i = 0; i < game_map->num_rooms - 1; i++) {
        int x1 = game_map->rooms[i].x + game_map->rooms[i].width / 2;
        int y1 = game_map->rooms[i].y + game_map->rooms[i].height / 2;
        int x2 = game_map->rooms[i + 1].x + game_map->rooms[i + 1].width / 2;
        int y2 = game_map->rooms[i + 1].y + game_map->rooms[i + 1].height / 2;
        if (rand() % 2) {
            create_h_tunnel(game_map, x1, x2, y1);
            create_v_tunnel(game_map, y1, y2, x2);
        } else {
            create_v_tunnel(game_map, y1, y2, x1);
            create_h_tunnel(game_map, x1, x2, y2);
        }
    }
}

void place_entities(GameMap *game_map) {
    for (int i = 0; i < game_map->num_rooms; i++) {
        int num_entities = rand() % 3 + 1;
        for (int j = 0; j < num_entities; j++) {
            Entity *entity = malloc(sizeof(Entity));
            entity->symbol = 'E';
            int entity_x = game_map->rooms[i].x + rand() % game_map->rooms[i].width;
            int entity_y = game_map->rooms[i].y + rand() % game_map->rooms[i].height;
            entity->x = entity_x;
            entity->y = entity_y;
            game_map->map[entity_x][entity_y].entity = entity;
        }
    }
}

void generate_map(GameMap *game_map) {
    game_map->num_rooms = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            game_map->map[i][j].symbol = '#';
            game_map->map[i][j].is_walkable = 0;
        }
    }
    for (int i = 0; i < MAX_ROOMS; i++) {
        create_room(game_map, i);
        int is_intersect = 0;
        for (int j = 0; j < i; j++) {
            if (is_intersecting(game_map->rooms[i], game_map->rooms[j])) {
                is_intersect = 1;
                break;
            }
        }
        if (!is_intersect) {
            int room_x = game_map->rooms[i].x;
            int room_y = game_map->rooms[i].y;
            int room_width = game_map->rooms[i].width;
            int room_height = game_map->rooms[i].height;
            for (int x = room_x; x < room_x + room_width; x++) {
                for (int y = room_y; y < room_y + room_height; y++) {
                    game_map->map[x][y].is_walkable = 1;
                    game_map->map[x][y].symbol = '.';
                }
            }
            game_map->num_rooms++;
        }
    }
    create_corridors(game_map);
    place_entities(game_map);
}

void print_map(GameMap *game_map) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (game_map->map[x][y].entity != NULL) {
                printf("%c", game_map->map[x][y].entity->symbol);
            } else {
                printf("%c", game_map->map[x][y].symbol);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    GameMap game_map;
    generate_map(&game_map);
    print_map(&game_map);
    return 0;
}