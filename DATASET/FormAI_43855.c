//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>

int main() {

  int width, height;
  printf("Enter the width : ");
  scanf("%d", &width);
  printf("Enter the height : ");
  scanf("%d", &height);

  int area = width * height;
  int perimeter = 2 * (width + height);

  printf("Area of the rectangle is : %d\n", area);
  printf("Perimeter of the rectangle is : %d\n", perimeter);

  return 0;
}