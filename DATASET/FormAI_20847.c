//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>

int main() {
  int length, width, area, perimeter;
  
  printf("Greetings, adventurer! Today we will be calculating the area and perimeter of your rectangular treasure chest.\n");
  printf("Please enter the length of the chest in meters: ");
  scanf("%d", &length);

  printf("Excellent! And now the width in meters, if you please: ");
  scanf("%d", &width);

  area = length * width;
  perimeter = 2 * (length + width);

  printf("Fantastic work, adventurer! The area of your treasure chest is %d square meters and the perimeter is %d meters.\n", area, perimeter);

  return 0;
}