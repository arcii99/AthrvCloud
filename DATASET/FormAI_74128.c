//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

int main() {
  printf("Welcome to the Graph World!\n\n");
  int N = 5;
  int graph[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = -1;
      }
    }
  }

  graph[0][1] = 5;
  graph[0][3] = 8;
  graph[1][0] = 5;
  graph[1][2] = 3;
  graph[2][1] = 3;
  graph[3][0] = 8;
  graph[3][4] = 2;
  graph[4][3] = 2;

  printf("    0   1   2   3   4\n");
  printf("---------------------\n");
  for (int i = 0; i < N; i++) {
    printf("%d | ", i);
    for (int j = 0; j < N; j++) {
      if (graph[i][j] == -1) {
        printf(".   ");
      } else {
        printf("%d   ", graph[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}