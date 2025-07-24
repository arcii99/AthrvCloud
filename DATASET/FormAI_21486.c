//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50
#define GENERATIONS 100

/* Initialize the board randomly */
void initialize_board(int board[][COLS]){
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = rand() % 2;
        }
    }
}

/* Calculate the next generation */
void next_generation(int board[][COLS]){
    int neighbors;
    int new_board[ROWS][COLS];

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            neighbors = 0;
            
            /* Count the number of live neighbors */
            if(i > 0 && board[i-1][j] == 1){ /* Above */
                neighbors++;
            }
            if(i < ROWS - 1 && board[i+1][j] == 1){ /* Below */
                neighbors++;
            }
            if(j > 0 && board[i][j-1] == 1){ /* Left */
                neighbors++;
            }
            if(j < COLS - 1 && board[i][j+1] == 1){ /* Right */
                neighbors++;
            }
            if(i > 0 && j > 0 && board[i-1][j-1] == 1){ /* Upper Left */
                neighbors++;
            }
            if(i > 0 && j < COLS - 1 && board[i-1][j+1] == 1){ /* Upper Right */
                neighbors++;
            }
            if(i < ROWS - 1 && j > 0 && board[i+1][j-1] == 1){ /* Lower Left */
                neighbors++;
            }
            if(i < ROWS - 1 && j < COLS - 1 && board[i+1][j+1] == 1){ /* Lower Right */
                neighbors++;
            }

            /* Update the cell based on its living neighbors */
            if(board[i][j] == 1 && neighbors < 2){ /* Underpopulation */
                new_board[i][j] = 0;
            }
            else if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)){ /* Survival */
                new_board[i][j] = 1;
            }
            else if(board[i][j] == 1 && neighbors > 3){ /* Overpopulation */
                new_board[i][j] = 0;
            }
            else if(board[i][j] == 0 && neighbors == 3){ /* Reproduction */
                new_board[i][j] = 1;
            }
            else{
                new_board[i][j] = board[i][j];
            }
        }
    }

    /* Copy the new board to the old board */
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

/* Print the board */
void print_board(int board[][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == 1){
                printf("O ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(){
    int board[ROWS][COLS];

    initialize_board(board);
    print_board(board);

    for(int i = 0; i < GENERATIONS; i++){
        printf("Generation %d:\n", i+1);
        next_generation(board);
        print_board(board);
    }

    return 0;
}