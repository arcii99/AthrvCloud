//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define N 9

int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                   { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                   { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                   { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

int row_check[N][N+1];
int col_check[N][N+1];
int grid_check[N][N+1];
int solved = 0;

void print_grid(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

int is_safe(int row, int col, int num){
    int row_start = (row/N)*N;
    int col_start = (col/N)*N;
    if(row_check[row][num] || col_check[col][num] || grid_check[row_start+(col/N)][num]){
        return 0;
    }
    return 1;
}

void* solve_sudoku(void* arg){
    int row = *((int *)arg);
    for(int i=row;i<row+1;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                for(int num=1;num<=N;num++){
                    if(is_safe(i,j,num)){
                        grid[i][j] = num;
                        row_check[i][num] = 1;
                        col_check[j][num] = 1;
                        grid_check[(i/N)*N+(j/N)][num] = 1;
                        solve_sudoku(arg);
                        if(!solved){
                            grid[i][j] = 0;
                            row_check[i][num] = 0;
                            col_check[j][num] = 0;
                            grid_check[(i/N)*N+(j/N)][num] = 0;
                        }
                    }
                }
                return NULL;
            } 
        }
    }
    solved = 1;
    return NULL;
}

int main(){
    pthread_t threads[N];
    for(int i=0;i<N;i++){
        pthread_create(&threads[i], NULL, solve_sudoku, &i);
    }
    for(int i=0;i<N;i++){
        pthread_join(threads[i], NULL);
    }
    print_grid();
    return 0;
}