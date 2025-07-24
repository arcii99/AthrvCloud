//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 15
#define COLS 20

// Function 1: Print the game board
void print_game_board(bool game_board[ROWS][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(game_board[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }   
}

// Function 2: Check if the cell is valid and alive
bool is_valid_alive_cell(int row, int col, bool game_board[ROWS][COLS]) {
    if(row < 0 || row >= ROWS) return false;
    if(col < 0 || col >= COLS) return false;
    return game_board[row][col];
}

// Function 3: Get the number of living neighbors
int get_living_neighbors(int row, int col, bool game_board[ROWS][COLS]) {
    int living_neighbors = 0;
    if(is_valid_alive_cell(row-1, col-1, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row-1, col, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row-1, col+1, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row, col-1, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row, col+1, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row+1, col-1, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row+1, col, game_board)) living_neighbors++;
    if(is_valid_alive_cell(row+1, col+1, game_board)) living_neighbors++;

    return living_neighbors;
}

// Function 4: Update the game board
void update_game_board(bool game_board[ROWS][COLS]) {
    bool new_game_board[ROWS][COLS];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int living_neighbors = get_living_neighbors(i, j, game_board);

            if(game_board[i][j] && (living_neighbors == 2 || living_neighbors == 3)) {
                new_game_board[i][j] = true;
            }
            else if(!game_board[i][j] && living_neighbors == 3) {
                new_game_board[i][j] = true;
            }
            else {
                new_game_board[i][j] = false;
            }
        }
    }

    // Update the game board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            game_board[i][j] = new_game_board[i][j];
        }
    }
}

int main() {
    bool game_board[ROWS][COLS];
    srand(time(NULL));

    // Initialize the game board with random values
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            game_board[i][j] = (rand() % 2 == 0) ? true : false;
        }
    }

    // Main game loop
    int generations = 0;
    while(true) {
        system("clear");
        printf("GENERATION %d\n", ++generations);
        print_game_board(game_board);
        update_game_board(game_board);
        usleep(100000);
    }

    return 0;
}