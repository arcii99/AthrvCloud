//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

void initialize_board(int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
void update_board(int board[HEIGHT][WIDTH]);

int main() {
    int board[HEIGHT][WIDTH];
    initialize_board(board);
    
    while(1) {
        print_board(board);
        update_board(board);
        usleep(50000); // Sleep for 50ms
    }
    
    return 0;
}

void initialize_board(int board[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    printf("\033[H\033[J"); // Clear terminal screen
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j]) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int neighbors = 0;
            for(int k = -1; k <= 1; k++) {
                for(int l = -1; l <= 1; l++) {
                    if(!(k == 0 && l == 0)) {
                        int x = i + k;
                        int y = j + l;
                        neighbors += board[(x + HEIGHT) % HEIGHT][(y + WIDTH) % WIDTH];
                    }
                }
            }
            if(board[i][j]) {
                if(neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0; // Dies from underpopulation or overpopulation
                } else {
                    new_board[i][j] = 1; // Lives on
                }
            } else {
                if(neighbors == 3) {
                    new_board[i][j] = 1; // Comes to life from reproduction
                } else {
                    new_board[i][j] = 0; // Remains dead
                }
            }
        }
    }
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}