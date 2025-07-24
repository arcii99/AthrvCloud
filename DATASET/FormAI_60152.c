//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>

int main() {
  int shape_choice;
  printf("Select the shape you want to calculate the area of:\n1. Circle\n2. Square\n3. Rectangle\n");
  scanf("%d", &shape_choice);
  
  switch (shape_choice) {
    case 1:
      float radius, area_circle;
      printf("Enter the radius of the circle: ");
      scanf("%f", &radius);
      area_circle = 3.14159 * radius * radius;
      printf("The area of the circle is: %f", area_circle);
      break;
    case 2:
      float side, area_square;
      printf("Enter the length of one side of the square: ");
      scanf("%f", &side);
      area_square = side * side;
      printf("The area of the square is: %f", area_square);
      break;
    case 3:
      float length, width, area_rectangle;
      printf("Enter the length of the rectangle: ");
      scanf("%f", &length);
      printf("Enter the width of the rectangle: ");
      scanf("%f", &width);
      area_rectangle = length * width;
      printf("The area of the rectangle is: %f", area_rectangle);
      break;
    default:
      printf("Invalid input, please try again.");
  }
  return 0;
}