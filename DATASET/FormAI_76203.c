//FormAI DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>

int main() {
  /*
  This program generates a mind-bending representation of a directed graph using ASCII characters.
  Each node is represented by a letter and is connected to other nodes with arrows.
  The direction of the arrow depends on the relationship between nodes, as follows:
  - Arrow pointing up: child node
  - Arrow pointing down: parent node
  - Arrow pointing right: next node in the same level (sibling)
  */

  // Define the nodes and their relationships
  char root = 'A';
  char a = 'B';
  char b = 'C';
  char c = 'D';
  char d = 'E';
  char e = 'F';

  // Generate the graph representation
  printf("      %c\n", root);
  printf("       |\n");
  printf("       v\n");
  printf("      %c\n", a);
  printf("       |\n");
  printf("       v\n");
  printf("      %c\n", b);
  printf("       |\n");
  printf("       v\n");
  printf("      %c\n", c);
  printf("       |\n");
  printf("       v\n");
  printf("      %c\n", d);
  printf("       |\n");
  printf("       v\n");
  printf("      %c\n", e);

  return 0;
}