//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int x, y;
   struct node *next;
} Node;

typedef struct queue {
   Node *front, *rear;
} Queue;

Queue *createQueue() {
   Queue *q = (Queue*)malloc(sizeof(Queue));
   q->front = q->rear = NULL;
   return q;
}

void enQueue(Queue *q, int x, int y) {
   Node *new = (Node*)malloc(sizeof(Node));
   new->x = x;
   new->y = y;
   new->next = NULL;
   if (q->rear == NULL)
      q->front = q->rear = new;
   else {
      q->rear->next = new;
      q->rear = new;
   }
}

void deQueue(Queue *q) {
   if (q->front == NULL)
      return;
   Node *temp = q->front;
   q->front = q->front->next;
   if (q->front == NULL)
      q->rear = NULL;
   free(temp);
}

void printPath(int x[], int y[], int n) {
   int i;
   for (i = 0; i < n; i++)
      printf("(%d,%d)->", x[i], y[i]);
   printf("(%d,%d)\n", x[n], y[n]);
}

void bfs(int maze[][5], int x1, int y1, int x2, int y2) {
   int i, j, found = 0, x, y, pos = 0;
   int dx[] = {-1, 0, 1, 0};
   int dy[] = {0, 1, 0, -1};
   int visited[5][5] = {0};
   int pathX[25], pathY[25];
   for (i = 0; i < 25; ++i) pathX[i] = -1, pathY[i] = -1;
   Queue *q = createQueue();
   enQueue(q, x1, y1);
   visited[x1][y1] = 1;
   while (q->front != NULL) {
      x = q->front->x;
      y = q->front->y;
      deQueue(q);
      pathX[pos] = x;
      pathY[pos] = y;
      pos++;
      if (x == x2 && y == y2) {
         found = 1;
         break;
      }
      for (i = 0; i < 4; i++) {
         int nx = x + dx[i], ny = y + dy[i];
         if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
         if (visited[nx][ny] || maze[nx][ny] == 0)
            continue;
         enQueue(q, nx, ny);
         visited[nx][ny] = 1;
      }
   }
   if (found)
      printPath(pathX, pathY, pos-1);
   else
      printf("No path found!\n");
}

int main() {
   int maze[5][5] = {{1, 1, 0, 1, 1},
                     {1, 0, 1, 1, 0},
                     {1, 0, 1, 0, 1},
                     {1, 0, 1, 1, 1},
                     {1, 1, 1, 0, 1}};
   printf("Shortest path from (0, 0) to (4, 4):\n");
   bfs(maze, 0, 0, 4, 4);
   return 0;
}