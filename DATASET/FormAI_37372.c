//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: bold
#include <stdio.h>
#include <math.h>

/* This program calculates the area of a triangle given the length of its 3 sides using Heron's formula */

int main() {
  float a, b, c, s, area;
  
  printf("Enter the length of side a: ");
  scanf("%f", &a);
  
  printf("Enter the length of side b: ");
  scanf("%f", &b);
  
  printf("Enter the length of side c: ");
  scanf("%f", &c);
  
  // calculate the semi-perimeter of the triangle
  s = (a + b + c) / 2;
  
  // calculate the area of the triangle using Heron's formula
  area = sqrt(s*(s-a)*(s-b)*(s-c));
  
  printf("The area of the triangle is: %.2f", area);
  
  return 0;
}