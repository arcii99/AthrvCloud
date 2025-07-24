//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 5
#define INF 9999

typedef enum { false, true } bool;

int grid[ROW][COL] = {
  {0, 3, 4, INF, 2},
  {INF, 5, 8, 7, 1},
  {2, INF, 4, 9, 5},
  {INF, INF, INF, 12, 6},
  {7, INF, 8, 1, 3}
};

typedef struct {
  int x;
  int y;
} Point;

//This function prints the grid
void printGrid(int grid[ROW][COL]) {
  for(int i=0;i<ROW;i++) {
    for(int j=0;j<COL;j++) {
      if(grid[i][j] == INF)
        printf("INF ");
      else
        printf("%d ",grid[i][j]);
    }
    printf("\n");
  }
}

//This function checks if the coordinate is within the grid and not blocked
bool isSafe(int grid[ROW][COL], bool visited[ROW][COL], int row, int col) {
  return (row>=0) && (row<ROW) && (col>=0) && (col<COL) && !visited[row][col] && grid[row][col]!=INF;
}

//This function returns the minimum distance coordinate from the unvisited ones
Point getMinPoint(int grid[ROW][COL], bool visited[ROW][COL], int dist[ROW][COL]) {
  Point min_point;
  min_point.x = -1;
  min_point.y = -1;
  int min_dist = INF;
  
  for(int i=0;i<ROW;i++) {
    for(int j=0;j<COL;j++) {
      if(isSafe(grid, visited, i, j) && dist[i][j] <= min_dist) {
        min_point.x = i;
        min_point.y = j;
        min_dist = dist[i][j];
      }
    }
  }
  return min_point;
}

//This function updates the distances to each unvisited node if there is a shorter path
void updateDistances(int grid[ROW][COL], bool visited[ROW][COL], int dist[ROW][COL], int curr_row, int curr_col) {
  
  int adj_row[4] = {-1, 0, 1, 0};
  int adj_col[4] = {0, 1, 0, -1};
  
  for(int i=0;i<4;i++) {
    int adj_row_val = curr_row + adj_row[i];
    int adj_col_val = curr_col + adj_col[i];
    
    if(isSafe(grid, visited, adj_row_val, adj_col_val) && (dist[curr_row][curr_col] + grid[adj_row_val][adj_col_val]) < dist[adj_row_val][adj_col_val])
      dist[adj_row_val][adj_col_val] = dist[curr_row][curr_col] + grid[adj_row_val][adj_col_val];
  }
}

//This function uses Dijkstra's algorithm to find the shortest path from start to end
void dijkstraAlgorithm(int start_row, int start_col, int end_row, int end_col) {
  
  bool visited[ROW][COL];
  int dist[ROW][COL];

  for(int i=0;i<ROW;i++) {
    for(int j=0;j<COL;j++) {
      visited[i][j] = false;
      dist[i][j] = INF;
    }
  }
  
  dist[start_row][start_col] = 0;
  
  for(int count=0;count<(ROW*COL)-1;count++) {
    Point curr_point = getMinPoint(grid, visited, dist);
    
    visited[curr_point.x][curr_point.y] = true;
    
    updateDistances(grid, visited, dist, curr_point.x, curr_point.y);
  }
  
  printf("The shortest path from (%d,%d) to (%d,%d) is %d",start_row, start_col, end_row, end_col, dist[end_row][end_col]);
}

int main() {
  printf("The grid is: \n");
  printGrid(grid);
  
  dijkstraAlgorithm(0,0,2,2);

  return 0;
}