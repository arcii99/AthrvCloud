//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
  int sides = 3;
  float radius = 10.0;
  float pi = 3.14;
  float side_length = 2 * radius * sin(pi/sides);
  float area = sides * pow(side_length, 2) / (4 * tan(pi/sides));
  printf("Regular polygon with %d sides has side length %.2f and area %.2f\n", sides, side_length, area);
  
  // Shape shifting - changing sides to 4 and recalculating side length and area
  sides = 4;
  side_length = 2 * radius * sin(pi/sides);
  area = sides * pow(side_length, 2) / (4 * tan(pi/sides));
  printf("Regular polygon with %d sides has side length %.2f and area %.2f\n", sides, side_length, area);
  
  // Shape shifting - changing radius to 5 and recalculating side length and area
  radius = 5.0;
  side_length = 2 * radius * sin(pi/sides);
  area = sides * pow(side_length, 2) / (4 * tan(pi/sides));
  printf("Regular polygon with %d sides has side length %.2f and area %.2f\n", sides, side_length, area);
  
  return 0;
}