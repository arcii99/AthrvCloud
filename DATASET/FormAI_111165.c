//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function Declarations
void init_game_board(int game_board[ROWS][COLS]);
void print_game_board(int game_board[ROWS][COLS]);
void update_game_board(int game_board[ROWS][COLS]);

int main(void){
    // Initialize Game Board
    int game_board[ROWS][COLS];
    init_game_board(game_board);

    // Game Loop
    while(1){
        // Clear Console
        system("clear");

        // Print Game Board
        print_game_board(game_board);

        // Update Game Board
        update_game_board(game_board);

        // Sleep for 500ms
        usleep(500 * 1000);
    }

    return 0;
}

void init_game_board(int game_board[ROWS][COLS]){
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            game_board[i][j] = (rand() % 2 == 1);
        }
    }
}

void print_game_board(int game_board[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(game_board[i][j]){
                printf("* ");
            }else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_game_board(int game_board[ROWS][COLS]){
    int temp_board[ROWS][COLS];

    for(int i = 1; i < ROWS - 1; i++){
        for(int j = 1; j < COLS - 1; j++){
            int alive_neighbors = 0;
            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    alive_neighbors += game_board[i + k][j + l];
                }
            }
            alive_neighbors -= game_board[i][j];

            if(alive_neighbors <= 1 || alive_neighbors >= 4){
                temp_board[i][j] = 0;
            }else if(alive_neighbors == 3){
                temp_board[i][j] = 1;
            }else{
                temp_board[i][j] = game_board[i][j];
            }
        }
    }

    for(int i = 1; i < ROWS - 1; i++){
        for(int j = 1; j < COLS - 1; j++){
            game_board[i][j] = temp_board[i][j];
        }
    }
}