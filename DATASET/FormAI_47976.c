//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>
#include<math.h>

int main() {
  double radius;
  double circle_area;
  double sphere_volume;
  const double pi = 3.14159265358979323846; // Define pi value
  
  printf("Enter the radius of the circle and sphere: ");
  scanf("%lf", &radius);
  
  // Calculate the area of the circle
  circle_area = pi * pow(radius, 2);
  
  // Calculate the volume of the sphere
  sphere_volume = (4.0 / 3.0) * pi * pow(radius, 3);
  
  printf("The area of the circle is: %.2lf\n", circle_area);
  printf("The volume of the sphere is: %.2lf\n", sphere_volume);
  
  return 0;
}