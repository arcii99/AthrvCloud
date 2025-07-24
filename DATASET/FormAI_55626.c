//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 22
#define COLS 19
#define SPEED 200 // milliseconds
#define DOTS 240
#define GHOSTS 4
#define SCORE_FACTOR 10

enum direction {
    UP, DOWN, LEFT, RIGHT
};

struct point {
    int row;
    int col;
};

struct pacman {
    struct point pos;
    int score;
    bool lives;
    enum direction dir;
};

struct ghost {
    struct point pos;
    enum direction dir;
    bool vulnerable;
};

char level[ROWS][COLS];
struct pacman player;
struct ghost ghosts[GHOSTS];
int dots_left = DOTS;

void initialize_level(void);
void initialize_player(void);
void initialize_ghosts(void);
void print_status(void);
void move_player(void);
void move_ghosts(void);
bool is_valid_move(int row, int col);
void end_game(bool win);

int main(void) {
    srand(time(0));

    initialize_level();
    initialize_player();
    initialize_ghosts();

    while (player.lives && dots_left) {
        print_status();
        move_player();
        move_ghosts();
        // collision detection
        // game logic
        // update score and dots_left
        // check win/lose conditions
        // sleep(SPEED);
    }

    end_game(dots_left == 0);
    return 0;
}

void initialize_level(void) {
    // initialize level array with walls, dots, power pellets, and ghosts
}

void initialize_player(void) {
    // set player initial position and score
    // set player to face right direction
    // set player lives
}

void initialize_ghosts(void) {
    // set ghosts initial position and direction
    // set ghosts vulnerable to false
}

void print_status(void) {
    // print level array and player score and lives
}

void move_player(void) {
    // read player input
    // check if move is valid
    // update player position and direction
}

void move_ghosts(void) {
    // update ghosts position and direction
    // if ghost is vulnerable, check collision with player and update score and ghost state
}

bool is_valid_move(int row, int col) {
    // check if new position is inside level boundaries and not a wall
    // also check if new position is not a ghost if player is not in power-up state
    // return true if valid move, false otherwise
}

void end_game(bool win) {
    // print end game message and final score
}