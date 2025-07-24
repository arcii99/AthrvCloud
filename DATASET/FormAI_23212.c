//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 30
#define HEIGHT 30

void initWorld(char world[WIDTH][HEIGHT]);
void showWorld(char world[WIDTH][HEIGHT]);
int countNeighbours(char world[WIDTH][HEIGHT], int row, int col);
void nextGeneration(char world[WIDTH][HEIGHT]);

int main(){
    char world[WIDTH][HEIGHT];
    int i;
    initWorld(world);
    for(i = 0; i < 100; i++){
        system("clear");
        printf("GENERATION %d:\n", i + 1);
        showWorld(world);
        nextGeneration(world);
        usleep(100000); //pause for 0.1 seconds
    }
    return 0;
}

void initWorld(char world[WIDTH][HEIGHT]){
    srand(time(NULL)); //seed random number with system time
    int row, col;
    for(row = 0; row < HEIGHT; row++){
        for(col = 0; col < WIDTH; col++){
            int random = rand() % 2; //0 or 1
            if(random == 0){
                world[row][col] = ' ';
            }
            else{
                world[row][col] = '*';
            }
        }
    }
}

void showWorld(char world[WIDTH][HEIGHT]){
    int row, col;
    for(row = 0; row < HEIGHT; row++){
        for(col = 0; col < WIDTH; col++){
            printf("%c ", world[row][col]);
        }
        printf("\n");
    }
}

int countNeighbours(char world[WIDTH][HEIGHT], int row, int col){
    int count = 0, r, c;
    for(r = row - 1; r <= row + 1; r++){
        for(c = col - 1; c <= col + 1; c++){
            if(r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH){ //check bounds
                if(world[r][c] == '*' && !(r == row && c == col)){ //cell is alive and not the current cell
                    count++;
                }
            }
        }
    }
    return count;
}

void nextGeneration(char world[WIDTH][HEIGHT]){
    int row, col, neighbours;
    char newWorld[WIDTH][HEIGHT];
    for(row = 0; row < HEIGHT; row++){
        for(col = 0; col < WIDTH; col++){
            neighbours = countNeighbours(world, row, col);
            if(world[row][col] == '*'){ //current cell is alive
                if(neighbours < 2 || neighbours > 3){ //loneliness or overcrowding
                    newWorld[row][col] = ' '; //cell dies
                }
                else{
                    newWorld[row][col] = '*'; //cell survives
                }
            }
            else{ //current cell is dead
                if(neighbours == 3){ //cell is born
                    newWorld[row][col] = '*';
                }
                else{
                    newWorld[row][col] = ' '; //cell remains dead
                }
            }
        }
    }
    //copy new world to old world
    for(row = 0; row < HEIGHT; row++){
        for(col = 0; col < WIDTH; col++){
            world[row][col] = newWorld[row][col];
        }
    }
}