//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 30

// Constants for direction
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Constants for map entities
#define WALL '#'
#define DOT '.'
#define PACMAN 'C'
#define GHOST 'G'
#define EMPTY ' '

// Struct for the game state
typedef struct {
    char map[ROWS][COLS];
    int pacman_row;
    int pacman_col;
    int ghost_row;
    int ghost_col;
    bool is_game_over;
    int score;
} GameState;

// Function to initialize the game state
void init_game(GameState* game) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the map to all empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game->map[i][j] = EMPTY;
        }
    }
    
    // Place walls around the perimeter of the map
    for (int i = 0; i < ROWS; i++) {
        game->map[i][0] = WALL;
        game->map[i][COLS-1] = WALL;
    }
    for (int j = 0; j < COLS; j++) {
        game->map[0][j] = WALL;
        game->map[ROWS-1][j] = WALL;
    }
    
    // Place dots randomly on the map
    int num_dots = ROWS * COLS / 5;
    for (int i = 0; i < num_dots; i++) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLS-2) + 1;
        if (game->map[row][col] == EMPTY) {
            game->map[row][col] = DOT;
        }
    }
    
    // Place Pac-Man in the center of the map
    game->pacman_row = ROWS / 2;
    game->pacman_col = COLS / 2;
    game->map[game->pacman_row][game->pacman_col] = PACMAN;
    
    // Place the ghost randomly on the map
    while (true) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLS-2) + 1;
        if (game->map[row][col] == EMPTY) {
            game->ghost_row = row;
            game->ghost_col = col;
            game->map[game->ghost_row][game->ghost_col] = GHOST;
            break;
        }
    }
    
    // Initialize game state variables
    game->is_game_over = false;
    game->score = 0;
}

// Function to print the map and game info
void pprint(GameState* game) {
    // Print the map
    printf("Score: %d\n", game->score);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", game->map[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game state based on user input
void update(GameState* game, int direction) {
    // Update Pac-Man's position
    int new_row = game->pacman_row;
    int new_col = game->pacman_col;
    if (direction == UP) {
        new_row--;
    } else if (direction == DOWN) {
        new_row++;
    } else if (direction == LEFT) {
        new_col--;
    } else if (direction == RIGHT) {
        new_col++;
    }
    
    // Check for collisions with walls or the ghost
    if (game->map[new_row][new_col] == WALL) {
        printf("Ouch! You hit a wall.\n");
    } else if (new_row == game->ghost_row && new_col == game->ghost_col) {
        printf("Oh no! You got caught by the ghost.\n");
        game->is_game_over = true;
    } else {
        // Move Pac-Man and update the score
        if (game->map[new_row][new_col] == DOT) {
            game->score += 10;
        }
        game->map[game->pacman_row][game->pacman_col] = EMPTY;
        game->pacman_row = new_row;
        game->pacman_col = new_col;
        game->map[game->pacman_row][game->pacman_col] = PACMAN;
        
        // Move the ghost randomly
        int ghost_direction = rand() % 4;
        int ghost_new_row = game->ghost_row;
        int ghost_new_col = game->ghost_col;
        if (ghost_direction == UP) {
            ghost_new_row--;
        } else if (ghost_direction == DOWN) {
            ghost_new_row++;
        } else if (ghost_direction == LEFT) {
            ghost_new_col--;
        } else if (ghost_direction == RIGHT) {
            ghost_new_col++;
        }
        if (game->map[ghost_new_row][ghost_new_col] != WALL && !(ghost_new_row == game->pacman_row && ghost_new_col == game->pacman_col)) {
            game->map[game->ghost_row][game->ghost_col] = EMPTY;
            game->ghost_row = ghost_new_row;
            game->ghost_col = ghost_new_col;
            game->map[game->ghost_row][game->ghost_col] = GHOST;
        }
        
        // Check for victory condition
        bool has_dots = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (game->map[i][j] == DOT) {
                    has_dots = true;
                    break;
                }
            }
            if (has_dots) {
                break;
            }
        }
        if (!has_dots) {
            printf("Congratulations, you won!\n");
            game->is_game_over = true;
        }
    }
}

int main() {
    // Initialize the game state
    GameState game;
    init_game(&game);
    
    // Game loop
    while (!game.is_game_over) {
        // Print the game state
        system("clear"); // Clear the console
        pprint(&game);
        
        // Get user input
        printf("Use WASD or arrow keys to move Pac-Man.\n");
        int direction;
        char input = getchar();
        if (input == 'w' || input == 'W' || input == 38) {
            direction = UP;
        } else if (input == 's' || input == 'S' || input == 40) {
            direction = DOWN;
        } else if (input == 'a' || input == 'A' || input == 37) {
            direction = LEFT;
        } else if (input == 'd' || input == 'D' || input == 39) {
            direction = RIGHT;
        } else {
            continue;
        }
        
        // Update the game state
        update(&game, direction);
        
        // Wait for user to press enter before continuing
        printf("Press enter to continue.\n");
        getchar();
    }
    
    return 0;
}