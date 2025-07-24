//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
#include <stdio.h>

int main() {
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= cols; j++) {
      if(i == 1 || i == rows || j == 1 || j == cols) {
        printf("*");
      } else if(i % 2 == 0) {
        printf("-");
      } else {
        printf("+");
      }
    }
    printf("\n");
  }
  
  return 0;
}