//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>

int main() {
  int choice;
  float radius, length, width, area, perimeter;
  
  printf("Choose a shape:\n");
  printf("1. Circle\n");
  printf("2. Rectangle\n");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("Enter the radius of the circle: ");
      scanf("%f", &radius);
      
      area = 3.14 * radius * radius;
      perimeter = 2 * 3.14 * radius;
      
      printf("The area of the circle is %.2f and the perimeter is %.2f.\n", area, perimeter);
      break;
      
    case 2:
      printf("Enter the length of the rectangle: ");
      scanf("%f", &length);
      
      printf("Enter the width of the rectangle: ");
      scanf("%f", &width);
      
      area = length * width;
      perimeter = 2 * (length + width);
      
      printf("The area of the rectangle is %.2f and the perimeter is %.2f.\n", area, perimeter);
      break;
      
    default:
      printf("Invalid choice.\n");
  }
  
  return 0;
}