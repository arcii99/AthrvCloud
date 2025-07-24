//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5
#define INF 1000000

typedef struct {
   int row;
   int col;
} Pair;

int grid[ROW][COL] = {
   { 1, 0, 1, 1, 1 },
   { 1, 0, 1, 0, 1 },
   { 1, 1, 1, 0, 1 },
   { 0, 0, 0, 0, 1 },
   { 1, 1, 1, 1, 1 }
};

bool visited[ROW][COL];
int dist[ROW][COL];

int rowDir[] = {-1, 0, 1, 0};
int colDir[] = {0, 1, 0, -1};

bool isValid(int row, int col) {
   return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

void init() {
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
         dist[i][j] = INF;
      }
   }
}

void BFS(Pair src, Pair dest) {
   visited[src.row][src.col] = true;
   dist[src.row][src.col] = 0;
   
   // Queue implemented using array
   Pair queue[ROW * COL];
   int front = 0, rear = 0;
   queue[rear++] = src;

   while (front != rear) {
      Pair curr = queue[front++];

      if (curr.row == dest.row && curr.col == dest.col) {
         printf("Shortest Path: %d", dist[curr.row][curr.col]);
         return;
      }

      for (int i = 0; i < 4; i++) {
         int adjRow = curr.row + rowDir[i];
         int adjCol = curr.col + colDir[i];

         if (isValid(adjRow, adjCol) && grid[adjRow][adjCol] && !visited[adjRow][adjCol]) {
            visited[adjRow][adjCol] = true;
            dist[adjRow][adjCol] = dist[curr.row][curr.col] + 1;
            queue[rear++] = (Pair){ adjRow, adjCol };
         }
      }
   }

   printf("No possible path");
}

int main() {
   Pair src = { 0, 0 };
   Pair dest = { 4, 4 };

   init();

   BFS(src, dest);

   return 0;
}