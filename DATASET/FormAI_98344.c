//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10
#define INF 99999

int graph[ROW][COL];
int visited[ROW];
int parent[ROW];
int distance[ROW];

void dijkstra(int start, int end)
{
  // initialize visited, parent, and distance arrays
  for(int i = 0; i < ROW; i++)
  {
    visited[i] = 0;
    parent[i] = -1;
    distance[i] = INF;
  }

  distance[start] = 0;

  // find shortest path
  for(int i = 0; i < ROW-1; i++)
  {
    int min = INF;
    int minIndex;

    // find vertex with minimum distance
    for(int j = 0; j < ROW; j++)
    {
      if(visited[j] == 0 && distance[j] < min)
      {
        min = distance[j];
        minIndex = j;
      }
    }

    // mark vertex as visited
    visited[minIndex] = 1;

    // update distances
    for(int j = 0; j < ROW; j++)
    {
      if(graph[minIndex][j] != 0 && visited[j] == 0 && distance[minIndex] + graph[minIndex][j] < distance[j])
      {
        distance[j] = distance[minIndex] + graph[minIndex][j];
        parent[j] = minIndex;
      }
    }
  }

  int path[ROW];
  int pathLength = 0;

  // build path from end to start
  int currentVertex = end;
  while(currentVertex != start)
  {
    path[pathLength++] = currentVertex;
    currentVertex = parent[currentVertex];
  }
  path[pathLength++] = start;

  // print shortest path
  printf("Shortest path from vertex %d to vertex %d:\n", start, end);
  for(int i = pathLength-1; i >= 0; i--)
  {
    printf("%d ", path[i]);
  }
  printf("\nShortest distance: %d\n", distance[end]);
}

int main()
{
  // initialize graph
  for(int i = 0; i < ROW; i++)
  {
    for(int j = 0; j < COL; j++)
    {
      graph[i][j] = 0;
    }
  }
  graph[0][1] = 5;
  graph[0][3] = 9;
  graph[0][4] = 2;
  graph[1][2] = 2;
  graph[1][3] = 6;
  graph[2][8] = 9;
  graph[3][2] = 3;
  graph[3][4] = 2;
  graph[4][5] = 3;
  graph[4][6] = 5;
  graph[5][6] = 4;
  graph[5][7] = 4;
  graph[5][8] = 5;
  graph[6][7] = 6;
  graph[7][8] = 2;

  dijkstra(0,8);

  return 0;
}