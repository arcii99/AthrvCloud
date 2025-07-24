//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * A unique C Chess AI example program in Alan Touring style
 */

int board[8][8] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};
/*
 * Initialize the board
 */

void init_board(){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i == 0 || i == 1 || i == 6 || i == 7){
                board[i][j] = board[i][j] * -1;
            }
        }
    }
}

/*
 * Print the current state of the board
 */

void print_board(){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

/*
 * Generate a random number between 0 and n-1
 */

int random_int(int n){
    srand(time(NULL));
    return rand() % n;
}

/*
 * Make a random move
 */

void random_move(){
    int from_x = random_int(8);
    int from_y = random_int(8);
    int to_x = random_int(8);
    int to_y = random_int(8);

    int piece = board[from_x][from_y];

    if(piece == 0){
        random_move();
        return;
    }

    if(piece < 0){
        if(to_x >= from_x){
            random_move();
            return;
        }
    }

    if(piece > 0){
        if(to_x <= from_x){
            random_move();
            return;
        }
    }

    int dx = abs(from_x - to_x);
    int dy = abs(from_y - to_y);

    switch(abs(piece)){
        case 1:
            if(dx == 1 && dy == 0 && board[to_x][to_y] == 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;

        case 2:
            if(dx == 2 && dy == 1 && board[to_x][to_y] <= 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;

        case 3:
            if(dx == dy && board[to_x][to_y] <= 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;

        case 4:
            if((dx == 0 && dy > 0) || (dx > 0 && dy == 0) && board[to_x][to_y] <= 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;

        case 5:
            if((dx == dy && dx > 0) || (dx == 0 && dy > 0) || (dx > 0 && dy == 0) && board[to_x][to_y] <= 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;

        case 6:
            if(dx == 1 && dy == 1 && board[to_x][to_y] <= 0){
                board[to_x][to_y] = board[from_x][from_y];
                board[from_x][from_y] = 0;
                return;
            }
            break;
    }

    random_move();
}

int main(){
    init_board();

    int i;
    for(i = 0; i < 100; i++){
        print_board();
        printf("\n");
    
        random_move();
    }

    return 0;
}