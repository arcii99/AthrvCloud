//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAP_ROWS 20
#define MAP_COLS 30
#define MAX_SCORE 999999

typedef enum _DIRECTION {
    LEFT = 0,
    RIGHT,
    UP,
    DOWN
} DIRECTION;

typedef struct _COORD {
    int row;
    int col;
} COORD;

// Global variables
int high_score = 0;
int score = 0;
char map[MAP_ROWS][MAP_COLS];
bool is_game_over = false;

// Function prototypes
void print_map();
void init_game();
void init_map();
void generate_food();
COORD get_pacman_start();
COORD get_ghost_start(int index);
void move_pacman(DIRECTION dir);
void move_ghost(int index);
COORD get_random_direction(COORD current_pos);
bool is_collision(COORD pos1, COORD pos2);
void check_collision();
void game_over();

int main() {
    srand(time(NULL));

    init_game();

    while (!is_game_over) {
        print_map();

        char input = getchar();
        fflush(stdin);

        switch (input) {
            case 'a':
                move_pacman(LEFT);
                break;
            case 'd':
                move_pacman(RIGHT);
                break;
            case 'w':
                move_pacman(UP);
                break;
            case 's':
                move_pacman(DOWN);
                break;
            default:
                break;
        }

        for (int i = 0; i < 4; i++) {
            move_ghost(i);
        }

        check_collision();
    }

    game_over();

    return 0;
}

void print_map() {
    system("clear");

    printf("PACMAN\n\n");

    printf("High Score: %d\t\tCurrent Score: %d\n\n", high_score, score);

    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void init_game() {
    init_map();
    generate_food();
}

void init_map() {
    // Fill the map with dots and walls
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (i == 0 || i == MAP_ROWS - 1 || j == 0 || j == MAP_COLS - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    // Set the starting positions of pacman and the ghosts
    COORD pacman_start = get_pacman_start();
    map[pacman_start.row][pacman_start.col] = 'O';

    for (int i = 0; i < 4; i++) {
        COORD ghost_start = get_ghost_start(i);
        map[ghost_start.row][ghost_start.col] = 'A' + i;
    }
}

void generate_food() {
    int food_count = 0;

    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map[i][j] == '.') {
                if (rand() % 100 < 30) {
                    map[i][j] = '*';
                    food_count++;
                }
            }
        }
    }

    // If there is no food on the map, generate some more
    if (food_count == 0) {
        generate_food();
    }
}

COORD get_pacman_start() {
    COORD start;

    start.row = MAP_ROWS / 2;
    start.col = MAP_COLS / 2;

    return start;
}

COORD get_ghost_start(int index) {
    COORD start;

    if (index == 0 || index == 3) {
        start.row = 1;
        start.col = 1 + (index * 8);
    } else {
        start.row = MAP_ROWS - 2;
        start.col = 1 + ((index - 1) * 8);
    }

    return start;
}

void move_pacman(DIRECTION dir) {
    COORD current_pos = get_pacman_start();
    COORD new_pos;

    switch (dir) {
        case LEFT:
            new_pos.row = current_pos.row;
            new_pos.col = current_pos.col - 1;
            break;
        case RIGHT:
            new_pos.row = current_pos.row;
            new_pos.col = current_pos.col + 1;
            break;
        case UP:
            new_pos.row = current_pos.row - 1;
            new_pos.col = current_pos.col;
            break;
        case DOWN:
            new_pos.row = current_pos.row + 1;
            new_pos.col = current_pos.col;
            break;
        default:
            break;
    }

    if (map[new_pos.row][new_pos.col] == '.' || map[new_pos.row][new_pos.col] == '*') {
        // Update the score
        if (map[new_pos.row][new_pos.col] == '*') {
            score += 10;
            generate_food();
        }

        // Move pacman to the new position
        map[current_pos.row][current_pos.col] = '.';
        map[new_pos.row][new_pos.col] = 'O';
    }
}

void move_ghost(int index) {
    COORD current_pos;
    COORD new_pos;

    // Get the current position of the ghost
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map[i][j] == 'A' + index) {
                current_pos.row = i;
                current_pos.col = j;
            }
        }
    }

    // Get a random direction for the ghost to move in
    new_pos = get_random_direction(current_pos);

    // Move the ghost to the new position
    map[current_pos.row][current_pos.col] = '.';
    map[new_pos.row][new_pos.col] = 'A' + index;
}

COORD get_random_direction(COORD current_pos) {
    COORD new_pos;

    while (true) {
        int dir = rand() % 4;

        switch (dir) {
            case LEFT:
                new_pos.row = current_pos.row;
                new_pos.col = current_pos.col - 1;
                break;
            case RIGHT:
                new_pos.row = current_pos.row;
                new_pos.col = current_pos.col + 1;
                break;
            case UP:
                new_pos.row = current_pos.row - 1;
                new_pos.col = current_pos.col;
                break;
            case DOWN:
                new_pos.row = current_pos.row + 1;
                new_pos.col = current_pos.col;
                break;
            default:
                break;
        }

        // Check if the new position is valid
        if (map[new_pos.row][new_pos.col] != '#') {
            break;
        }
    }

    return new_pos;
}

bool is_collision(COORD pos1, COORD pos2) {
    return pos1.row == pos2.row && pos1.col == pos2.col;
}

void check_collision() {
    COORD pacman_pos = get_pacman_start();

    for (int i = 0; i < 4; i++) {
        COORD ghost_pos;

        for (int j = 0; j < MAP_ROWS; j++) {
            for (int k = 0; k < MAP_COLS; k++) {
                if (map[j][k] == 'A' + i) {
                    ghost_pos.row = j;
                    ghost_pos.col = k;
                }
            }
        }

        if (is_collision(pacman_pos, ghost_pos)) {
            is_game_over = true;
        }
    }

    if (score > high_score) {
        high_score = score;
    }

    if (score > MAX_SCORE) {
        is_game_over = true;
    }
}

void game_over() {
    printf("GAME OVER\n");

    if (score > high_score) {
        printf("New High Score: %d\n", score);
    } else {
        printf("Your Score: %d\n", score);
        printf("High Score: %d\n", high_score);
    }
}