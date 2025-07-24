//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>

int main() {

  int len, width;
  printf("Enter the length and width of the rectangle: ");
  scanf("%d %d", &len, &width);

  int area = len * width;
  int perimeter = 2*len + 2*width;

  printf("The area of the rectangle is: %d\n", area);
  printf("The perimeter of the rectangle is: %d\n", perimeter);

  int i, j;
  for (i = 0; i < width; i++) {
    for (j = 0; j < len; j++) {
      if (i == 0 || i == width-1 || j == 0 || j == len-1) {
        printf("*");
      } else if (i == j) {
        printf("\\");
      } else if (i == width-1-j) {
        printf("/");
      } else if (i % 2 == 0 && j % 2 == 0) {
        printf("+");
      } else if (i % 2 == 0 || j % 2 == 0) {
        printf("-");
      } else {
        printf(".");
      }
      printf(" ");
    }
    printf("\n");
  }

  return 0;
}