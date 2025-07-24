//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: visionary
// C Space Invaders Game Clone

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Define constants
#define ROWS 20
#define COLS 40
#define PLAYER_CHAR 'A'
#define ENEMY_CHAR 'X'

// Define global variables
char field[ROWS][COLS];
int player_pos;
bool game_over;

// Initialize terminal
void init_term() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

// Cleanup terminal
void cleanup_term() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    printf("\033[2J");
    printf("\033[%d;%dHGame over!\n", ROWS+1, 1);
}

// Render field
void render_field() {
    printf("\033[2J");
    printf("\033[%d;%dH", 1, 1);
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            printf("%c", field[y][x]);
        }
        printf("\n");
    }
    printf("\033[%d;%dHPlayer level: %d\n", ROWS+1, 1, player_pos);
}

// Move player
void move_player(char direction) {
    int new_pos = player_pos + (direction == 'a' ? -1 : 1);
    if (new_pos < 0 || new_pos >= COLS) return;
    field[ROWS-1][player_pos] = ' ';
    field[ROWS-1][new_pos] = PLAYER_CHAR;
    player_pos = new_pos;
}

// Spawn enemy
void spawn_enemy() {
    for (int i = 0; i < ROWS; i++) {
        if (field[i][0] == ' ') {
            field[i][0] = ENEMY_CHAR;
            return;
        }
    }
    game_over = true;
}

// Move enemies
void move_enemies() {
    for (int y = ROWS-2; y >= 0; y--) {
        for (int x = 0; x < COLS; x++) {
            if (field[y][x] == ENEMY_CHAR) {
                if (y == ROWS-2 || field[y+1][x] != ' ') game_over = true;
                field[y][x] = ' ';
                field[y+1][x] = ENEMY_CHAR;
            }
        }
    }
}

// Handle user input
void handle_input(char input) {
    if (input == 'q') game_over = true;
    else if (input == 'a' || input == 'd') move_player(input);
}

// Main function
int main() {
    init_term();

    // Initialize field
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            field[y][x] = ' ';
        }
    }
    player_pos = COLS / 2;
    field[ROWS-1][player_pos] = PLAYER_CHAR;

    // Main loop
    while (!game_over) {
        spawn_enemy();
        render_field();
        usleep(500000);
        move_enemies();
        render_field();

        // Handle input
        char input = getchar();
        if (input != EOF) handle_input(input);
    }

    cleanup_term();
    return 0;
}