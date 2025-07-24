//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 20

// Function to print banana at the specified coordinates
void printBanana(int x, int y) {
  printf("\033[%d;%dH", y, x);
  printf(".-'\"\"`-.\n"); 
  printf(",' _   e )`-._\n");
  printf("/ ,' `-._O)  _ \\\n");
  printf("\\(c  ,   `-._(_)\n");
  printf(" \\ '`) sc    ) /\n");
  printf("  `-._.-._   /\n");
  printf("         `-'\n"); 
}

int main() {
  char graph[HEIGHT][WIDTH]; // Our banana graph
  int i, j;

  // Initialize graph to blank spaces
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      graph[i][j] = ' ';
    }
  }

  // Add some bananas!
  graph[2][5] = 'B';
  graph[3][6] = 'A';
  graph[4][7] = 'N';
  graph[5][8] = 'A';
  graph[6][9] = 'N';
  graph[7][10] = 'A';

  // Print the graph!
  system("clear"); // Clear terminal window
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (graph[i][j] == 'B') { // If there's a banana, print it!
        printBanana(j, i);
      } else { // Otherwise, print a blank space
        printf(" ");
      }
    }
    printf("\n"); // Move to the next row
  }

  return 0;
}