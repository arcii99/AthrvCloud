//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLUMNS 25

void print_cells(int cells[ROWS][COLUMNS]){
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            if(cells[i][j] == 1){
                printf("* ");
            }else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_cells(int cells[ROWS][COLUMNS]){
    int new_cells[ROWS][COLUMNS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            int alive_neighbors = 0;            
            if(i-1 >= 0 && j-1 >=0 && cells[i-1][j-1] == 1){
                alive_neighbors++;
            }
            if(i-1 >= 0 && cells[i-1][j] == 1){
                alive_neighbors++;
            }
            if(i-1 >= 0 && j+1 < COLUMNS && cells[i-1][j+1] == 1){
                alive_neighbors++;
            }
            if(j-1 >= 0 && cells[i][j-1] == 1){
                alive_neighbors++;
            }
            if(j+1 < COLUMNS && cells[i][j+1] == 1){
                alive_neighbors++;
            }
            if(i+1 < ROWS && j-1 >=0 && cells[i+1][j-1] == 1){
                alive_neighbors++;
            }
            if(i+1 < ROWS && cells[i+1][j] == 1){
                alive_neighbors++;
            }
            if(i+1 < ROWS && j+1 < COLUMNS && cells[i+1][j+1] == 1){
                alive_neighbors++;
            }
            if(cells[i][j] == 1){
                if(alive_neighbors < 2){
                    new_cells[i][j] = 0; //underpopulation
                }else if(alive_neighbors == 2 || alive_neighbors == 3){
                    new_cells[i][j] = 1; //survival
                }else{
                    new_cells[i][j] = 0; //overpopulation
                }
            }else{
                if(alive_neighbors == 3){
                    new_cells[i][j] = 1; //reproduction
                }else{
                    new_cells[i][j] = 0; //no change
                }
            }
        }
    }
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            cells[i][j] = new_cells[i][j];
        }
    }
}

void game_of_life(int cells[ROWS][COLUMNS], int iterations){
    print_cells(cells);

    if(iterations == 0){
        return;
    }

    update_cells(cells);
    game_of_life(cells, iterations-1);
}

int main(){
    int cells[ROWS][COLUMNS] = {{0}};
    cells[2][2] = 1;
    cells[2][3] = 1;
    cells[2][4] = 1;
    
    game_of_life(cells, 10);
    
    return 0;
}