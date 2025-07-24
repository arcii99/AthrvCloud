//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include<stdio.h>
#include<math.h>

int main(){
  double radius, circumference, area;
  const double PI = 3.14159;

  printf("Enter the radius of the circle: ");
  scanf("%lf", &radius);

  //Calculating the circumference of the circle
  circumference = 2 * PI * radius;

  //Calculating the area of the circle
  area = PI * pow(radius, 2);

  printf("The circumference of the circle is: %lf\n", circumference);
  printf("The area of the circle is: %lf\n", area);

  return 0;
}