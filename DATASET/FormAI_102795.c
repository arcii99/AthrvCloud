//FormAI DATASET v1.0 Category: Game of Life ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

void initialize_board(int board[][COL]);  // function to initialize the board
void print_board(int board[][COL]);  // function to print the board
int count_live_neighbors(int board[][COL], int row, int col);  // function to count live neighbors of a cell

int main() {
    int board[ROW][COL];  // declare the board

    // initialize the random number generator
    srand(time(0));

    initialize_board(board);  // initialize the board
    print_board(board);  // print the initial board configuration
    printf("\n");

    // update the board configuration at each time step
    for(int t=0; t<10; t++) {
        int new_board[ROW][COL];  // declare new board configuration

        // loop through each cell in the board
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                int live_neighbors = count_live_neighbors(board, i, j);

                // apply the Game of Life rules
                if(board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3))
                    new_board[i][j] = 0;
                else if(board[i][j] == 0 && live_neighbors == 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = board[i][j];
            }
        }

        // copy new board configuration to the original board
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                board[i][j] = new_board[i][j];
            }
        }

        print_board(board);  // print the board configuration at current time step
        printf("\n");
    }

    return 0;
}

// function to initialize the board with random live and dead cells
void initialize_board(int board[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// function to print the board
void print_board(int board[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to count live neighbors of a cell
int count_live_neighbors(int board[][COL], int row, int col) {
    int live_neighbors = 0;

    // check top neighbor
    if(row-1 >= 0 && board[row-1][col] == 1)
        live_neighbors++;

    // check bottom neighbor
    if(row+1 < ROW && board[row+1][col] == 1)
        live_neighbors++;

    // check left neighbor
    if(col-1 >= 0 && board[row][col-1] == 1)
        live_neighbors++;

    // check right neighbor
    if(col+1 < COL && board[row][col+1] == 1)
        live_neighbors++;

    // check top-left neighbor
    if(row-1 >= 0 && col-1 >=0 && board[row-1][col-1] == 1)
        live_neighbors++;

    // check top-right neighbor
    if(row-1 >= 0 && col+1 < COL && board[row-1][col+1] == 1)
        live_neighbors++;

    // check bottom-left neighbor
    if(row+1 < ROW && col-1 >= 0 && board[row+1][col-1] == 1)
        live_neighbors++;

    // check bottom-right neighbor
    if(row+1 < ROW && col+1 < COL && board[row+1][col+1] == 1)
        live_neighbors++;

    return live_neighbors;
}