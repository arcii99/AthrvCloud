//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

int rand_wall(){
    return (rand() % 2);
}

void setup(){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            visited[i][j] = 0;
            if(i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = rand_wall();
            }
        }
    }
    visited[1][1] = 1;
    grid[1][0] = 0;
}

void print_grid(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 1){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}

void dfs(int x, int y){
    visited[x][y] = 1;
    if(x - 1 > 0 && grid[x - 1][y] == 0 && visited[x - 1][y] == 0){ //up
        dfs(x - 1, y);
    }
    if(x + 1 < SIZE && grid[x + 1][y] == 0 && visited[x + 1][y] == 0){ //down
        dfs(x + 1, y);
    }
    if(y - 1 > 0 && grid[x][y - 1] == 0 && visited[x][y - 1] == 0){ //left
        dfs(x, y - 1);
    }
    if(y + 1 < SIZE && grid[x][y + 1] == 0 && visited[x][y + 1] == 0){ //right
        dfs(x, y + 1);
    }
}

int main(){
    setup();
    printf("Initial Grid:\n");
    print_grid();
    dfs(1, 1);
    printf("\nFinal Grid:\n");
    print_grid();
    return 0;
}