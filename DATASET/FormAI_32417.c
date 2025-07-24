//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50
#define MAX_ROOMS 6
#define MIN_ROOM_WIDTH 4
#define MAX_ROOM_WIDTH 12
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_HEIGHT 10
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'
#define STAIRS '>'
#define MONSTER 'M'
#define TREASURE '$'

char dungeon[ROWS][COLS];
int room_count = 0;

typedef struct {
    int x, y, width, height;
} room_t;

room_t rooms[MAX_ROOMS];

/* Function prototypes */
void generate_dungeon();
void initialize_dungeon();
void paint_wall(int x, int y);
void paint_floor(int x, int y);
void paint_room(room_t room);
void connect_rooms();
void paint_player();
void paint_monsters();
void paint_treasure();
void paint_stairs();
void print_dungeon();
void game_loop();
void move_player();
int get_random(int min, int max);

int main() {
    srand(time(NULL));

    initialize_dungeon();

    generate_dungeon();

    paint_player();

    paint_monsters();

    paint_treasure();

    paint_stairs();

    print_dungeon();

    game_loop();

    return 0;
}

void generate_dungeon() {
    // Set all cells to 'wall'
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            dungeon[i][j] = WALL;
        }
    }

    // Generate rooms
    while(room_count < MAX_ROOMS) {
        int x = get_random(1, COLS-MAX_ROOM_WIDTH-1);
        int y = get_random(1, ROWS-MAX_ROOM_HEIGHT-1);
        int width = get_random(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);
        int height = get_random(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);

        room_t room = {x, y, width, height};

        // Check if the room intersects with any existing rooms
        int intersects = 0;
        for(int i = 0; i < room_count; i++) {
            if(room.x < rooms[i].x + rooms[i].width + 2 && 
                room.x + room.width + 2 > rooms[i].x &&
                room.y < rooms[i].y + rooms[i].height + 2 &&
                room.y + room.height + 2 > rooms[i].y) {
                    intersects = 1;
                    break;
            }
        }

        if(!intersects) {
            paint_room(room);
            rooms[room_count++] = room;
        }
    }

    connect_rooms();
}

void initialize_dungeon() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            dungeon[i][j] = WALL;
        }
    }
}

void paint_wall(int x, int y) {
    dungeon[y][x] = WALL;
}

void paint_floor(int x, int y) {
    dungeon[y][x] = FLOOR;
}

void paint_room(room_t room) {
    for(int i = room.y; i < room.y + room.height; i++) {
        for(int j = room.x; j < room.x + room.width; j++) {
            paint_floor(j, i);
        }
    }
}

void connect_rooms() {
    for(int i = 0; i < room_count-1; i++) {
        int x1 = get_random(rooms[i].x, rooms[i].x + rooms[i].width);
        int x2 = get_random(rooms[i+1].x, rooms[i+1].x + rooms[i+1].width);
        int y1 = get_random(rooms[i].y, rooms[i].y + rooms[i].height);
        int y2 = get_random(rooms[i+1].y, rooms[i+1].y + rooms[i+1].height);

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        int x = x1, y = y1;
        int n = dx + dy;
        int x_inc = (x2 > x1) ? 1 : -1;
        int y_inc = (y2 > y1) ? 1 : -1;
        int error = dx - dy;

        dx *= 2;
        dy *= 2;

        for(int j = 0; j < n; j++) {
            paint_floor(x, y);

            if (error > 0) {
                x += x_inc;
                error -= dy;    
            } else {
                y += y_inc;
                error += dx;
            }
        }
    }
}

void paint_player() {
    int x = get_random(rooms[0].x+1, rooms[0].x+rooms[0].width-1);
    int y = get_random(rooms[0].y+1, rooms[0].y+rooms[0].height-1);
    dungeon[y][x] = PLAYER;
}

void paint_monsters() {
    for(int i = 0; i < room_count; i++) {
        int x = get_random(rooms[i].x+1, rooms[i].x+rooms[i].width-1);
        int y = get_random(rooms[i].y+1, rooms[i].y+rooms[i].height-1);
        if(dungeon[y][x] == FLOOR) {
            dungeon[y][x] = MONSTER;
        }
    }
}

void paint_treasure() {
    for(int i = 0; i < room_count; i++) {
        int x = get_random(rooms[i].x+1, rooms[i].x+rooms[i].width-1);
        int y = get_random(rooms[i].y+1, rooms[i].y+rooms[i].height-1);
        if(dungeon[y][x] == FLOOR) {
            dungeon[y][x] = TREASURE;
        }
    }
}

void paint_stairs() {
    int x = get_random(rooms[room_count-1].x+1, rooms[room_count-1].x+rooms[room_count-1].width-1);
    int y = get_random(rooms[room_count-1].y+1, rooms[room_count-1].y+rooms[room_count-1].height-1);
    dungeon[y][x] = STAIRS;
}

void print_dungeon() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

void game_loop() {
    int game_over = 0;

    while(!game_over) {
        move_player();

        print_dungeon();
    }
}

void move_player() {
    int x = 0, y = 0;
    int player_x, player_y;

    // Find player position
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(dungeon[i][j] == PLAYER) {
                player_x = j;
                player_y = i;
                break;
            }
        }
    }

    // Get player input
    char input = getchar();

    switch(input) {
        case 'w':
            x = player_x;
            y = player_y - 1;
            break;
        case 'a':
            x = player_x - 1;
            y = player_y;
            break;
        case 's':
            x = player_x;
            y = player_y + 1;
            break;
        case 'd':
            x = player_x + 1;
            y = player_y;
            break;
        case 'q':
            exit(0);
        default:
            printf("Invalid input\n");
            break;
    }

    // Check if move is valid
    if(dungeon[y][x] == FLOOR) {
        dungeon[y][x] = PLAYER;
        dungeon[player_y][player_x] = FLOOR;
    }
}

int get_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}