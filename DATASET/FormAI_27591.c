//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10 // Size of the board
#define SLEEP_TIME 2 // Time to display the cards

// Structure to hold the state of each cell in the board
typedef struct {
    int value;
    int is_open;
} Cell;

// Structure to hold the state of the game
typedef struct {
    Cell board[SIZE][SIZE];
    int score;
    int num_open;
    pthread_mutex_t mutex;
} Game;

// Function to initialize the game
void init_game(Game *game) {
    game->score = 0;
    game->num_open = 0;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j].value = rand() % 10; // Assign random values to cells
            game->board[i][j].is_open = 0; // Close all cells
        }
    }
}

// Function to display a cell
void display_cell(Cell cell) {
    if (cell.is_open) {
        printf("%d ", cell.value);
    } else {
        printf("# ");
    }
}

// Function to display the board
void display_board(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display_cell(game->board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", game->score);
}

// Function to open a cell
void open_cell(Game *game, int i, int j) {
    if (!game->board[i][j].is_open) {
        game->board[i][j].is_open = 1;
        game->num_open++;
    }
}

// Function to close a cell
void close_cell(Game *game, int i, int j) {
    if (game->board[i][j].is_open) {
        game->board[i][j].is_open = 0;
        game->num_open--;
    }
}

// Function to update the score
void update_score(Game *game, int value) {
    game->score += value;
}

// Thread function to play the game
void* play(void* arg) {
    Game *game = (Game*) arg;
    while (game->num_open < SIZE * SIZE) { // Check if all cells are open
        int i1, j1, i2, j2;
        do {
            i1 = rand() % SIZE;
            j1 = rand() % SIZE;
        } while (game->board[i1][j1].is_open); // Choose a closed cell
        open_cell(game, i1, j1);
        display_board(game);
        sleep(SLEEP_TIME);
        do {
            i2 = rand() % SIZE;
            j2 = rand() % SIZE;
        } while (game->board[i2][j2].is_open); // Choose another closed cell
        open_cell(game, i2, j2);
        display_board(game);
        if (game->board[i1][j1].value == game->board[i2][j2].value) { // If same value, update score
            update_score(game, game->board[i1][j1].value);
        } else { // If different, close both cells
            close_cell(game, i1, j1);
            close_cell(game, i2, j2);
        }
        display_board(game);
        sleep(SLEEP_TIME);
    }
    printf("Game Over! Final Score: %d\n", game->score);
    return NULL;
}

// Main function to start the game
int main() {
    Game game;
    init_game(&game);
    pthread_t thread;
    pthread_create(&thread, NULL, play, &game);
    pthread_join(thread, NULL);
    return 0;
}