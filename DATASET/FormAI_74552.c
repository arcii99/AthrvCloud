//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 30

// Here is a struct to keep track of our game state
typedef struct {
    int x;  // x-coordinate of the player
    int y;  // y-coordinate of the player
    int score; // player score
    char map[ROWS][COLUMNS];  // game board
} game_t;

// This function clears the screen and prints the game board
void render_board(game_t *game) {
    system("clear");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", game->map[i][j]);
        }
        printf("\n");
    }
}

// This function initializes the game board with walls and dots
void init_board(game_t *game) {
    // Initialize everything to empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            game->map[i][j] = ' ';
        }
    }

    // Add some walls
    for (int i = 0; i < ROWS; i++) {
        game->map[i][0] = '#';
        game->map[i][COLUMNS - 1] = '#';
    }
    for (int i = 0; i < COLUMNS; i++) {
        game->map[0][i] = '#';
        game->map[ROWS - 1][i] = '#';
    }
    for (int i = 5; i < 15; i++) {
        game->map[7][i] = '#';
        game->map[13][i] = '#';
    }

    // Add some dots
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLUMNS - 1; j++) {
            if (game->map[i][j] != '#') {
                game->map[i][j] = '.';
            }
        }
    }

    // Add the player
    game->map[ROWS / 2][COLUMNS / 2] = 'P';
    game->x = COLUMNS / 2;
    game->y = ROWS / 2;
    game->score = 0;
}

// This function checks if there is a wall at the specified position
int is_wall(game_t *game, int x, int y) {
    return (game->map[y][x] == '#');
}

// This function checks if the player is touching a dot
int is_dot(game_t *game, int x, int y) {
    if (game->map[y][x] == '.') {
        game->score++;
        return 1;
    }
    return 0;
}

// This function moves the player in the specified direction
void move_player(game_t *game, char direction) {
    int new_x = game->x;
    int new_y = game->y;

    switch (direction) {
        case 'w':
            new_y--;
            break;
        case 'a':
            new_x--;
            break;
        case 's':
            new_y++;
            break;
        case 'd':
            new_x++;
            break;
    }

    // Check if new position is out of bounds
    if (new_x >= COLUMNS || new_x < 0 || new_y >= ROWS || new_y < 0) {
        return;
    }

    // Check if new position is a wall
    if (is_wall(game, new_x, new_y)) {
        return;
    }

    // Check if new position is a dot
    if (is_dot(game, new_x, new_y)) {
        game->map[new_y][new_x] = 'P';
        game->map[game->y][game->x] = '.';
        game->x = new_x;
        game->y = new_y;
        return;
    }

    // Otherwise, it's just an empty space
    game->map[new_y][new_x] = 'P';
    game->map[game->y][game->x] = ' ';
    game->x = new_x;
    game->y = new_y;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game state
    game_t game;
    init_board(&game);

    // Main game loop
    char input;
    while (1) {
        // Render the board
        render_board(&game);

        // Check for game over state
        if (game.score == ((ROWS - 2) * (COLUMNS - 2) - 28)) {
            printf("You win!\n");
            break;
        }

        // Get input from the user
        printf("Score: %d\n", game.score);
        printf("Enter a direction (w/a/s/d): ");
        scanf(" %c", &input);

        // Move the player
        move_player(&game, input);
    }

    return 0;
}