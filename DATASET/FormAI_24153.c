//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Set the size of the game board
#define ROWS 10
#define COLS 10

// Define game symbols
#define PLAYER_SYMBOL 'P'
#define TREASURE_SYMBOL '$'
#define OBSTACLE_SYMBOL 'X'

// Define colors for console output
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

// Define game structures
struct player {
    int x;
    int y;
};

struct treasure {
    int x;
    int y;
};

struct obstacle {
    int x;
    int y;
};

// Function to print game board
void print_board(char board[ROWS][COLS]) {
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == PLAYER_SYMBOL) {
                printf("%s%c%s", GREEN, PLAYER_SYMBOL, RESET);
            } else if (board[i][j] == TREASURE_SYMBOL) {
                printf("%s%c%s", YELLOW, TREASURE_SYMBOL, RESET);
            } else if (board[i][j] == OBSTACLE_SYMBOL) {
                printf("%s%c%s", RED, OBSTACLE_SYMBOL, RESET);
            } else {
                printf("%s%c%s", BLUE, '.', RESET);
            }
        }
        printf("\n");
    }

    printf("\n");
}

// Function to check if a cell is occupied by an obstacle
int is_obstacle(char board[ROWS][COLS], int x, int y) {
    return (board[x][y] == OBSTACLE_SYMBOL);
}

// Function to check if a cell is occupied by the player or treasure
int is_occupied(char board[ROWS][COLS], int x, int y) {
    return (board[x][y] == PLAYER_SYMBOL || board[x][y] == TREASURE_SYMBOL);
}

// Function to place an obstacle randomly on the game board
void place_obstacle(char board[ROWS][COLS], struct obstacle *obstacle) {
    int x, y;

    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (is_occupied(board, x, y));

    obstacle->x = x;
    obstacle->y = y;

    board[x][y] = OBSTACLE_SYMBOL;
}

// Function to place the player randomly on the game board
void place_player(char board[ROWS][COLS], struct player *player) {
    int x, y;

    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (is_occupied(board, x, y));

    player->x = x;
    player->y = y;

    board[x][y] = PLAYER_SYMBOL;
}

// Function to place the treasure randomly on the game board
void place_treasure(char board[ROWS][COLS], struct treasure *treasure) {
    int x, y;

    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (is_occupied(board, x, y));

    treasure->x = x;
    treasure->y = y;

    board[x][y] = TREASURE_SYMBOL;
}

// Function to move the player on the game board
void move_player(char board[ROWS][COLS], struct player *player, int x_offset, int y_offset) {
    int new_x = player->x + x_offset;
    int new_y = player->y + y_offset;

    if (new_x < 0 || new_x >= ROWS || new_y < 0 || new_y >= COLS) {
        return;
    }

    if (is_obstacle(board, new_x, new_y)) {
        return;
    }

    board[player->x][player->y] = '.';
    player->x = new_x;
    player->y = new_y;
    board[new_x][new_y] = PLAYER_SYMBOL;
}

int main() {
    char board[ROWS][COLS];
    struct player player;
    struct treasure treasure;
    struct obstacle obstacle;
    int moves = 0;

    srand(time(NULL));

    // Initialize the game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }

    // Place the obstacle, player and treasure on the game board
    place_obstacle(board, &obstacle);
    place_player(board, &player);
    place_treasure(board, &treasure);

    // Print the game board
    print_board(board);

    // Game loop
    while (1) {
        int x_offset, y_offset;

        // Get user input
        printf("Enter your moves (up, down, left, right): ");
        scanf("%d %d", &x_offset, &y_offset);

        // Move the player
        move_player(board, &player, x_offset, y_offset);
        moves++;

        // Check if the player has reached the treasure
        if (player.x == treasure.x && player.y == treasure.y) {
            printf("You found the treasure in %d moves!\n", moves);
            break;
        }

        // Print the game board
        print_board(board);
    }

    return 0;
}