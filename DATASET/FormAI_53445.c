//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 30
#define HEIGHT 30

// Function to generate random initial state
void init_game(int game_board[HEIGHT][WIDTH]) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            game_board[i][j] = rand() % 2;
        }
    }
}

// Function to print current state of the game
void print_game_board(int game_board[HEIGHT][WIDTH]) {
    printf("\n");
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            printf("%c",(game_board[i][j]) ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int game_board[HEIGHT][WIDTH];

    init_game(game_board);
    print_game_board(game_board);

    sleep(1); // wait one second before updating the board

    // Start the game loop
    while(1) {
        int new_board[HEIGHT][WIDTH];
        for(int i=0;i<HEIGHT;i++) {
            for(int j=0;j<WIDTH;j++) {
                int neighbours = 0;

                // count the number of alive neighbours
                for(int k=i-1;k<=i+1;k++) {
                    for(int l=j-1;l<=j+1;l++) {
                        if(k>=0 && k<HEIGHT && l>=0 && l<WIDTH && !(k==i && l==j) && game_board[k][l]) {
                            neighbours++;
                        }
                    }
                }

                // decide if the cell is alive or dead based on the number of neighbours
                if(game_board[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                    new_board[i][j] = 1;
                } else if(game_board[i][j] == 0 && neighbours == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }

        // update the game board
        for(int i=0;i<HEIGHT;i++) {
            for(int j=0;j<WIDTH;j++) {
                game_board[i][j] = new_board[i][j];
            }
        }

        // print the current state of the board
        print_game_board(game_board);

        sleep(1); // wait one second before updating the board again
    }

    return 0;
}