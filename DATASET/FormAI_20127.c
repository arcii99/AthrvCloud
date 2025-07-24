//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <math.h>

int main() {

  printf("Welcome to my funny Geometric Algorithm program!\n");
  
  // Let's calculate the area of a circle with a radius of 5
  float radius = 5;
  float area = M_PI * pow(radius, 2);
  
  printf("The area of a circle with a radius of 5 is %f\n", area);
  
  // Now let's calculate the perimeter of a triangle with sides 3, 4, and 5
  float side1 = 3;
  float side2 = 4;
  float side3 = 5;
  
  if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) {
    float perimeter = side1 + side2 + side3;
    printf("The perimeter of the triangle is %f\n", perimeter);
  } else {
    printf("Sorry, that's not a valid triangle. Let's try again.\n");
  }
  
  // Finally, let's calculate the volume of a sphere with a radius of 7
  float sphereRadius = 7;
  float sphereVolume = (4.0/3.0) * M_PI * pow(sphereRadius, 3);
  
  printf("The volume of a sphere with a radius of 7 is %f\n", sphereVolume);
  
  printf("I hope you enjoyed my funny Geometric Algorithm program. Now go forth and calculate some shapes!\n");
  
  return 0;
}