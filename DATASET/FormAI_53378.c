//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GRID_SIZE 10
#define PROBABILITY 0.6

typedef struct cell{
    int status;
    int visited;
}cell;

int check_percolation(cell grid[][GRID_SIZE]){
    cell visited_grid[GRID_SIZE][GRID_SIZE];
    int i, j;
    for(i=0;i<GRID_SIZE;i++){
        for(j=0;j<GRID_SIZE;j++){
            visited_grid[i][j].status = grid[i][j].status;
            visited_grid[i][j].visited = 0;
        }
    }

    for(i=0;i<GRID_SIZE;i++){
        if(visited_grid[0][i].status == 1){
            visited_grid[0][i].visited = 1;
            if(check_path(visited_grid, 0, i) == 1){
                return 1;
            }
        }
    }
    return 0;
}

int check_path(cell visited_grid[][GRID_SIZE], int row, int col){
    if(row == GRID_SIZE-1){
        return 1;
    }
    if(col>0 && visited_grid[row][col-1].status == 1 && visited_grid[row][col-1].visited == 0){
        visited_grid[row][col-1].visited = 1;
        if(check_path(visited_grid, row, col-1) == 1){
            return 1;
        }
    }
    if(col<GRID_SIZE-1 && visited_grid[row][col+1].status == 1 && visited_grid[row][col+1].visited == 0){
        visited_grid[row][col+1].visited = 1;
        if(check_path(visited_grid, row, col+1) == 1){
            return 1;
        }
    }
    if(row>0 && visited_grid[row-1][col].status == 1 && visited_grid[row-1][col].visited == 0){
        visited_grid[row-1][col].visited = 1;
        if(check_path(visited_grid, row-1, col) == 1){
            return 1;
        }
    }
    if(row<GRID_SIZE-1 && visited_grid[row+1][col].status == 1 && visited_grid[row+1][col].visited == 0){
        visited_grid[row+1][col].visited = 1;
        if(check_path(visited_grid, row+1, col) == 1){
            return 1;
        }
    }
    return 0;
}

void print_grid(cell grid[][GRID_SIZE]){
    int i, j;
    for(i=0;i<GRID_SIZE;i++){
        for(j=0;j<GRID_SIZE;j++){
            printf("%d ", grid[i][j].status);
        }
        printf("\n");
    }
}

int main(){
    cell grid[GRID_SIZE][GRID_SIZE];
    int i, j;

    srand(time(NULL));

    // Initializing the grid
    for(i=0;i<GRID_SIZE;i++){
        for(j=0;j<GRID_SIZE;j++){
            if(((float)rand()/RAND_MAX) < PROBABILITY){
                grid[i][j].status = 1;
            }else{
                grid[i][j].status = 0;
            }
            grid[i][j].visited = 0;
        }
    }

    // Printing the initial grid
    printf("Initial Grid:\n");
    print_grid(grid);
    printf("\n");

    int percolation_check = check_percolation(grid);

    if(percolation_check == 1){
        printf("Percolation achieved!\n");
    }else{
        printf("Percolation not achieved!\n");
    }

    return 0;
}