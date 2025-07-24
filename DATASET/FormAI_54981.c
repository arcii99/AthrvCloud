//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ROW 10
#define COL 10

int is_valid(int i, int j) {
    return (i >= 0 && i < ROW && j >= 0 && j < COL);
}

int bfs(int maze[ROW][COL], int row_start, int col_start, int row_dest, int col_dest) {
    if(!maze[row_start][col_start] || !maze[row_dest][col_dest]) {
        return -1;
    }
    
    int distance[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j]) {
                distance[i][j] = INT_MAX;
            }
            else {
                distance[i][j] = -1;
            }
        }
    }
    distance[row_start][col_start] = 0;
    
    int horizontal[4] = {1, -1, 0, 0};
    int vertical[4] = {0, 0, 1, -1};
    
    int queue[ROW*COL][2];
    int front = -1, rear = -1;
    queue[++rear][0] = row_start;
    queue[rear][1] = col_start;
    
    while(front != rear) {
        int i = queue[++front][0];
        int j = queue[front][1];
        for(int k=0; k<4; k++) {
            int i_new = i+vertical[k];
            int j_new = j+horizontal[k];
            
            if(is_valid(i_new, j_new) && maze[i_new][j_new] && distance[i_new][j_new] == INT_MAX) {
                queue[++rear][0] = i_new;
                queue[rear][1] = j_new;
                distance[i_new][j_new] = distance[i][j] + 1;
            }
        }
    }
    return distance[row_dest][col_dest];
}
int main() {
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    int row_start = 0, col_start = 0;
    int row_dest = 9, col_dest = 9;
    int min_distance = bfs(maze, row_start, col_start, row_dest, col_dest);
    if(min_distance == -1) {
        printf("There is no path between source and destination.\n");
    }
    else {
        printf("Minimum distance between source and destination is : %d\n", min_distance);
    }
    return 0;
}