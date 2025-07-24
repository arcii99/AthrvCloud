//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 8

int map[ROW][COL] = {
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 1, 1, 1, 1, 1, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0}
};

struct Node {
   int x, y;
   int dist;
};

int is_valid(int row, int col) {
   return (row >= 0) && (row < ROW) &&
          (col >= 0) && (col < COL);
}

int is_blocked(int row, int col) {
   return map[row][col] == 1;
}

int is_destination(int row, int col, struct Node dest) {
   return row == dest.x && col == dest.y;
}

int pathfound = 0;
void bfs_traversal(int sx, int sy, struct Node dest) {
   //source is valid
   if (!is_valid(sx, sy) || is_blocked(sx, sy))
      return;

   //destination is valid
   if (is_destination(sx, sy, dest)) {
      pathfound = 1;
      return;
   }

   //initialize visiting
   int visited[ROW][COL];
   memset(visited, 0, sizeof(visited));
   struct Node queue[ROW * COL];
   int qsize = 0;

   //mark the starting point as visited and add to queue
   visited[sx][sy] = 1;
   struct Node start = {sx, sy, 0};
   queue[qsize++] = start;

   while (qsize > 0) {
      //dequeue the front node and check if it's the destination
      struct Node current = queue[0];
      if (is_destination(current.x, current.y, dest)) {
         pathfound = 1;
         break;
      }

      //otherwise explore its neighbors and add to queue
      int x = current.x;
      int y = current.y;
      int dist = current.dist;
      if (is_valid(x-1, y) && !visited[x-1][y] && !is_blocked(x-1, y)) {
         visited[x-1][y] = 1;
         struct Node neighbor = {x-1, y, dist+1};
         queue[qsize++] = neighbor;
      }
      if (is_valid(x+1, y) && !visited[x+1][y] && !is_blocked(x+1, y)) {
         visited[x+1][y] = 1;
         struct Node neighbor = {x+1, y, dist+1};
         queue[qsize++] = neighbor;
      }
      if (is_valid(x, y-1) && !visited[x][y-1] && !is_blocked(x, y-1)) {
         visited[x][y-1] = 1;
         struct Node neighbor = {x, y-1, dist+1};
         queue[qsize++] = neighbor;
      }
      if (is_valid(x, y+1) && !visited[x][y+1] && !is_blocked(x, y+1)) {
         visited[x][y+1] = 1;
         struct Node neighbor = {x, y+1, dist+1};
         queue[qsize++] = neighbor;
      }

      //dequeue the current node
      for (int i = 0; i < qsize-1; i++) {
         queue[i] = queue[i+1];
      }
      qsize--;
   }
}

int main() {
   struct Node source = {2, 0};
   struct Node dest = {5, 7};
   bfs_traversal(source.x, source.y, dest);
   if (pathfound) {
      printf("The path from (%d,%d) to (%d,%d) is found!\n", source.x, source.y, dest.x, dest.y);
   } else {
      printf("The path from (%d,%d) to (%d,%d) is not found!\n", source.x, source.y, dest.x, dest.y);
   }

   return 0;
}