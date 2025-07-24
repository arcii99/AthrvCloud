//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game parameters
#define ROWS 10
#define COLS 20
#define MAX_FRUITS 5
#define FRUIT_TYPES 4
#define WIN_SCORE 100

// Define a struct for the game state
struct GameState {
    char board[ROWS][COLS];
    int score;
    int fruits_collected[FRUIT_TYPES];
};

// Function to initialize the game board
void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = '#';
            }
        }
    }
}

// Function to print the game board
void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly generate a fruit on the board
void generate_fruit(struct GameState *gamestate) {
    int row, col;
    char fruit;
    do {
        row = rand() % (ROWS-2) + 1;
        col = rand() % (COLS-2) + 1;
    } while (gamestate->board[row][col] != ' ');
    fruit = 'A' + rand() % FRUIT_TYPES;
    gamestate->board[row][col] = fruit;
}

// Function to update the game state based on player input
void update_gamestate(struct GameState *gamestate, char input) {
    int row, col, i, j;
    int fruit_collected = 0;
    char fruit;
    switch (input) {
        case 'w': // Move up
            for (col = 1; col < COLS-1; col++) {
                for (row = 1; row < ROWS-1; row++) {
                    if (gamestate->board[row][col] != ' ') {
                        if (gamestate->board[row-1][col] == ' ') {
                            gamestate->board[row-1][col] = gamestate->board[row][col];
                            gamestate->board[row][col] = ' ';
                        } else if (gamestate->board[row][col] == gamestate->board[row-1][col]) {
                            gamestate->board[row-1][col]++;
                            gamestate->score += gamestate->board[row-1][col]-'A'+1;
                            gamestate->fruits_collected[gamestate->board[row-1][col]-'A']++;
                            gamestate->board[row][col] = ' ';
                            fruit_collected = 1;
                        }
                    }
                }
            }
            break;
        case 'a': // Move left
            for (row = 1; row < ROWS-1; row++) {
                for (col = 1; col < COLS-1; col++) {
                    if (gamestate->board[row][col] != ' ') {
                        if (gamestate->board[row][col-1] == ' ') {
                            gamestate->board[row][col-1] = gamestate->board[row][col];
                            gamestate->board[row][col] = ' ';
                        } else if (gamestate->board[row][col] == gamestate->board[row][col-1]) {
                            gamestate->board[row][col-1]++;
                            gamestate->score += gamestate->board[row][col-1]-'A'+1;
                            gamestate->fruits_collected[gamestate->board[row][col-1]-'A']++;
                            gamestate->board[row][col] = ' ';
                            fruit_collected = 1;
                        }
                    }
                }
            }
            break;
        case 's': // Move down
            for (col = 1; col < COLS-1; col++) {
                for (row = ROWS-2; row > 0; row--) {
                    if (gamestate->board[row][col] != ' ') {
                        if (gamestate->board[row+1][col] == ' ') {
                            gamestate->board[row+1][col] = gamestate->board[row][col];
                            gamestate->board[row][col] = ' ';
                        } else if (gamestate->board[row][col] == gamestate->board[row+1][col]) {
                            gamestate->board[row+1][col]++;
                            gamestate->score += gamestate->board[row+1][col]-'A'+1;
                            gamestate->fruits_collected[gamestate->board[row+1][col]-'A']++;
                            gamestate->board[row][col] = ' ';
                            fruit_collected = 1;
                        }
                    }
                }
            }
            break;
        case 'd': // Move right
            for (row = 1; row < ROWS-1; row++) {
                for (col = COLS-2; col > 0; col--) {
                    if (gamestate->board[row][col] != ' ') {
                        if (gamestate->board[row][col+1] == ' ') {
                            gamestate->board[row][col+1] = gamestate->board[row][col];
                            gamestate->board[row][col] = ' ';
                        } else if (gamestate->board[row][col] == gamestate->board[row][col+1]) {
                            gamestate->board[row][col+1]++;
                            gamestate->score += gamestate->board[row][col+1]-'A'+1;
                            gamestate->fruits_collected[gamestate->board[row][col+1]-'A']++;
                            gamestate->board[row][col] = ' ';
                            fruit_collected = 1;
                        }
                    }
                }
            }
            break;
    }
    if (fruit_collected) {
        generate_fruit(gamestate);
    }
}

// Function to check if the game is over
int is_gameover(struct GameState *gamestate) {
    int i, j, empty_cells = 0;
    for (i = 1; i < ROWS-1; i++) {
        for (j = 1; j < COLS-1; j++) {
            if (gamestate->board[i][j] == ' ') {
                empty_cells++;
            }
        }
    }
    if (empty_cells < MAX_FRUITS) {
        return 1;
    } else if (gamestate->score >= WIN_SCORE) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to run the game
int main() {
    char input;
    struct GameState gamestate;
    gamestate.score = 0;
    int i;
    for (i = 0; i < FRUIT_TYPES; i++) {
        gamestate.fruits_collected[i] = 0;
    }
    srand(time(0));
    init_board(gamestate.board);
    generate_fruit(&gamestate);
    while (!is_gameover(&gamestate)) {
        print_board(gamestate.board);
        printf("Score: %d\n", gamestate.score);
        for (i = 0; i < FRUIT_TYPES; i++) {
            printf("Fruit %c: %d ", 'A'+i, gamestate.fruits_collected[i]);
        }
        printf("\n");
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &input);
        update_gamestate(&gamestate, input);
    }
    printf("Game over! Final score: %d\n", gamestate.score);
    return 0;
}