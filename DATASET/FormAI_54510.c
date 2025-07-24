//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include<stdio.h> 

void drawLine(int n, char c) {
  for(int i=0; i<n; i++) 
    printf("%c", c);
  printf("\n");
}

int main() {
  int n, m;
  printf("Welcome to the Graph-o-matic!\n");
  printf("Enter the number of horizontal lines: ");
  scanf("%d", &n);
  printf("Enter the number of vertical lines: ");
  scanf("%d", &m);

  printf("Your graph is ready:\n");

  for(int i=0; i<n; i++) {
    drawLine(m, '|');
  }

  drawLine(m*(n+2), '-');

  int x = n*m;
  printf("Your graph is worth approximately $%d\n", x);

  return 0;
}