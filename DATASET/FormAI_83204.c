//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 20

struct Tile {
    char symbol;
    char color[10];
    int walkable;
};

struct Coord {
    int x;
    int y;
};

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

void clear_screen() {
    system("cls || clear");
}

void print_title() {
    printf("\n\n");
    printf(" █████╗  ██████╗ ███╗   ███╗███╗   ██╗███████╗██████╗ ██╗      █████╗ ███╗   ██╗███████╗\n");
    printf("██╔══██╗██╔════╝ ████╗ ████║████╗  ██║██╔════╝██╔══██╗██║     ██╔══██╗████╗  ██║██╔════╝\n");
    printf("███████║██║  ███╗██╔████╔██║██╔██╗ ██║█████╗  ██████╔╝██║     ███████║██╔██╗ ██║█████╗  \n");
    printf("██╔══██║██║   ██║██║╚██╔╝██║██║╚██╗██║██╔══╝  ██╔══██╗██║     ██╔══██║██║╚██╗██║██╔══╝  \n");
    printf("██║  ██║╚██████╔╝██║ ╚═╝ ██║██║ ╚████║███████╗██║  ██║███████╗██║  ██║██║ ╚████║███████╗\n");
    printf("╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝\n");
    printf("\n\n");
}

void print_map(struct Tile map[WIDTH][HEIGHT], struct Coord player_pos) {
    clear_screen();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == player_pos.x && y == player_pos.y) {
                printf("@");
            } else {
                printf("%c", map[x][y].symbol);
            }
        }
        printf("\n");
    }
}

int is_in_bounds(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

int can_move(struct Tile map[WIDTH][HEIGHT], int x, int y) {
    if (!is_in_bounds(x, y)) {
        return 0;
    }
    return map[x][y].walkable;
}

void move_player(struct Tile map[WIDTH][HEIGHT], struct Coord* player_pos, enum Direction direction) {
    int new_x = player_pos->x;
    int new_y = player_pos->y;
    switch (direction) {
        case NORTH:
            new_y--;
            break;
        case SOUTH:
            new_y++;
            break;
        case EAST:
            new_x++;
            break;
        case WEST:
            new_x--;
            break;
    }
    if (can_move(map, new_x, new_y)) {
        player_pos->x = new_x;
        player_pos->y = new_y;
    }
}

void print_text(char* text) {
    printf("\n%s\n", text);
    getchar();
}

void battle() {
    printf("\nYou encounter a troll!\n");
    printf("\nYou must engage in combat!\n");
    getchar();
}

struct Tile* get_tile_at(struct Tile map[WIDTH][HEIGHT], int x, int y) {
    if (is_in_bounds(x, y)) {
        return &map[x][y];
    } else {
        return NULL;
    }
}

void fill_map(struct Tile map[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            struct Tile tile;
            tile.symbol = '.';
            tile.walkable = 1;
            strcpy(tile.color, "white");
            map[x][y] = tile;
        }
    }
}

void populate_map(struct Tile map[WIDTH][HEIGHT]) {
    struct Tile* tile;
    tile = get_tile_at(map, 10, 10);
    tile->symbol = 'T';
    tile->walkable = 0;
    strcpy(tile->color, "red");

    tile = get_tile_at(map, 20, 15);
    tile->symbol = 'C';
    tile->walkable = 0;
    strcpy(tile->color, "yellow");
}

void main_loop(struct Tile map[WIDTH][HEIGHT], struct Coord player_pos) {
    while (1) {
        print_map(map, player_pos);
        printf("Use arrow keys to move, press Q to quit\n");
        int input = getchar();
        if (input == 'q') {
            break;
        }
        switch (input) {
            case 'w':
                move_player(map, &player_pos, NORTH);
                break;
            case 's':
                move_player(map, &player_pos, SOUTH);
                break;
            case 'a':
                move_player(map, &player_pos, WEST);
                break;
            case 'd':
                move_player(map, &player_pos, EAST);
                break;
        }
        struct Tile* current_tile = get_tile_at(map, player_pos.x, player_pos.y);
        if (!current_tile->walkable) {
            battle();
        }
    }
}

int main() {
    struct Tile map[WIDTH][HEIGHT];
    fill_map(map);
    populate_map(map);
    struct Coord player_pos;
    player_pos.x = 5;
    player_pos.y = 5;
    print_title();
    print_text("Welcome to the medieval space adventure game!");
    main_loop(map, player_pos);
    return 0;
}