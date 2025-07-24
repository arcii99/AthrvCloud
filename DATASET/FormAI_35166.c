//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

int main() {
  printf("Enter the length and width of the rectangle: ");
  
  int length;
  int width;
  
  scanf("%d %d", &length, &width);
  
  int perimeter = 2 * (length + width);
  int area = length * width;
  
  printf("Perimeter of the rectangle is: %d\n", perimeter);
  printf("Area of the rectangle is: %d\n", area);
  
  if (area > 100) {
    printf("This is a large rectangle!\n");
  } else {
    printf("This is a small rectangle!\n");
  }
  
  int rows;
  int columns;
  
  printf("How many rows and columns should the rectangle have: ");
  
  scanf("%d %d", &rows, &columns);
  
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= columns; j++) {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}