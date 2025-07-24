//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 21
#define PLAYER_SYMBOL '@'
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 10

typedef struct {
    int x, y, w, h;
} Room;

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    char map[MAP_HEIGHT][MAP_WIDTH];
    Room rooms[MAX_ROOMS];
    Entity player;
} Game;

void initialize_game(Game *game);
void generate_map(Game *game);
bool is_room_overlap(const Room *r1, const Room *r2);
void create_room(char map[][MAP_WIDTH], const Room *room);
void connect_rooms(char map[][MAP_WIDTH], const Room *r1, const Room *r2);
void place_entities(Game *game);
void render_game(const Game *game);
void handle_input(Game *game);
bool is_valid_move(const Game *game, int x, int y);

int main(void)
{
    Game game;
    initialize_game(&game);
    generate_map(&game);
    place_entities(&game);
    while (true) {
        render_game(&game);
        handle_input(&game);
    }
    return 0;
}

void initialize_game(Game *game)
{
    srand(time(NULL));
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            game->map[y][x] = '#';
        }
    }
    for (int i = 0; i < MAX_ROOMS; i++) {
        game->rooms[i].x = 0;
        game->rooms[i].y = 0;
        game->rooms[i].w = 0;
        game->rooms[i].h = 0;
    }
    game->player.x = 0;
    game->player.y = 0;
    game->player.symbol = PLAYER_SYMBOL;
}

void generate_map(Game *game)
{
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        int room_x = rand() % (MAP_WIDTH - ROOM_MAX_SIZE - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - ROOM_MAX_SIZE - 1) + 1;
        int room_w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int room_h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        Room new_room = {room_x, room_y, room_w, room_h};
        if (is_room_overlap(&new_room, &game->rooms[num_rooms])) {
            continue;
        }
        create_room(game->map, &new_room);
        if (num_rooms > 0) {
            connect_rooms(game->map, &new_room, &game->rooms[num_rooms - 1]);
        }
        game->rooms[num_rooms++] = new_room;
    }
    game->player.x = game->rooms[0].x + game->rooms[0].w / 2;
    game->player.y = game->rooms[0].y + game->rooms[0].h / 2;
}

bool is_room_overlap(const Room *r1, const Room *r2)
{
    return r1->x + r1->w >= r2->x && r2->x + r2->w >= r1->x &&
           r1->y + r1->h >= r2->y && r2->y + r2->h >= r1->y;
}

void create_room(char map[][MAP_WIDTH], const Room *room)
{
    for (int y = room->y; y < room->y + room->h; y++) {
        for (int x = room->x; x < room->x + room->w; x++) {
            map[y][x] = '.';
        }
    }
}

void connect_rooms(char map[][MAP_WIDTH], const Room *r1, const Room *r2)
{
    int x1 = r1->x + r1->w / 2, y1 = r1->y + r1->h / 2;
    int x2 = r2->x + r2->w / 2, y2 = r2->y + r2->h / 2;
    while (x1 != x2) {
        x1 += (x1 < x2) ? 1 : -1;
        map[y1][x1] = '.';
    }
    while (y1 != y2) {
        y1 += (y1 < y2) ? 1 : -1;
        map[y1][x1] = '.';
    }
}

void place_entities(Game *game)
{
    for (int i = 1; i < MAX_ROOMS; i++) {
        int x = game->rooms[i].x + rand() % game->rooms[i].w;
        int y = game->rooms[i].y + rand() % game->rooms[i].h;
        game->map[y][x] = 'E';
    }
    game->map[game->player.y][game->player.x] = game->player.symbol;
}

void render_game(const Game *game)
{
    printf("\n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", game->map[y][x]);
        }
        printf("\n");
    }
}

void handle_input(Game *game)
{
    int dx = 0, dy = 0;
    char c = getchar();
    switch (c) {
        case 'w': dy = -1; break;
        case 's': dy = 1; break;
        case 'a': dx = -1; break;
        case 'd': dx = 1; break;
        default: break;
    }
    if (is_valid_move(game, game->player.x + dx, game->player.y + dy)) {
        game->map[game->player.y][game->player.x] = '.';
        game->player.x += dx;
        game->player.y += dy;
        game->map[game->player.y][game->player.x] = game->player.symbol;
    }
}

bool is_valid_move(const Game *game, int x, int y)
{
    return x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT &&
           game->map[y][x] != '#';
}