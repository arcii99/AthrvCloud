//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 20 //number of rows in the grid
#define COL 40 //number of columns in the grid

int grid[ROW][COL]; //grid for the Game of Life simulation

//generates the initial grid with random values of 0's and 1's
void initialize_grid(){

    srand(time(NULL));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            grid[i][j] = rand()%2;
        }
    }
}

//prints the current state of the grid
void print_grid(){

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if (grid[i][j])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}

//gets the next state of the grid based on Game of Life rules
void get_next_gen(){

    int next_grid[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){

            //count the number of live neighbors for current cell
            int count = 0;
            if(i>0 && j>0 && grid[i-1][j-1])
                count++;
            if(i>0 && grid[i-1][j])
                count++;
            if(i>0 && j<COL-1 && grid[i-1][j+1])
                count++;
            if(j>0 && grid[i][j-1])
                count++;
            if(j<COL-1 && grid[i][j+1])
                count++;
            if(i<ROW-1 && j>0 && grid[i+1][j-1])
                count++;
            if(i<ROW-1 && grid[i+1][j])
                count++;
            if(i<ROW-1 && j<COL-1 && grid[i+1][j+1])
                count++;

            //apply the Game of Life rules to get next state
            if(grid[i][j]){ //cell is alive
                if(count<2 || count>3)
                    next_grid[i][j] = 0;
                else
                    next_grid[i][j] = 1;
            }
            else{ //cell is dead
                if(count == 3)
                    next_grid[i][j] = 1;
                else
                    next_grid[i][j] = 0;
            }
        }
    }

    //update the grid with the next state
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            grid[i][j] = next_grid[i][j];
        }
    }
}

int main(){

    initialize_grid();
    printf("Initial state:\n");
    print_grid();

    //simulate 100 generations of Game of Life
    for(int i=0;i<100;i++){
        get_next_gen();
        printf("\nGeneration %d:\n", i+1);
        print_grid();
    }

    return 0;
}