//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include<stdio.h>
#include<limits.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = { 
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
                        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
                        { 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
                        { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1 },
                        { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
                        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                        { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                    };

int dist[ROW][COL];
int visited[ROW][COL];
int parent_x[ROW][COL];
int parent_y[ROW][COL];

int minDistance(){
    int min = INT_MAX, min_index_row = -1, min_index_col = -1;
    for (int row = 0; row < ROW; row++){
        for (int col = 0; col < COL; col++){
            if (!visited[row][col] && dist[row][col] <= min){
                min = dist[row][col];
                min_index_row = row;
                min_index_col = col;
            }
        }
    }
    return min_index_row*COL+min_index_col;
}

void dijkstra(){
    for (int row = 0; row < ROW; row++){
        for (int col = 0; col < COL; col++){
            dist[row][col] = INT_MAX;
            visited[row][col] = 0;
        }
    }

    dist[0][0] = 0;

    for (int count = 0; count < ROW*COL-1; count++){
        int u = minDistance();
        int ur = u/COL, uc = u%COL;

        visited[ur][uc] = 1;
        if (ur-1 >= 0 && !visited[ur-1][uc] && map[ur-1][uc] == 1 && dist[ur][uc] != INT_MAX && (dist[ur][uc]+1 < dist[ur-1][uc])){
            dist[ur-1][uc] = dist[ur][uc] + 1;
            parent_x[ur-1][uc] = ur;
            parent_y[ur-1][uc] = uc;
        }

        if (uc-1 >= 0 && !visited[ur][uc-1] && map[ur][uc-1] == 1 && dist[ur][uc] != INT_MAX && (dist[ur][uc]+1 < dist[ur][uc-1])){
            dist[ur][uc-1] = dist[ur][uc] + 1;
            parent_x[ur][uc-1] = ur;
            parent_y[ur][uc-1] = uc;
        }

        if (uc+1 < COL && !visited[ur][uc+1] && map[ur][uc+1] == 1 && dist[ur][uc] != INT_MAX && (dist[ur][uc]+1 < dist[ur][uc+1])){
            dist[ur][uc+1] = dist[ur][uc] + 1;
            parent_x[ur][uc+1] = ur;
            parent_y[ur][uc+1] = uc;
        }

        if (ur+1 < ROW && !visited[ur+1][uc] && map[ur+1][uc] == 1 && dist[ur][uc] != INT_MAX && (dist[ur][uc]+1 < dist[ur+1][uc])){
            dist[ur+1][uc] = dist[ur][uc] + 1;
            parent_x[ur+1][uc] = ur;
            parent_y[ur+1][uc] = uc;
        }
    }
}

void printPath(){
    int row = ROW-1, col = COL-1;
    while (row != 0 || col != 0){
        printf("(%d,%d) -> ", row, col);
        int temp_row = row;
        row = parent_x[row][col];
        col = parent_y[temp_row][col];
    }
    printf("(%d,%d)\n", row, col);
}

int main(){
    dijkstra();
    printPath();
    return 0;
}