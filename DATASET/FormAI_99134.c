//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 10

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    //set all cells to 0
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;
        }
    }

    //plant mines randomly
    srand(time(NULL));
    int num_mines_planted = 0;
    while(num_mines_planted < NUM_MINES) {
        int i = rand() % BOARD_SIZE;
        int j = rand() % BOARD_SIZE;
        if(board[i][j] == 0) {
            board[i][j] = -1; //set mine
            num_mines_planted++;
        }
    }

    //initialize remaining cells with their counts
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == -1) continue; //skip mines
            int count = 0;
            for(int k=-1; k<=1; k++) {
                for(int l=-1; l<=1; l++) {
                    if(i+k < 0 || i+k >= BOARD_SIZE) continue; //out of bounds
                    if(j+l < 0 || j+l >= BOARD_SIZE) continue; //out of bounds
                    if(board[i+k][j+l] == -1) count++; //found a mine
                }
            }
            board[i][j] = count;
        }
    }
}

void reveal(int i, int j) {
    if(revealed[i][j]) return; //already revealed

    revealed[i][j] = 1; //mark cell as revealed

    if(board[i][j] == -1) {
        printf("Game Over!\n");
        exit(0);
    }

    if(board[i][j] == 0) {
        //expand reveal
        for(int k=-1; k<=1; k++) {
            for(int l=-1; l<=1; l++) {
                if(i+k < 0 || i+k >= BOARD_SIZE) continue; //out of bounds
                if(j+l < 0 || j+l >= BOARD_SIZE) continue; //out of bounds
                reveal(i+k, j+l); //recursive call
            }
        }
    }
}

void print_board(int is_end_game) {
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%2d ", i);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(!is_end_game && !revealed[i][j]) {
                printf(".  ");
            } else if(board[i][j] == -1) {
                printf("*  ");
            } else if(board[i][j] == 0) {
                printf("   "); //blank space
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_board();

    while(1) {
        print_board(0); //print unrevealed board
        int i, j;
        printf("Enter row and column to reveal: ");
        scanf("%d %d", &i, &j);
        reveal(i, j);
    }

    return 0;
}