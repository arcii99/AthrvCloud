//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
#include<stdio.h>

int main(){
  int n, i, j;
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &n);
  int graph[n][n];
  printf("Enter the Matrix:\n");
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      scanf("%d", &graph[i][j]);
    }
  }
  printf("\n\n  ____       _____");
  printf("\n /  __ \\    /  ___|");
  printf("\n|  /    |  |  |");
  printf("\n|  |    |  |  \\_____ ");
  printf("\n|  \\__/ |   \\_____  \\ ");
  printf("\n \\_____/   ________/");
  printf("\n\nThis is your graph's medial representation:\n\n");
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(graph[j][i]==1){
        printf("|__");
      }
      else{
        printf("|  ");
      }
    }
    printf("|\n");
  }
  printf("\n\n  ____       _____");
  printf("\n /  __ \\    /  ___|");
  printf("\n|  /    |  |  |");
  printf("\n|  | __ |  |  \\----.");
  printf("\n|  \\__/ |   \\_____  \\");
  printf("\n \\_____/         \\__|");
  printf("\n\nAll the best for your medieval graph calculations!\n");
  return 0;
}