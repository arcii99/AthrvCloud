//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20
#define DELAY 500000

int player_row = 0, player_col = 0;
int ghost_row = 0, ghost_col = 0;
int exit_row = ROWS - 1, exit_col = COLUMNS - 1;

char grid[ROWS][COLUMNS];

void populate_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }
    grid[player_row][player_col] = 'P';
    grid[ghost_row][ghost_col] = 'G';
    grid[exit_row][exit_col] = 'E';
}

void print_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void move_player(char direction) {
    switch (direction) {
        case 'up':
            if (player_row > 0) {
                player_row--;
            }
            break;
        case 'left':
            if (player_col > 0) {
                player_col--;
            }
            break;
        case 'down':
            if (player_row < ROWS - 1) {
                player_row++;
            }
            break;
        case 'right':
            if (player_col < COLUMNS - 1) {
                player_col++;
            }
            break;
    }
}

void move_ghost() {
    int direction = rand() % 4;
    switch (direction) {
        case 0: // up
            if (ghost_row > 0) {
                ghost_row--;
            }
            break;
        case 1: // left
            if (ghost_col > 0) {
                ghost_col--;
            }
            break;
        case 2: // down
            if (ghost_row < ROWS - 1) {
                ghost_row++;
            }
            break;
        case 3: // right
            if (ghost_col < COLUMNS - 1) {
                ghost_col++;
            }
            break;
    }
}

bool game_over() {
    if (player_row == ghost_row && player_col == ghost_col) {
        return true;
    }
    if (player_row == exit_row && player_col == exit_col) {
        return true;
    }
    return false;
}

int main() {

    srand(time(0));

    while (!game_over()) {

        system("clear");

        populate_grid();

        print_grid();

        printf("Use arrow keys to move the player\n");

        char input;
        scanf(" %c", &input);

        move_player(input);

        move_ghost();

        usleep(DELAY);
    }

    system("clear");

    populate_grid();
    print_grid();

    if (player_row == exit_row && player_col == exit_col) {
        printf("You made it out alive!\n");
    } else {
        printf("You were caught by the ghost!\n");
    }

    return 0;
}