//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int gameGrid[ROWS][COLUMNS], tempGrid[ROWS][COLUMNS];

int countNeighbours(int x, int y){
    int neighbours = 0;
    if(x > 0 && y > 0 && gameGrid[x-1][y-1] == 1) neighbours++;
    if(y > 0 && gameGrid[x][y-1] == 1) neighbours++;
    if(x < ROWS-1 && y > 0 && gameGrid[x+1][y-1] == 1) neighbours++;
    if(x > 0 && gameGrid[x-1][y] == 1) neighbours++;
    if(x < ROWS-1 && gameGrid[x+1][y] == 1) neighbours++;
    if(x > 0 && y < COLUMNS-1 && gameGrid[x-1][y+1] == 1) neighbours++;
    if(y < COLUMNS-1 && gameGrid[x][y+1] == 1) neighbours++;
    if(x < ROWS-1 && y < COLUMNS-1 && gameGrid[x+1][y+1] == 1) neighbours++;
    return neighbours;
}

void printGrid(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            if(gameGrid[i][j]) printf("X ");
            else printf("- ");
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL)); //initializes the random number generator
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            gameGrid[i][j] = rand()%2; //randomly fills the grid with 1s and 0s
        }
    }
    while(1){ //infinite loop to iterate through generations
        printGrid(); //prints the current generation
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLUMNS; j++){
                int neighbours = countNeighbours(i,j);
                if(gameGrid[i][j] == 1){ //cell is alive
                    if(neighbours < 2 || neighbours > 3) tempGrid[i][j] = 0; //dies due to isolation or overpopulation
                    else tempGrid[i][j] = 1; //lives on
                }
                else{ //cell is dead
                    if(neighbours == 3) tempGrid[i][j] = 1; //comes to life due to reproduction
                    else tempGrid[i][j] = 0; //stays dead
                }
            }
        }
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLUMNS; j++){
                gameGrid[i][j] = tempGrid[i][j]; //copies the temporary grid to the game grid
            }
        }
    }
    return 0;
}