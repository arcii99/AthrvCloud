//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
This program uses a unique geometric algorithm to check if a given point lies inside or on the perimeter of a circle. 
The algorithm takes the coordinates of the point (x, y) and the coordinates of the center of the circle (a, b) as input.
It then utilizes the Pythagorean theorem to calculate the distance between the point and the center of the circle.
If this distance is less than or equal to the radius of the circle, the point lies within the circle.

*/

int main() {
  float x, y, a, b, radius, distance;

  printf("Enter the coordinates of the center of the circle: \n");
  scanf("%f %f", &a, &b);

  printf("Enter the radius of the circle: \n");
  scanf("%f", &radius);

  printf("Enter the coordinates of the point: \n");
  scanf("%f %f", &x, &y);

  //Calculate the distance between the point and the center of the circle using Pythagorean theorem
  distance = sqrt(pow((x - a), 2) + pow((y - b), 2));

  // Check if point lies within or on the perimeter of the circle
  if(distance <= radius){
    printf("The point (%0.2f, %0.2f) lies inside or on the perimeter of the circle with center (%0.2f, %0.2f) and radius %0.2f\n", x, y, a, b, radius);
  } else {
    printf("The point (%0.2f, %0.2f) lies outside the circle with center (%0.2f, %0.2f) and radius %0.2f\n", x, y, a, b, radius);
  }

  return 0;
}