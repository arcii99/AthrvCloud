//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the HappyGeometrics program!\n");
  printf("Let's calculate the area of a triangle with our cheerful algorithm!\n");

  int base, height;
  printf("Please enter the length of the base: ");
  scanf("%d", &base);

  printf("Please enter the height: ");
  scanf("%d", &height);

  int area = (base * height) / 2;
  printf("\nThe area of the triangle is: %d\n", area);

  printf("\nHooray! We did it! Let's calculate the circumference of a circle!\n");

  float radius, pi;
  pi = 3.14159;
  
  printf("Please input the radius of the circle: ");
  scanf("%f", &radius);

  float circumference = 2 * pi * radius;
  printf("\nThe circumference of the circle is: %.2f\n", circumference);

  printf("\nAmazing! We did it again! Let's calculate the surface of a sphere next!\n");

  int sphereRadius;
  printf("Please input the radius of the sphere: ");
  scanf("%d", &sphereRadius);

  float sphereSurface = 4 * pi * (sphereRadius * sphereRadius);
  printf("\nThe surface of the sphere is: %.2f\n", sphereSurface);

  printf("\nYay! Three calculations and three successes! The HappyGeometrics program is awesome!\n");

  return 0;
}