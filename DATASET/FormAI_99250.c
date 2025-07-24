//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h> // Required header file for I/O operations

int main() {
  printf("Hello there! I'm a graph representation program written in C language.\n");
  printf("Let's create a graph display using asterisks (*), edges, and vertices!\n\n");

  printf("      *        \n");
  printf("     / \\       \n");
  printf("    *   *      \n");
  printf("   /     \\     \n");
  printf("  *-------*    \n\n"); // A simple graph display with 2 vertices and 1 edge

  printf("Now, let's create a function that generates different graph displays!\n"); 
  //This function takes in the number of vertices and edges as arguments and prints the graph accordingly
  void createGraph(int vertices, int edges) {
    if(edges > vertices*(vertices-1)/2) { //Checking if the number of edges are greater than the maximum possible edges for the given vertices
        printf("\nThis graph is not possible with %d vertices and %d edges\n\n", vertices, edges);
        return;
    }

    int i, j;
    printf("\n");

    for(i=1; i<=vertices; i++){
        printf("   *");
        for(j=2; j<=i; j++){
            printf("-");
        }
        if(i<vertices){
            printf("\n");
            printf("   |");
        }
        printf("\n");
    }

    for(i=1; i<=edges; i++){
        if(i%2 == 1){
            printf("     \\");
        }else{
            printf("       \\");
        }
        if(i%2 == 1){
            for(j=1; j<=vertices/2; j++){
                printf(" ");
            }
        }else{
            for(j=vertices/2+1; j<vertices; j++){
                printf(" ");
            }
        }
        printf("/\n");
    }
    printf("\n");
  }

  printf("Great! We've just created a function to generate a graph display.\n\n");

  printf("Now, let's test the function with different parameters!\n");
  printf("Example 1: A graph display with 4 vertices and 3 edges\n");
  createGraph(4, 3);

  printf("Example 2: A graph display with 5 vertices and 7 edges\n");
  createGraph(5, 7);

  printf("Example 3: A graph display with 6 vertices and 10 edges\n");
  createGraph(6, 10);

  return 0;
}