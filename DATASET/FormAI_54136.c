//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game parameters
#define ROWS 20
#define COLS 20
#define PACMAN 'C'
#define DOT '.'
#define GHOST 'G'
#define WALL '#'
#define MAX_DOTS 300
#define MAX_GHOSTS 4

// Define structures for game entities
struct Point {
    int x;
    int y;
};

struct PacMan {
    struct Point location;
    int dots_collected;
};

struct Ghost {
    struct Point location;
    int direction;
};

// Declare global variables for game entities and parameters
char grid[ROWS][COLS];
struct PacMan player;
struct Ghost ghosts[MAX_GHOSTS];
int num_ghosts;
int game_over;

// Function declarations
void initialize_game();
void print_grid();
void update_grid();
void move_player();
void move_ghosts();

int main() {
    initialize_game();
    print_grid();
    while (!game_over) {
        move_player();
        move_ghosts();
        update_grid();
        print_grid();
    }
    printf("Game Over! Final Score: %d\n", player.dots_collected);
    return 0;
}

void initialize_game() {
    // Initialize random number generator
    srand(time(NULL));
    // Set up grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || (i == ROWS / 2 && j != COLS / 2)) {
                grid[i][j] = WALL;
            } else {
                grid[i][j] = DOT;
            }
        }
    }
    // Add player character
    player.location.x = COLS / 2;
    player.location.y = ROWS / 2;
    grid[player.location.y][player.location.x] = PACMAN;
    player.dots_collected = 0;
    // Add ghosts
    num_ghosts = 0;
    while (num_ghosts < MAX_GHOSTS) {
        int x = rand() % COLS;
        int y = rand() % ROWS;
        if (grid[y][x] == DOT) {
            ghosts[num_ghosts].location.x = x;
            ghosts[num_ghosts].location.y = y;
            ghosts[num_ghosts].direction = rand() % 4;
            grid[y][x] = GHOST;
            num_ghosts++;
        }
    }
    // Set game over flag to false
    game_over = 0;
}

void print_grid() {
    system("clear");
    printf("SCORE: %d\n\n", player.dots_collected);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == PACMAN || grid[i][j] == GHOST) {
                grid[i][j] = DOT;
            }
        }
    }
    grid[player.location.y][player.location.x] = PACMAN;
    for (int i = 0; i < num_ghosts; i++) {
        grid[ghosts[i].location.y][ghosts[i].location.x] = GHOST;
    }
}

void move_player() {
    char input;
    printf("Use arrow keys to move Pac-Man.\n");
    input = getchar();
    while (input != '\n') {
        input = getchar();
    }
    switch (getchar()) {
        case 'A':
        case 'a':
            if (grid[player.location.y][player.location.x - 1] != WALL) {
                player.location.x--;
                if (grid[player.location.y][player.location.x] == DOT) {
                    player.dots_collected++;
                }
            }
            break;
        case 'D':
        case 'd':
            if (grid[player.location.y][player.location.x + 1] != WALL) {
                player.location.x++;
                if (grid[player.location.y][player.location.x] == DOT) {
                    player.dots_collected++;
                }
            }
            break;
        case 'W':
        case 'w':
            if (grid[player.location.y - 1][player.location.x] != WALL) {
                player.location.y--;
                if (grid[player.location.y][player.location.x] == DOT) {
                    player.dots_collected++;
                }
            }
            break;
        case 'S':
        case 's':
            if (grid[player.location.y + 1][player.location.x] != WALL) {
                player.location.y++;
                if (grid[player.location.y][player.location.x] == DOT) {
                    player.dots_collected++;
                }
            }
            break;
        default:
            break;
    }
    if (player.dots_collected == MAX_DOTS) {
        game_over = 1;
    }
}

void move_ghosts() {
    for (int i = 0; i < num_ghosts; i++) {
        int x = ghosts[i].location.x;
        int y = ghosts[i].location.y;
        switch (ghosts[i].direction) {
            case 0:
                if (grid[y - 1][x] != WALL) {
                    ghosts[i].location.y--;
                }
                break;
            case 1:
                if (grid[y][x + 1] != WALL) {
                    ghosts[i].location.x++;
                }
                break;
            case 2:
                if (grid[y + 1][x] != WALL) {
                    ghosts[i].location.y++;
                }
                break;
            case 3:
                if (grid[y][x - 1] != WALL) {
                    ghosts[i].location.x--;
                }
                break;
            default:
                break;
        }
        if (ghosts[i].location.x == player.location.x && ghosts[i].location.y == player.location.y) {
            game_over = 1;
        }
        ghosts[i].direction = rand() % 4;
    }
}