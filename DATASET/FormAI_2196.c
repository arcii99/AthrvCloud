//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 50
#define MAX_ENEMIES 5

// Function prototypes
void print_game_board(char game_board[][COLUMNS], int score, int lives);
void move_player(char game_board[][COLUMNS], int *player_row, int *player_column, int direction);
void move_enemies(char game_board[][COLUMNS], int enemy_rows[], int enemy_columns[], int num_enemies);
bool check_collision(int row, int column, int enemy_rows[], int enemy_columns[], int num_enemies);
void place_enemies(char game_board[][COLUMNS], int enemy_rows[], int enemy_columns[], int num_enemies);
int get_random_number(int min, int max);

int main() {
    char game_board[ROWS][COLUMNS] = {0}; // initialize to 0
    int score = 0;
    int lives = 3;
    int player_row = ROWS/2;
    int player_column = COLUMNS/2;
    int enemy_rows[MAX_ENEMIES];
    int enemy_columns[MAX_ENEMIES];
    int num_enemies = 1;
    int direction;

    srand(time(NULL)); // seed random number generator

    // Place initial player on game board
    game_board[player_row][player_column] = 'C';

    // Place initial enemies on game board
    place_enemies(game_board, enemy_rows, enemy_columns, num_enemies);

    // Start game loop
    while (true) {
        print_game_board(game_board, score, lives);
        printf("Enter a direction (1 = up, 2 = down, 3 = left, 4 = right): ");
        scanf("%d", &direction);

        move_player(game_board, &player_row, &player_column, direction);

        if (check_collision(player_row, player_column, enemy_rows, enemy_columns, num_enemies)) {
            // Collision with enemy!
            printf("You collided with an enemy! -1 life\n");
            lives--;
            if (lives == 0) {
                printf("Game over! Final score: %d\n", score);
                break; // End game loop
            }
            place_enemies(game_board, enemy_rows, enemy_columns, num_enemies);
        }
        else {
            // Move enemies
            move_enemies(game_board, enemy_rows, enemy_columns, num_enemies);
            if (get_random_number(1, 10) == 1) {
                // Add a new enemy
                num_enemies++;
                if (num_enemies > MAX_ENEMIES) {
                    num_enemies = MAX_ENEMIES;
                }
                place_enemies(game_board, enemy_rows, enemy_columns, num_enemies);
            }
            // Update score
            score++;
        }

    }

    return 0;
}

// Print the game board and player info
void print_game_board(char game_board[][COLUMNS], int score, int lives) {
    printf("Score: %d\nLives: %d\n\n", score, lives);
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            printf("%c", game_board[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}

// Move the player in the given direction
void move_player(char game_board[][COLUMNS], int *player_row, int *player_column, int direction) {
    game_board[*player_row][*player_column] = ' '; // Remove player from current position
    switch (direction) {
        case 1: // Up
            if (*player_row > 0) {
                (*player_row)--;
            }
            break;
        case 2: // Down
            if (*player_row < ROWS-1) {
                (*player_row)++;
            }
            break;
        case 3: // Left
            if (*player_column > 0) {
                (*player_column)--;
            }
            break;
        case 4: // Right
            if (*player_column < COLUMNS-1) {
                (*player_column)++;
            }
            break;
        default:
            break;
    }
    game_board[*player_row][*player_column] = 'C'; // Place player in new position
}

// Move the enemies randomly on the game board
void move_enemies(char game_board[][COLUMNS], int enemy_rows[], int enemy_columns[], int num_enemies) {
    for (int i = 0; i < num_enemies; i++) {
        game_board[enemy_rows[i]][enemy_columns[i]] = ' '; // Remove enemy from current position
        int direction = get_random_number(1, 4);
        switch (direction) {
            case 1: // Up
                if (enemy_rows[i] > 0) {
                    enemy_rows[i]--;
                }
                break;
            case 2: // Down
                if (enemy_rows[i] < ROWS-1) {
                    enemy_rows[i]++;
                }
                break;
            case 3: // Left
                if (enemy_columns[i] > 0) {
                    enemy_columns[i]--;
                }
                break;
            case 4: // Right
                if (enemy_columns[i] < COLUMNS-1) {
                    enemy_columns[i]++;
                }
                break;
            default:
                break;
        }
        game_board[enemy_rows[i]][enemy_columns[i]] = 'G'; // Place enemy in new position
    }
}

// Check if the player has collided with an enemy
bool check_collision(int row, int column, int enemy_rows[], int enemy_columns[], int num_enemies) {
    for (int i = 0; i < num_enemies; i++) {
        if (row == enemy_rows[i] && column == enemy_columns[i]) {
            return true; // Collision detected
        }
    }
    return false; // No collision detected
}

// Place the enemies on the game board
void place_enemies(char game_board[][COLUMNS], int enemy_rows[], int enemy_columns[], int num_enemies) {
    for (int i = 0; i < num_enemies; i++) {
        int row = get_random_number(0, ROWS-1);
        int column = get_random_number(0, COLUMNS-1);
        while (game_board[row][column] != ' ') {
            row = get_random_number(0, ROWS-1);
            column = get_random_number(0, COLUMNS-1);
        }
        enemy_rows[i] = row;
        enemy_columns[i] = column;
        game_board[row][column] = 'G';
    }
}

// Get a random number between min and max (inclusive)
int get_random_number(int min, int max) {
    return rand() % (max-min+1) + min;
}