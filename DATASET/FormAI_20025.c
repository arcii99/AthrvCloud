//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100 /* maximum number of vertices */
#define MAXDEGREE 50 /* maximum vertex degree */

typedef struct {
  int edges[MAXV+1][MAXDEGREE]; /* adjacency info */
  int degree[MAXV+1];           /* outdegree of each vertex */
  int color[MAXV+1];            /* assigned color */
  int num_vertices;             /* number of vertices in graph */
  int num_edges;                /* number of edges in graph */
} graph;

int main() {
  graph g;
  int i,j,k;
  int color_ok;

  /* read in the graph */
  scanf("%d %d",&(g.num_vertices),&(g.num_edges));
  for (i=1; i<=g.num_vertices; i++) {
    g.degree[i] = 0;
    g.color[i] = 0;
  }
  
  for (i=0; i<g.num_edges; i++) {
    scanf("%d %d",&j,&k);
    g.edges[j][g.degree[j]++] = k;
    g.edges[k][g.degree[k]++] = j;
  }

  /* color the vertices */
  for (i=1; i<=g.num_vertices; i++) {
    color_ok = 1;
    /* check the colors of the adjacent vertices */
    for (j=0; j<g.degree[i]; j++) {
      if (g.color[g.edges[i][j]] == g.color[i]) {
        color_ok = 0;
        break;
      }
    }
    /* assign the first legal color */
    if (color_ok) {
      g.color[i] = 1;
    } else {
      g.color[i] = 2;
    }
  }

  /* print out the results */
  for (i=1; i<=g.num_vertices; i++) {
    printf(" Vertex %2d: color %d\n",i,g.color[i]);
  }

  return 0;
}