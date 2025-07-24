//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define DOT_SCORE 10
#define POWERUP_SCORE 50

/* Define direction constants */
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

/* Define Pacman and ghosts structs */
struct Entity {
    int x, y;
    enum Direction direction;
};

struct Entity pacman;
struct Entity ghosts[4];

/* Define game board */
char board[BOARD_HEIGHT][BOARD_WIDTH] = {
    "###################",
    "#.................#",
    "#.###.#.###.#.###.#",
    "#o###.#.###.#.###o#",
    "#.###.#.###.#.###.#",
    "#.................#",
    "#.###.#.#.#.#.#.###",
    "#.###.#.#.#.#.#.###",
    "#......#...#......#",
    "####.#.#.#.#.#.#.##",
    "  #.#.#.#.#.#.#.#  ",
    "####.#.#.#.#.#.#.##",
    "#.................#",
    "#.###.#.#####.#.###",
    "#o..#.#...#...#.#.#",
    "###.#.#.#.#.#.#.#.#",
    "#.....#...#...#...#",
    "###################"
};

/* Declare functions */
void print_board();
void update_entity(struct Entity *entity);
void move_entity(struct Entity *entity, int dx, int dy);
bool can_entity_move(struct Entity *entity, int dx, int dy);
void update_pacman();
void update_ghosts();
void move_ghost(struct Entity *ghost);

int main() {
    // Initialize Pacman 
    pacman.x = 1;
    pacman.y = 1;
    pacman.direction = RIGHT;

    // Initialize Ghosts
    ghosts[0].x = 8;
    ghosts[0].y = 10;
    ghosts[1].x = 9;
    ghosts[1].y = 10;
    ghosts[2].x = 10;
    ghosts[2].y = 10;
    ghosts[3].x = 11;
    ghosts[3].y = 10;

    // Game loop
    while (true) {
        // Clear console
        system("cls");

        // Update entities
        update_pacman();
        update_ghosts();

        // Print board
        print_board();
    }

    return 0;
}

void print_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == pacman.y && j == pacman.x) {
                printf("C");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

void update_entity(struct Entity *entity) {
    int dx = 0, dy = 0;

    // Move entity according to its current direction
    switch(entity->direction) {
        case UP:
            dy = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
        case DOWN:
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            break;
    }

    // Check if entity can move to its new position
    if (can_entity_move(entity, dx, dy)) {
        move_entity(entity, dx, dy);
    } else {
        // Check if entity can move in its current direction
        if (!can_entity_move(entity, dx, dy)) {
            entity->direction = (entity->direction + 1) % 4;
        }
    }
}

void move_entity(struct Entity *entity, int dx, int dy) {
    // Remove entity from its current position
    board[entity->y][entity->x] = ' ';

    // Update entity position
    entity->x += dx;
    entity->y += dy;

    // Check if entity has eaten a dot
    if (board[entity->y][entity->x] == '.') {
        board[entity->y][entity->x] = ' ';
        // Increase score
        printf("Score: %d\n", DOT_SCORE);
    }
    // Check if entity has eaten a powerup
    if (board[entity->y][entity->x] == 'o') {
        board[entity->y][entity->x] = ' ';
        // Increase score
        printf("Score: %d\n", POWERUP_SCORE);
    }

    // Add entity to its new position
    board[entity->y][entity->x] = 'C';
}

bool can_entity_move(struct Entity *entity, int dx, int dy) {
    // Calculate entity's new position
    int new_x = entity->x + dx;
    int new_y = entity->y + dy;

    // Check if new position is within board bounds
    if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
        return false;
    }

    // Check if new position is not a wall
    if (board[new_y][new_x] == '#') {
        return false;
    }

    // Entity can move to its new position
    return true;
}

void update_pacman() {
    update_entity(&pacman);
}

void update_ghosts() {
    for (int i = 0; i < 4; i++) {
        move_ghost(&ghosts[i]);
    }
}

void move_ghost(struct Entity *ghost) {
    // Move ghost towards Pacman
    int dx = 0, dy = 0;
    if (ghost->x < pacman.x) {
        dx = 1;
    } else if (ghost->x > pacman.x) {
        dx = -1;
    }
    if (ghost->y < pacman.y) {
        dy = 1;
    } else if (ghost->y > pacman.y) {
        dy = -1;
    }

    // Check if ghost can move to its new position
    if (can_entity_move(ghost, dx, dy)) {
        move_entity(ghost, dx, dy);
    } else {
        // Check if ghost can move in any direction
        if (!can_entity_move(ghost, 1, 0) && !can_entity_move(ghost, -1, 0) && !can_entity_move(ghost, 0, 1) && !can_entity_move(ghost, 0, -1)) {
            return;
        }
        // Choose random direction
        int direction = rand() % 4;
        while (!can_entity_move(ghost, dx, dy)) {
            direction = (direction + 1) % 4;
            switch(direction) {
                case UP:
                    dx = 0; dy = -1;
                    break;
                case RIGHT:
                    dx = 1; dy = 0;
                    break;
                case DOWN:
                    dx = 0; dy = 1;
                    break;
                case LEFT:
                    dx = -1; dy = 0;
                    break;
            }
        }
        // Move ghost in selected direction
        move_entity(ghost, dx, dy);
    }
}