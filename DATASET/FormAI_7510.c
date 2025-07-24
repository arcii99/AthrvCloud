//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>

int main() {

  //initialize the necessary variables
  int rows, columns;

  //prompt the user to enter rows and columns of the graph
  printf("Enter the number of rows for your graph:\n");
  scanf("%d", &rows);
  printf("Enter the number of columns for your graph:\n");
  scanf("%d", &columns);

  //initialize the graph array with zeros
  int graph[rows][columns];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      graph[i][j] = 0;
    }
  }

  //let's create some crazy curves on the graph
  for (int i = 0; i < columns; i++) {
    int y1 = i / 2;
    int y2 = 2 * i % rows;
    int y3 = rows - i / 2;
    graph[y1][i] = 1;
    graph[y2][i] = 1;
    graph[y3][i] = 1;
  }

  //output the graph
  printf("\n    YOUR UNIQUE C GRAPH REPRESENTATION:\n\n");
  for(int i = 0; i<rows; i++){
    for(int j = 0; j<columns; j++){
      if(graph[i][j] == 1) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}