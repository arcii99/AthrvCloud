//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

// function to print grid
void print_grid(char grid[ROWS][COLS]) {
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("%d", i % 10);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// function to move player's spaceship
int move_spaceship(char grid[ROWS][COLS], int *spaceship_pos) {
    char move;
    int curr_pos = *spaceship_pos;

    printf("Enter move (a: left, s: stay, d: right): ");
    scanf(" %c", &move);

    // move spaceship left
    if (move == 'a' && curr_pos > 0) {
        grid[ROWS - 1][curr_pos] = ' ';
        grid[ROWS - 1][curr_pos - 1] = 'S';
        *spaceship_pos = curr_pos - 1;
    }
    // move spaceship right
    else if (move == 'd' && curr_pos < COLS - 1) {
        grid[ROWS - 1][curr_pos] = ' ';
        grid[ROWS - 1][curr_pos + 1] = 'S';
        *spaceship_pos = curr_pos + 1;
    }

    return 0;
}

// function to move aliens
int move_aliens(char grid[ROWS][COLS], int aliens[ROWS][COLS]) {
    int move_or_shoot;
    int count_alive_aliens = 0;
    int min_alive_row = ROWS;
    int max_alive_row = 0;
    int min_alive_col = COLS;
    int max_alive_col = 0;

    // count number of alive aliens and get the range of their positions
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (aliens[i][j] == 1) {
                count_alive_aliens++;
                if (i < min_alive_row) {
                    min_alive_row = i;
                }
                if (i > max_alive_row) {
                    max_alive_row = i;
                }
                if (j < min_alive_col) {
                    min_alive_col = j;
                }
                if (j > max_alive_col) {
                    max_alive_col = j;
                }
            }
        }
    }
    // If no aliens are alive, return 1 (game won)
    if (count_alive_aliens == 0) {
        return 1;
    }

    move_or_shoot = rand() % 2; // randomly decide if aliens should move or shoot

    // if aliens should move
    if (move_or_shoot == 0) {
        // move aliens down
        if (max_alive_row < ROWS - 1) {
            for (int i = ROWS - 1; i >= min_alive_row; i--) {
                for (int j = min_alive_col; j <= max_alive_col; j++) {
                    if (aliens[i][j] == 1) {
                        aliens[i][j] = 0;
                        aliens[i + 1][j] = 1;
                        grid[i][j] = ' ';
                        grid[i + 1][j] = 'A';
                    }
                }
            }
        }
        // aliens have reached the bottom: game over
        else {
            return -1;
        }
    }
    // if aliens should shoot
    else {
        // find bottom-most alien in each column and shoot
        for (int j = min_alive_col; j <= max_alive_col; j++) {
            for (int i = ROWS - 1; i >= 0; i--) {
                if (aliens[i][j] == 1) {
                    grid[i][j] = ' ';
                    aliens[i][j] = 0;
                    grid[i + 1][j] = 'A';
                    aliens[i + 1][j] = 1;
                    break;
                }
            }
        }
    }

    return 0;
}

int main() {
    char grid[ROWS][COLS];
    int aliens[ROWS][COLS] = {0};
    int spaceship_pos = COLS / 2;
    int player_score = 0;
    int game_status = 0;
    int move_count = 0;

    srand(time(0)); // seed random number generator

    // initialize grid and aliens
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
            if (i < 3 && (i + j) % 2 == 0) {
                grid[i][j] = 'A';
                aliens[i][j] = 1;
            }
        }
    }
    grid[ROWS - 1][spaceship_pos] = 'S';

    // game loop
    while (game_status == 0) {
        print_grid(grid);
        move_spaceship(grid, &spaceship_pos);
        game_status = move_aliens(grid, aliens);
        if (game_status == 1) {
            printf("Congratulations! You won!\n");
            return 0;
        }
        else if (game_status == -1) {
            printf("Game over. You lose.\n");
            return 0;
        }
        move_count++;
        if (move_count % 5 == 0) {
            player_score++;
        }
    }

    return 0;
}