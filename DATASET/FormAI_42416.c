//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>

int main() {
  int rows, cols, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);
  
  int arr[rows][cols];
  
  printf("Enter the values for the array\n");
  
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      printf("Enter value for pixel [%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
  
  printf("\n");

  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      if(arr[i][j] == 1) {
        printf("X");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}