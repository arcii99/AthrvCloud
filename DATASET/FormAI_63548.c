//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>

// Function to calculate the area of a rectangle
int rectangle_area(int length, int width) {
  return length * width;
}

// Function to calculate the perimeter of a rectangle
int rectangle_perimeter(int length, int width) {
  return 2 * (length + width);
}

// Main function
int main() {
  printf("Welcome to the Rectangle Calculator!\n");

  int length, width;
  printf("Enter the length of your rectangle: ");
  scanf("%d", &length);
  printf("Enter the width of your rectangle: ");
  scanf("%d", &width);

  int area = rectangle_area(length, width);
  int perimeter = rectangle_perimeter(length, width);

  printf("The area of your rectangle is: %d\n", area);
  printf("The perimeter of your rectangle is: %d\n", perimeter);

  return 0;
}