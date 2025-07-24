//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 20
#define COL_SIZE 50

int main(){

    int i, j, k;
    char grid[ROW_SIZE][COL_SIZE];
    char new_grid[ROW_SIZE][COL_SIZE];
    srand(time(NULL));

    /* Initialize the grid with random values */
    for(i=0; i<ROW_SIZE; i++){
        for(j=0; j<COL_SIZE; j++){
            grid[i][j] = rand() % 2 ? '#' : ' ';
            new_grid[i][j] = ' ';
        }
    }

    /* Print the initial grid */
    for(i=0; i<ROW_SIZE; i++){
        for(j=0; j<COL_SIZE; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    /* Start the Game of Life */
    for(k=0; k<100; k++){ /* Run the simulation for 100 iterations */

        /* Update the new grid based on the rules of the Game of Life */
        for(i=0; i<ROW_SIZE; i++){
            for(j=0; j<COL_SIZE; j++){

                int alive_neighbors = 0;
                int x, y;

                /* Count the alive neighbors */
                for(x=i-1; x<=i+1; x++){
                    for(y=j-1; y<=j+1; y++){
                        if(x<0 || x>=ROW_SIZE || y<0 || y>=COL_SIZE || (x==i && y==j))
                            continue;
                        if(grid[x][y] == '#')
                            alive_neighbors++;
                    }
                }

                /* Apply the rules of the Game of Life */
                if(grid[i][j] == '#'){
                    if(alive_neighbors < 2 || alive_neighbors > 3){
                        new_grid[i][j] = ' ';
                    } else {
                        new_grid[i][j] = '#';
                    }
                } else {
                    if(alive_neighbors == 3){
                        new_grid[i][j] = '#';
                    } else {
                        new_grid[i][j] = ' ';
                    }
                }
            }
        }

        /* Copy the new grid to the old grid */
        for(i=0; i<ROW_SIZE; i++){
            for(j=0; j<COL_SIZE; j++){
                grid[i][j] = new_grid[i][j];
            }
        }

        /* Clear the screen and print the new grid */
        system("clear");
        for(i=0; i<ROW_SIZE; i++){
            for(j=0; j<COL_SIZE; j++){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }

        /* Pause the simulation */
        usleep(200000);
    }

    return 0;
}