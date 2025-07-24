//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Surprise! I have a unique C Pathfinding algorithm for you!\n");
    int maze[5][5] = {{1,1,1,1,1},
                      {1,0,0,0,1},
                      {1,0,1,0,1},
                      {1,0,0,0,1},
                      {1,1,1,1,1}}; // the maze to be solved
    
    int xstart=3, ystart=1; // starting point 
    int xend=1, yend=3; // ending point
    int x = xstart, y = ystart; // current position

    printf("The maze is:\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    while(x != xend || y != yend){
        printf("Now at position (%d, %d)\n", x, y);

        if(maze[x-1][y] != 1){
            printf("Move Up\n");
            x--;
        }
        else if(maze[x][y+1] != 1){
            printf("Move Right\n");
            y++;
        }
        else if(maze[x+1][y] != 1){
            printf("Move Down\n");
            x++;
        }
        else if(maze[x][y-1] != 1){
            printf("Move Left\n");
            y--;
        }
        else{
            printf("Stuck! No way out.\n");
            break;
        }
    }

    if(x == xend && y == yend){
        printf("Congratulations! You have reached the end point (%d, %d)\n", x, y);
    }

    return 0;
}