//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){
  
  printf("Welcome to the Geometric algorithms example program!\n");
  printf("This program will calculate the area of a triangle given its three sides using Heron's formula.\n");

  float side1, side2, side3, s, area;
  
  printf("Enter the first side: ");
  scanf("%f", &side1);
  
  printf("Enter the second side: ");
  scanf("%f", &side2);
  
  printf("Enter the third side: ");
  scanf("%f", &side3);

  //calculate the semi-perimeter and area of the triangle
  s = (side1+side2+side3)/2;
  area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

  printf("The area of the triangle is: %.2f\n", area);
  
  return 0;
}