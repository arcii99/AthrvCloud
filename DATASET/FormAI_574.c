//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_MOVES 25

void print_grid(char grid[][GRID_SIZE]);
void initialize_grid(char grid[][GRID_SIZE]);
int get_input(char prompt[], int upper_limit);
int check_win(char grid[][GRID_SIZE]);
void update_character(char grid[][GRID_SIZE], int *x, int *y, int dx, int dy);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int player_x = 0, player_y = 0, moves_remaining = MAX_MOVES;
    srand(time(0));
    initialize_grid(grid);
    print_grid(grid);

    while (moves_remaining > 0) {
        printf("\nMoves Remaining: %d\n", moves_remaining);
        int dx = get_input("Move right (1) or left (-1): ", 1);
        int dy = get_input("Move up (1) or down (-1): ", 1);
        update_character(grid, &player_x, &player_y, dx, dy);
        print_grid(grid);
        if (check_win(grid)) {
            printf("\nCongratulations! You have won!\n");
            break;
        }
        moves_remaining--;
    }

    if (!check_win(grid)) {
        printf("\nGame Over! You have lost!\n");
    }

    return 0;
}

void initialize_grid(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    int treasure_x = rand() % GRID_SIZE;
    int treasure_y = rand() % GRID_SIZE;
    grid[treasure_x][treasure_y] = 'T';
}

void print_grid(char grid[][GRID_SIZE]) {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int get_input(char prompt[], int upper_limit) {
    int input;
    do {
        printf("%s", prompt);
        scanf("%d", &input);
    } while (input < -upper_limit || input > upper_limit);
    return input;
}

int check_win(char grid[][GRID_SIZE]) {
    int treasure_x, treasure_y;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'T') {
                treasure_x = i;
                treasure_y = j;
                break;
            }
        }
    }
    return (treasure_x == 0 && treasure_y == 0);
}

void update_character(char grid[][GRID_SIZE], int *x, int *y, int dx, int dy) {
    int new_x = *x + dx;
    int new_y = *y + dy;
    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        return;
    }
    grid[*x][*y] = '.';
    grid[new_x][new_y] = 'P';
    *x = new_x;
    *y = new_y;
}