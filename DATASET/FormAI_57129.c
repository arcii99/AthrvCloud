//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 5
#define MIN_SIZE 3
#define MAX_SIZE 6

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    int x;
    int y;
    char symbol;
} Entity;

void map_init(char map[WIDTH][HEIGHT]);
void map_print(char map[WIDTH][HEIGHT], Entity player);
bool map_is_occupied(char map[WIDTH][HEIGHT], int x, int y);
void map_create_rooms(char map[WIDTH][HEIGHT], Room *rooms);
void map_connect_rooms(char map[WIDTH][HEIGHT], Room *rooms);
Entity map_get_player(char map[WIDTH][HEIGHT]);
void entities_init(Entity entities[], Room rooms[]);
void entities_print(Entity entities[], int num_entities);
bool entities_move(Entity *entity, char map[WIDTH][HEIGHT], int dx, int dy);
bool check_collision(Entity *entity, Entity entities[], int num_entities);

int main(void) {
    char map[WIDTH][HEIGHT];
    Room rooms[MAX_ROOMS];
    Entity entities[MAX_ROOMS + 1];
    int num_entities = MAX_ROOMS + 1;

    srand(time(NULL));

    map_init(map);
    map_create_rooms(map, rooms);
    map_connect_rooms(map, rooms);
    entities_init(entities, rooms);
    entities_print(entities, num_entities);

    while (true) {
        Entity player = map_get_player(map);
        map_print(map, player);

        char input = getchar();
        getchar(); // discard newline

        if (input == 'q') {
            break;
        }

        int x = 0, y = 0;

        switch (input) {
            case 'w':
                y = -1;
                break;
            case 's':
                y = 1;
                break;
            case 'a':
                x = -1;
                break;
            case 'd':
                x = 1;
                break;
        }

        bool moved = entities_move(&player, map, x, y);

        if (moved) {
            Entity *entity = &entities[num_entities - 1];

            if (check_collision(&player, entities, num_entities - 1)) {
                printf("You were killed by %c!\n", entity->symbol);
                break;
            }

            entity->x = player.x;
            entity->y = player.y;
        }
    }

    return 0;
}

void map_init(char map[WIDTH][HEIGHT]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            map[x][y] = '#';
        }
    }
}

void map_print(char map[WIDTH][HEIGHT], Entity player) {
    printf("\033[2J\033[1;1H"); // clear console

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (player.x == x && player.y == y) {
                putchar('@');
            } else {
                putchar(map[x][y]);
            }
        }

        putchar('\n');
    }
}

bool map_is_occupied(char map[WIDTH][HEIGHT], int x, int y) {
    return map[x][y] != '#';
}

void map_create_rooms(char map[WIDTH][HEIGHT], Room *rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % (MAX_SIZE - MIN_SIZE) + MIN_SIZE;
        int height = rand() % (MAX_SIZE - MIN_SIZE) + MIN_SIZE;
        int x = rand() % (WIDTH - width - 2) + 1;
        int y = rand() % (HEIGHT - height - 2) + 1;

        Room room = (Room) { x, y, width, height };

        for (int j = 0; j < i; j++) {
            if (room.x < rooms[j].x + rooms[j].width &&
                room.x + room.width > rooms[j].x &&
                room.y < rooms[j].y + rooms[j].height &&
                room.y + room.height > rooms[j].y) {
                i--;
                goto retry;
            }
        }

        rooms[i] = room;

        for (int x = room.x; x < room.x + width; x++) {
            for (int y = room.y; y < room.y + height; y++) {
                map[x][y] = '.';
            }
        }

    retry:;
    }
}

void map_connect_rooms(char map[WIDTH][HEIGHT], Room *rooms) {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room a = rooms[i];
        Room b = rooms[i + 1];

        int x = a.x + a.width / 2;
        int y = a.y + a.height / 2;

        while (x != b.x + b.width / 2) {
            if (x < b.x + b.width / 2) {
                x++;
            } else {
                x--;
            }

            if (!map_is_occupied(map, x, y)) {
                map[x][y] = '.';
            }
        }

        while (y != b.y + b.height / 2) {
            if (y < b.y + b.height / 2) {
                y++;
            } else {
                y--;
            }

            if (!map_is_occupied(map, x, y)) {
                map[x][y] = '.';
            }
        }
    }
}

Entity map_get_player(char map[WIDTH][HEIGHT]) {
    Entity player = (Entity) { 0, 0, '@' };

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (map[x][y] == '@') {
                player.x = x;
                player.y = y;
                break;
            }
        }
    }

    return player;
}

void entities_init(Entity entities[], Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        entities[i] = (Entity) { rooms[i].x + rooms[i].width / 2, rooms[i].y + rooms[i].height / 2, 'O' };
    }

    entities[MAX_ROOMS] = (Entity) { -1, -1, 'X' };
}

void entities_print(Entity entities[], int num_entities) {
    for (int i = 0; i < num_entities; i++) {
        Entity entity = entities[i];
        printf("%c: (%d, %d)\n", entity.symbol, entity.x, entity.y);
    }
}

bool entities_move(Entity *entity, char map[WIDTH][HEIGHT], int dx, int dy) {
    int x = entity->x + dx;
    int y = entity->y + dy;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || map_is_occupied(map, x, y)) {
        return false;
    }

    entity->x = x;
    entity->y = y;

    return true;
}

bool check_collision(Entity *entity, Entity entities[], int num_entities) {
    for (int i = 0; i < num_entities; i++) {
        Entity other = entities[i];

        if (entity->x == other.x && entity->y == other.y) {
            return true;
        }
    }

    return false;
}