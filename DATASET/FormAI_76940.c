//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello there, I'm a graph!\n");
  printf("My vertices are as follows:\n");
  
  //Creating graph vertex names
  char vertex1 = 'A';
  char vertex2 = 'B';
  char vertex3 = 'C';
  char vertex4 = 'D';

  printf("%c, %c, %c, %c\n", vertex1, vertex2, vertex3, vertex4);

  // Creating the graph edges
  printf("Now it's time to connect these vertices!\n");
  int adj_mtx[4][4] = {
      {0, 1, 1, 0},
      {1, 0, 1, 1},
      {1, 1, 0, 0},
      {0, 1, 0, 0}
  };
  printf("This is my adjacency matrix:\n");

  //Printing the adjacency matrix
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", adj_mtx[i][j]);
    }
    printf("\n");
  }
  printf("As you can see, my edges are represented by 1's in my adjacency matrix!\n");
  printf("It looks like my graph is connected, but let's make sure...\n");

  //Checking if graph is connected
  for (int i = 0; i < 4; i++) {
    int connected = 0;
    for (int j = 0; j < 4; j++) {
      if (adj_mtx[i][j] == 1) {
        connected++;
      }
    }
    if (connected == 0) {
      printf("Oh no! Vertex %c is not connected to any other vertices!\n", 'A' + i);
    }
  }

  printf("Phew! It looks like my graph is connected after all!\n");
  printf("Thanks for checking out my graph! See you later!\n");

  return 0;
}