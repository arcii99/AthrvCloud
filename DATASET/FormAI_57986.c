//FormAI DATASET v1.0 Category: Chess AI ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int chess_board[8][8] = { // initial chess board configuration
        {-5, -3, -4, -9,-10, -4, -3, -5},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 1,  1,  1,  1,  1,  1,  1,  1},
        { 5,  3,  4,  9, 10,  4,  3,  5}
};

// shape-shifting function to change the configuration of the board
void shift_board() {
    int config = rand() % 3;
    switch (config) {
        case 0: // mirror
            for (int x = 0; x < 4; x++) {
	            for (int y = 0; y < 8; y++) {
	                int temp = chess_board[x][y];
		            chess_board[x][y] = chess_board[7-x][y];
		            chess_board[7-x][y] = temp;
	            }
	        }
	        break;
        case 1: // rotate 90 degrees
            for (int i = 0; i < 4; i++) {
	            for (int j = i; j < 8-i-1; j++) {
		            int temp = chess_board[j][7-i];
		            chess_board[j][7-i] = chess_board[i][j];
		            chess_board[i][j] = chess_board[7-j][i];
		            chess_board[7-j][i] = chess_board[7-i][7-j];
		            chess_board[7-i][7-j] = temp;
	            }
            }
            break;
        case 2: // shuffle
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 4; y++) {
                    int temp = chess_board[x][y];
                    chess_board[x][y] = chess_board[x][7-y];
                    chess_board[x][7-y] = temp;
                }
            }
            break;
    }
}

// function to print current board configuration
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", chess_board[i][j]);
        }
        printf("\n");
    }
}

// function to play a random move
void play_random_move() {
    int x1, y1, x2, y2;

    do { // select a random piece to move
        x1 = rand() % 8;
        y1 = rand() % 8;
    } while (chess_board[x1][y1] == 0);
    
    do { // select a random position to move the piece to
        x2 = rand() % 8;
        y2 = rand() % 8;
    } while ((x2 == x1) && (y2 == y1));
    
    // move the piece to the selected position
    chess_board[x2][y2] = chess_board[x1][y1];
    chess_board[x1][y1] = 0;
}

int main() {
    srand(time(NULL)); // set random seed
    int counter = 0;

    // play 10 random moves and shift the board configuration after each move
    for (int i = 0; i < 10; i++) {
        printf("Move %d:\n", i+1);
        play_random_move();
        print_board();
        shift_board();
        counter++;
    }
    
    printf("Total number of board configurations: %d\n", counter);

    return 0;
}