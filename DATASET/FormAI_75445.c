//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h> 

#define ROW 10 
#define COL 10 

int findPath(int maze[ROW][COL], int x, int y, int sol[ROW][COL]) 
{ 
    if(x == ROW-1 && y == COL-1) { 
        sol[x][y] = 1; 
        return 1; 
    } 
    
    if(x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1 && sol[x][y] != 1) { 
        sol[x][y] = 1; 
    
        if(findPath(maze, x+1, y, sol) == 1) 
            return 1; 
    
        if(findPath(maze, x, y+1, sol) == 1) 
            return 1; 
        
        if(findPath(maze, x-1, y, sol) == 1) 
            return 1; 
        
        if(findPath(maze, x, y-1, sol) == 1) 
            return 1; 
        
        sol[x][y] = 0; 
        return 0; 
    } 
    
    return 0; 
} 

int main() 
{ 
    int maze[ROW][COL] = { {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 1, 0, 1, 0, 1, 1, 1, 1, 0}, 
                            {0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, 
                            {0, 1, 1, 1, 0, 1, 1, 1, 1, 0}, 
                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
                            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1} }; 
    
    int sol[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }; 
        
    if(findPath(maze, 0, 0, sol) == 1) 
    { 
        printf("Path Found:\n"); 
        for(int i=0; i<ROW; i++) 
        { 
            for(int j=0; j<COL; j++) 
                printf("%d ", sol[i][j]); 
            printf("\n"); 
        } 
    } 
    else { 
        printf("No Path Found\n"); 
    } 
    
    return 0; 
}