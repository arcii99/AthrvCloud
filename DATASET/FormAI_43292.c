//FormAI DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

//print the current state of the world
void printWorld(int world[][WIDTH]) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            if(world[i][j]) printf("* ");
            else printf("- ");
        }
        printf("\n");
    }
}

//count neighbors for a cell in the world
int countNeighbors(int world[][WIDTH], int i, int j) {
    int count = 0;
    for(int x=i-1;x<=i+1;x++) {
        for(int y=j-1;y<=j+1;y++) {
            if(x<0 || x>=HEIGHT || y<0 || y>=WIDTH || (x==i && y==j)) continue;
            if(world[x][y]) count++;
        }
    }
    return count;
}

//update the world for the next generation
void updateWorld(int world[][WIDTH]) {
    int newWorld[HEIGHT][WIDTH];
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            int count = countNeighbors(world, i, j);
            if(world[i][j]) {
                if(count==2 || count==3) newWorld[i][j] = 1;
                else newWorld[i][j] = 0;
            }
            else {
                if(count==3) newWorld[i][j] = 1;
                else newWorld[i][j] = 0;
            }
        }
    }
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            world[i][j] = newWorld[i][j];
        }
    }
}

int main() {
    //initialize the world with random cells
    int world[HEIGHT][WIDTH];
    srand(time(NULL));
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            world[i][j] = rand() % 2;
        }
    }
    //run the game of life for 20 generations
    for(int i=0;i<20;i++) {
        system("cls"); //clear the console screen (for Windows)
        printWorld(world);
        updateWorld(world);
        printf("Generation %d\n", i+1);
        printf("Press enter to continue...");
        getchar();
    }
    return 0;
}