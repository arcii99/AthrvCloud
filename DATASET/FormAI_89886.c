//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = 
{
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 1, 1, 0, 1},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}
};

struct position{
    int x;
    int y;
};

int find_exit(int x, int y){
    if(x < 0 || x >= ROW || y < 0 || y >= COL) 
        return 0;

    if(maze[x][y]==0 || maze[x][y]==2) 
        return 0;

    if(x == ROW-1 && y == COL-1){
        maze[x][y] = 2;
        return 1;
    }

    maze[x][y] = 2;

    struct position next_pos;
    next_pos.x = x + 1;
    next_pos.y = y;
    if (find_exit(next_pos.x, next_pos.y))
        return 1;

    next_pos.x = x;
    next_pos.y = y + 1;
    if (find_exit(next_pos.x, next_pos.y))
        return 1;
 
    next_pos.x = x - 1;
    next_pos.y = y;
    if (find_exit(next_pos.x, next_pos.y))
        return 1;

    next_pos.x = x;
    next_pos.y = y - 1;
    if (find_exit(next_pos.x, next_pos.y))
        return 1;
  
    maze[x][y] = 1;
    return 0;
}

int main(){
    int i, j;
    printf("\n Maze:");

    for( i = 0; i < ROW; i++){
        printf("\n");
        for(j = 0; j < COL; j++)
            printf("%d ", maze[i][j]);
    }

    if (find_exit(0, 0) == 1){
        printf("\n\n Path Found:");

        for( i = 0; i < ROW; i++){
            printf("\n");
            for(j = 0; j < COL; j++)
                printf("%d ", maze[i][j]);
        }
    }
    else 
        printf("\n\n No path found.\n");

    return 0;
}