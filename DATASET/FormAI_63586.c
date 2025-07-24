//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>

int main() {
  printf("Wait, what? A C graph representation program example?!\n");
  printf("Is this real life or is this just fantasy?\n\n");

  printf("Okay, let's buckle up and get to it.\n");
  printf("First, we need to declare the number of vertices: \n");
  
  int vertices = 5;
  printf("int vertices = %d;\n", vertices);

  printf("\nNow, let's declare the adjacency matrix:\n");

  int adj_matrix[vertices][vertices];
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  printf("\nint adj_matrix[%d][%d] = {\n", vertices, vertices);
  for (int i = 0; i < vertices; i++) {
    printf("  {");
    for (int j = 0; j < vertices; j++) {
      printf("%d", adj_matrix[i][j]);
      if (j != vertices - 1) {
        printf(", ");
      }
    }
    printf("}");
    if (i != vertices - 1) {
      printf(",");
    }
    printf("\n");
  }
  printf("};\n");

  printf("\nWow, we have our very own adjacency matrix!\n");
  printf("Now let's add some edges:\n");

  adj_matrix[0][1] = 1;
  adj_matrix[0][2] = 1;
  adj_matrix[1][0] = 1;
  adj_matrix[1][3] = 1;
  adj_matrix[2][0] = 1;
  adj_matrix[2][3] = 1;
  adj_matrix[3][1] = 1;
  adj_matrix[3][2] = 1;
  adj_matrix[3][4] = 1;
  adj_matrix[4][3] = 1;

  printf("\nint adj_matrix[%d][%d] = {\n", vertices, vertices);
  for (int i = 0; i < vertices; i++) {
    printf("  {");
    for (int j = 0; j < vertices; j++) {
      printf("%d", adj_matrix[i][j]);
      if (j != vertices - 1) {
        printf(", ");
      }
    }
    printf("}");
    if (i != vertices - 1) {
      printf(",");
    }
    printf("\n");
  }
  printf("};\n");

  printf("\nHoly moly, we have a graph!\n");
  printf("Our graph has %d vertices and looks like this:\n\n", vertices);

  printf("    1 -- 2  \n");
  printf("   /     |  \n");
  printf("  0      3  \n");
  printf("        /   \n");
  printf("       4    \n");

  printf("\nYes, I know it's not exactly like the adjacency matrix.\n");
  printf("But come on, I needed some creativity here.\n");
  printf("And anyway, you get the idea, right?\n");

  return 0;
}