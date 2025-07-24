//FormAI DATASET v1.0 Category: Chess AI ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[8][8]; // 2D Array to represent the chess board

// Function to initialize the chess board
void init_board(){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            board[i][j] = 0;
        }
    }

    // Placing the black rooks
    board[0][0] = -2;
    board[0][7] = -2;

    // Placing the white rooks
    board[7][0] = 2;
    board[7][7] = 2;

    // Placing the black knights
    board[0][1] = -3;
    board[0][6] = -3;

    // Placing the white knights
    board[7][1] = 3;
    board[7][6] = 3;

    // Placing the black bishops
    board[0][2] = -4;
    board[0][5] = -4;

    // Placing the white bishops
    board[7][2] = 4;
    board[7][5] = 4;

    // Placing the black queen
    board[0][3] = -5;

    // Placing the white queen
    board[7][3] = 5;

    // Placing the black king
    board[0][4] = -6;

    // Placing the white king
    board[7][4] = 6;

    // Placing the pawns
    for(i=0; i<8; i++){
        board[1][i] = -1;
        board[6][i] = 1;
    }
}

// Function to display the chess board
void display_board(){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to make a random move
void make_move(){
    int i, j, x, y;
    srand(time(NULL));
    x = rand() % 8;
    y = rand() % 8;
    while(board[x][y] == 0){
        x = rand() % 8;
        y = rand() % 8;
    }
    printf("Selected Piece: %d \n", board[x][y]);
    printf("Old Position: %c%d \n", 'A'+y, x+1);
    i = rand() % 8;
    j = rand() % 8;
    while(board[i][j] != 0){
        i = rand() % 8;
        j = rand() % 8;
    }
    board[i][j] = board[x][y];
    board[x][y] = 0;
    printf("New Position: %c%d \n", 'A'+j, i+1);
}

int main(){
    init_board();
    display_board();
    make_move();
    display_board();
    return 0;
}