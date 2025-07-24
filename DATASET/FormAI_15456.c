//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: funny
#include <stdio.h>

int main()
{
  printf("Welcome to the funny pathfinding algorithm program!\n");
  printf("This algorithm helps a mouse find its way through a maze\n");

  // Let's create the maze
  int maze[5][5] = {
      {1, 0, 1, 1, 1},
      {1, 1, 0, 0, 1},
      {1, 0, 1, 0, 1},
      {1, 0, 0, 0, 1},
      {1, 1, 1, 1, 1}};

  int startX = 0;
  int startY = 0;
  int endX = 4;
  int endY = 4;

  printf("Here is the maze the mouse needs to pass through:\n");

  // Print the maze
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (maze[i][j] == 1)
      {
        printf("%c", 219);
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }

  // Let's find the path
  int queue[25][2];
  int front = -1;
  int rear = -1;
  int visited[5][5] = {0};
  int distance[5][5] = {0};
  int path[5][5] = {0};

  queue[++rear][0] = startX;
  queue[rear][1] = startY;
  visited[startX][startY] = 1;

  while (front != rear)
  {
    front++;
    int x = queue[front][0];
    int y = queue[front][1];

    if (x == endX && y == endY)
      break;

    if (x > 0 && maze[x - 1][y] == 1 && visited[x - 1][y] == 0)
    {
      queue[++rear][0] = x - 1;
      queue[rear][1] = y;
      visited[x - 1][y] = 1;
      distance[x - 1][y] = distance[x][y] + 1;
      path[x - 1][y] = front;
    }
    if (x < 4 && maze[x + 1][y] == 1 && visited[x + 1][y] == 0)
    {
      queue[++rear][0] = x + 1;
      queue[rear][1] = y;
      visited[x + 1][y] = 1;
      distance[x + 1][y] = distance[x][y] + 1;
      path[x + 1][y] = front;
    }
    if (y > 0 && maze[x][y - 1] == 1 && visited[x][y - 1] == 0)
    {
      queue[++rear][0] = x;
      queue[rear][1] = y - 1;
      visited[x][y - 1] = 1;
      distance[x][y - 1] = distance[x][y] + 1;
      path[x][y - 1] = front;
    }
    if (y < 4 && maze[x][y + 1] == 1 && visited[x][y + 1] == 0)
    {
      queue[++rear][0] = x;
      queue[rear][1] = y + 1;
      visited[x][y + 1] = 1;
      distance[x][y + 1] = distance[x][y] + 1;
      path[x][y + 1] = front;
    }
  }

  if (visited[endX][endY] == 0)
  {
    printf("\nSorry, the mouse could not find its way through the maze...\n");
  }
  else
  {
    printf("\nCongratulations! The mouse found its way through the maze in %d steps!\n", distance[endX][endY]);

    // Let's print the path
    int row = endX;
    int col = endY;
    int p = path[row][col];
    while (p != -1)
    {
      int t = queue[p][0];
      col = queue[p][1];
      row = t;
      p = path[row][col];
      maze[row][col] = 2;
    }

    printf("\nHere is the path:\n");
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if (maze[i][j] == 1)
        {
          printf("%c", 219);
        }
        else if (maze[i][j] == 2)
        {
          printf("*");
        }
        else
        {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  return 0;
}