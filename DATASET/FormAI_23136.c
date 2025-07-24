//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include <stdio.h>

// Welcome to my unique Pathfinding algorithm program!
// I am beyond excited to show you how my algorithm works. 

void main() {
    int map[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
    };
    
    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;
    
    int path[100][2];
    int steps = 1;
    
    // Here is my pathfinding algorithm in action!
    int x = startX;
    int y = startY;
    while (x != endX || y != endY) {
        path[steps][0] = x;
        path[steps][1] = y;
        steps++;
        
        if (map[x][y+1] == 0) {
            y++;
        } else if (map[x+1][y] == 0) {
            x++;
        } else if (map[x][y-1] == 0) {
            y--;
        } else if (map[x-1][y] == 0) {
            x--;
        } else {
            printf("Error: Cannot find path!");
            return;
        }
    }
    
    // The path has been found! Let's output the results.
    printf("Path found!\n");
    for (int i = 1; i < steps; i++) {
        printf("(%d,%d) ", path[i][0], path[i][1]);
    }
    printf("(%d,%d)", endX, endY);
}

// Thank you for checking out my program! 
// I hope you found it as exciting as I did to create it!
// I look forward to exploring more unique programming challenges with you in the future!