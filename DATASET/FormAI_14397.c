//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 15
#define COLS 15
#define PACMAN_CHAR 'C'
#define GHOST_CHAR 'G'
#define PELLET_CHAR '.'
#define POWERUP_CHAR 'O'

// Structs
struct entity {
    char symbol;
    int row;
    int col;
};

// Function prototypes
void clear_screen();
void setup_game_board(char game_board[][COLS], struct entity *pacman, struct entity ghosts[], int *num_ghosts);
void print_game_board(char game_board[][COLS]);
void handle_input(char game_board[][COLS], struct entity *pacman, char input);
void update_game_board(char game_board[][COLS], struct entity *pacman, struct entity ghosts[], int num_ghosts);
void move_entity(char game_board[][COLS], struct entity *entity, int row_delta, int col_delta);
int is_collision(struct entity *entity1, struct entity *entity2);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Variables
    char game_board[ROWS][COLS];
    struct entity pacman;
    struct entity ghosts[4];
    int num_ghosts = 4;
    char input;

    // Setup game board and entities
    setup_game_board(game_board, &pacman, ghosts, &num_ghosts);

    // Game loop
    while (1) {
        // Clear screen and print game board
        clear_screen();
        print_game_board(game_board);

        // Get user input
        printf("Enter a direction (u/d/l/r): ");
        scanf(" %c", &input);

        // Handle user input
        handle_input(game_board, &pacman, input);

        // Update game board
        update_game_board(game_board, &pacman, ghosts, num_ghosts);
    }

    return 0;
}

// Functions

// Clears the terminal screen
void clear_screen() {
    system("clear");
}

// Sets up the game board and entities
void setup_game_board(char game_board[][COLS], struct entity *pacman, struct entity ghosts[], int *num_ghosts) {
    int i, j;

    // Initialize game board with pellets
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            game_board[i][j] = PELLET_CHAR;
        }
    }

    // Add powerup to center of game board
    game_board[ROWS/2][COLS/2] = POWERUP_CHAR;

    // Add entities to game board
    pacman->symbol = PACMAN_CHAR;
    pacman->row = ROWS - 2;
    pacman->col = COLS / 2;
    game_board[pacman->row][pacman->col] = pacman->symbol;

    for (i = 0; i < *num_ghosts; i++) {
        ghosts[i].symbol = GHOST_CHAR;
        ghosts[i].row = rand() % ROWS;
        ghosts[i].col = rand() % COLS;
        game_board[ghosts[i].row][ghosts[i].col] = ghosts[i].symbol;
    }
}

// Prints the game board
void print_game_board(char game_board[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }
}

// Handles user input
void handle_input(char game_board[][COLS], struct entity *pacman, char input) {
    int row_delta = 0, col_delta = 0;

    switch (input) {
        case 'u':
            row_delta = -1;
            break;
        case 'd':
            row_delta = 1;
            break;
        case 'l':
            col_delta = -1;
            break;
        case 'r':
            col_delta = 1;
            break;
        default:
            break;
    }

    move_entity(game_board, pacman, row_delta, col_delta);
}

// Updates the game board after each turn
void update_game_board(char game_board[][COLS], struct entity *pacman, struct entity ghosts[], int num_ghosts) {
    int i;

    // Move ghosts
    for (i = 0; i < num_ghosts; i++) {
        int row_delta = (rand() % 3) - 1; // Random number between -1 and 1
        int col_delta = (rand() % 3) - 1; // Random number between -1 and 1

        move_entity(game_board, &ghosts[i], row_delta, col_delta);
    }

    // Detect collisions
    for (i = 0; i < num_ghosts; i++) {
        if (is_collision(pacman, &ghosts[i])) {
            printf("Game over!\n");
            exit(0);
        }
    }
}

// Moves an entity on the game board
void move_entity(char game_board[][COLS], struct entity *entity, int row_delta, int col_delta) {
    int new_row = entity->row + row_delta;
    int new_col = entity->col + col_delta;

    // Make sure entity is within game board boundaries
    if ((new_row >= 0 && new_row < ROWS) && (new_col >= 0 && new_col < COLS)) {
        // Check for collision with pellets or powerup
        if (game_board[new_row][new_col] == PELLET_CHAR || game_board[new_row][new_col] == POWERUP_CHAR) {
            game_board[entity->row][entity->col] = PELLET_CHAR;
            entity->row = new_row;
            entity->col = new_col;
            entity->symbol = PACMAN_CHAR;
            game_board[entity->row][entity->col] = entity->symbol;
        // Check for collision with another entity
        } else if (game_board[new_row][new_col] == PACMAN_CHAR || game_board[new_row][new_col] == GHOST_CHAR) {
            // Do nothing
        // Move entity
        } else if (game_board[new_row][new_col] == PELLET_CHAR) {
            game_board[entity->row][entity->col] = PELLET_CHAR;
            entity->row = new_row;
            entity->col = new_col;
            game_board[entity->row][entity->col] = entity->symbol;
        }
    }
}

// Detects if two entities collide
int is_collision(struct entity *entity1, struct entity *entity2) {
    return (entity1->row == entity2->row && entity1->col == entity2->col);
}