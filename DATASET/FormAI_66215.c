//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 // board width
#define HEIGHT 25 //board height

//create board as a 2D array of integers
int board[HEIGHT][WIDTH];

//function to initialize board with random values
void init_board() {
    srand(time(0)); //seed random number generator with current time
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2; //randomly set cell to 0 or 1
        }
    }
}

//function to print board to console
void print_board() {
    printf("\n\n");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//function to count number of live neighbors for a given cell
int count_neighbors(int i, int j) {
    int count = 0;
    for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
            //skip checking current cell
            if(x == 0 && y == 0) {
                continue;
            }
            //calculate neighbor coordinates, considering edge cases
            int col = (j + y + WIDTH) % WIDTH;
            int row = (i + x + HEIGHT) % HEIGHT;
            //increment count if neighbor is alive
            if(board[row][col] == 1) {
                count++;
            }
        }
    }
    return count;
}

//function to update board values based on game rules
void update_board() {
    int new_board[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(i, j);
            //apply game rules
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0; //cell dies
            } else if(board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1; //cell is born
            } else {
                new_board[i][j] = board[i][j]; //cell remains the same
            }
        }
    }
    //copy new board values to original board
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    init_board();
    while(1) {
        print_board();
        update_board();
        getchar(); //pause between frames
    }
    return 0;
}