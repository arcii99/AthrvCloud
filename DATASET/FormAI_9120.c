//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_board(int board[][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%c ", board[i][j] ? '*' : ' ');
        }
        printf("\n");   
    }
}

int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    
    for(int i=-1;i<=1;i++) {
        for(int j=-1;j<=1;j++) {
            if(i == 0 && j == 0)
                continue;
            int r = row + i;
            int c = col + j;
            
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS)
                continue;
                
            if(board[r][c])
                count++;                
        }
    }
    
    return count;
}

void next_generation(int board[][COLS], int next_board[][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            int count = count_neighbors(board, i, j);
            
            if(board[i][j]) {
                if(count < 2 || count > 3)
                    next_board[i][j] = 0;
                else
                    next_board[i][j] = 1;
            }
            else {
                if(count == 3)
                    next_board[i][j] = 1;
                else
                    next_board[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int main()
{
    int board[ROWS][COLS] = {0};
    int next_board[ROWS][COLS] = {0};
    
    srand(time(NULL));
    
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    while(1) {
        system("clear");
        
        print_board(board);
        next_generation(board, next_board);
        
        usleep(500000);
    }

    return 0;
}