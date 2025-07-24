//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#define MAX_ANGLE 360

int main() {
  int sides, radius, i, j;
  double angle, x, y;

  printf("Enter number of sides: ");
  scanf("%d", &sides);
  
  printf("Enter radius: ");
  scanf("%d", &radius);
  
  for (i = 0; i < MAX_ANGLE; i++) {
    angle = i * 3.14159 / 180;
    x = radius * cos(angle);
    y = radius * sin(angle);
    
    for (j = 0; j < sides; j++) {
      printf("(%d, %d) ", (int)(x + radius * cos(angle + j * 2 * 3.14159 / sides)), (int)(y + radius * sin(angle + j * 2 * 3.14159 / sides)));
    }
    printf("\n");
  }
  
  return 0;
}