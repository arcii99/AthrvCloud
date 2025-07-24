//FormAI DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(int board[][COLS], int gen);
void update_board(int board[][COLS], int new_board[][COLS]);
int count_alive_neighbors(int board[][COLS], int row, int col);

int main()
{
    srand(time(NULL)); // initialize random seed
    int board[ROWS][COLS] = {0}; // initialize board with all dead cells (0)
    int new_board[ROWS][COLS] = {0}; // create new board for next generation
    int generation = 0; // initialize generation counter
    int i, j;

    // randomly generate initial cells in the center of the board
    for(i = ROWS/2 - 3; i <= ROWS/2 + 3; i++) {
        for(j = COLS/2 - 3; j <= COLS/2 + 3; j++) {
            board[i][j] = rand() % 2;
        }
    }

    while(1) {
        system("clear"); // clear console between generations (for Unix systems)
        print_board(board, generation);
        update_board(board, new_board);
        generation++;
    }

    return 0;
}

void print_board(int board[][COLS], int gen)
{
    printf("Generation %d:\n", gen);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j]==1) printf("* "); // alive cell
            else printf(". "); // dead cell
        }
        printf("\n");
    }
}

void update_board(int board[][COLS], int new_board[][COLS])
{
    int count, cell;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            count = count_alive_neighbors(board, i, j);
            cell = board[i][j];

            if(cell==1 && count<2) new_board[i][j] = 0; // underpopulation
            else if(cell==1 && (count==2 || count==3)) new_board[i][j] = 1; // survival
            else if(cell==1 && count>3) new_board[i][j] = 0; // overpopulation
            else if(cell==0 && count==3) new_board[i][j] = 1; // reproduction
            else new_board[i][j] = cell;
        }
    }

    // copy new board back to original board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int count_alive_neighbors(int board[][COLS], int row, int col)
{
    int count = 0;

    // loop through neighbors of the current cell
    for(int i = row-1; i <= row+1; i++) {
        for(int j = col-1; j <= col+1; j++) {
            // skip the current cell
            if(i==row && j==col) continue;
            // count living neighbors
            if(board[i][j]==1) count++;
        }
    }

    return count;
}