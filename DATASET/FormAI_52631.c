//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
/* 
 * A game where the player moves a character on a grid to collect coins
 * and avoid enemies. 
 *
 * Controls:
 *  - Up arrow: move up
 *  - Down arrow: move down
 *  - Left arrow: move left
 *  - Right arrow: move right
 *
 * Rules:
 *  - Collect all the coins to win
 *  - Colliding with an enemy results in game over
 *  - Player can move through walls
 *
 * Enjoy the game!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 10
#define COLS 10
#define NUM_ENEMIES 3
#define NUM_COINS 5

// Enum for game pieces
enum piece { EMPTY, WALL, PLAYER, ENEMY, COIN };

// Global variables
enum piece grid[ROWS][COLS];  // game grid
int player_row, player_col;   // player position
int num_coins;                // number of coins remaining

// Function prototypes
void init_grid();
void print_grid();
void set_player();
void set_enemies();
void set_coins();
void move_player(int row_delta, int col_delta);
void move_enemies();
int rand_range(int min, int max);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize game grid
    init_grid();

    // Game loop
    int playing = 1;
    while (playing) {
        // Clear screen
        system("clear");

        // Print game grid
        print_grid();

        // Get user input
        char input;
        fflush(stdin);
        printf("Enter move (u/d/l/r): ");
        scanf("%c", &input);

        // Move player based on input
        switch (input) {
            case 'u': move_player(-1, 0); break;
            case 'd': move_player(1, 0); break;
            case 'l': move_player(0, -1); break;
            case 'r': move_player(0, 1); break;
        }

        // Move enemies
        move_enemies();

        // Check win/lose conditions
        if (num_coins == 0) {
            printf("Congratulations! You collected all the coins!\n");
            playing = 0;
        } else if (grid[player_row][player_col] == ENEMY) {
            printf("Game over! You collided with an enemy.\n");
            playing = 0;
        }
    }

    return 0;
}

void init_grid()
{
    // Fill grid with empty spaces
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = EMPTY;
        }
    }

    // Set walls
    for (int row = 0; row < ROWS; row++) {
        grid[row][0] = WALL;
        grid[row][COLS-1] = WALL;
    }
    for (int col = 0; col < COLS; col++) {
        grid[0][col] = WALL;
        grid[ROWS-1][col] = WALL;
    }

    // Set player, enemies, and coins
    set_player();
    set_enemies();
    set_coins();
    num_coins = NUM_COINS;
}

void print_grid()
{
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            switch (grid[row][col]) {
                case EMPTY: printf("_ "); break;
                case WALL: printf("# "); break;
                case PLAYER: printf("P "); break;
                case ENEMY: printf("E "); break;
                case COIN: printf("C "); break;
            }
        }
        printf("\n");
    }
}

void set_player()
{
    player_row = rand_range(1, ROWS-2);
    player_col = rand_range(1, COLS-2);
    grid[player_row][player_col] = PLAYER;
}

void set_enemies()
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        int row, col;
        do {
            row = rand_range(1, ROWS-2);
            col = rand_range(1, COLS-2);
        } while (grid[row][col] != EMPTY);
        grid[row][col] = ENEMY;
    }
}

void set_coins()
{
    for (int i = 0; i < NUM_COINS; i++) {
        int row, col;
        do {
            row = rand_range(1, ROWS-2);
            col = rand_range(1, COLS-2);
        } while (grid[row][col] != EMPTY);
        grid[row][col] = COIN;
    }
}

void move_player(int row_delta, int col_delta)
{
    // Move player if target space is valid
    if (grid[player_row+row_delta][player_col+col_delta] != WALL) {
        grid[player_row][player_col] = EMPTY;
        player_row += row_delta;
        player_col += col_delta;
        grid[player_row][player_col] = PLAYER;

        // Collect coin if present
        if (grid[player_row][player_col] == COIN) {
            num_coins--;
        }
    }
}

void move_enemies()
{
    for (int row = 1; row < ROWS-1; row++) {
        for (int col = 1; col < COLS-1; col++) {
            if (grid[row][col] == ENEMY) {
                // Move enemy randomly
                int row_delta, col_delta;
                do {
                    row_delta = rand_range(-1, 1);
                    col_delta = rand_range(-1, 1);
                } while (grid[row+row_delta][col+col_delta] == WALL);
                grid[row][col] = EMPTY;
                grid[row+row_delta][col+col_delta] = ENEMY;

                // Collide with player if present
                if (row+row_delta == player_row && col+col_delta == player_col) {
                    grid[player_row][player_col] = ENEMY;
                }
            }
        }
    }
}

int rand_range(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}