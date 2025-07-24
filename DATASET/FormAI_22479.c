//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

float heron(float a, float b, float c);

int main() {
  float side1, side2, side3, area;
  
  printf("Enter the length of side 1: ");
  scanf("%f", &side1);
  
  printf("Enter the length of side 2: ");
  scanf("%f", &side2);
  
  printf("Enter the length of side 3: ");
  scanf("%f", &side3);
  
  area = heron(side1, side2, side3);
  
  printf("The area of the triangle is: %.2f\n", area);
  
  return 0;
}

float heron(float a, float b, float c) {
  float s, area;
  
  s = (a + b + c) / 2;
  
  area = sqrt(s * (s - a) * (s - b) * (s - c));
  
  return area;
}