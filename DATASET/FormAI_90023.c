//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed random number generator
  srand(time(NULL));
  
  // Generate two random integers
  int a = rand() % 100;
  int b = rand() % 100;
  
  // Print the two random integers
  printf("a = %d, b = %d\n", a, b);
  
  // Calculate the distance between the two points
  double distance = sqrt(pow(a, 2) + pow(b, 2));
  
  // Print the distance
  printf("The distance between the two points is: %lf\n", distance);
  
  // Generate a random angle in degrees
  int angle = rand() % 360;
  
  // Convert the angle to radians
  double angle_rad = angle * M_PI / 180;
  
  // Calculate the sine and cosine of the angle
  double sine = sin(angle_rad);
  double cosine = cos(angle_rad);
  
  // Print the angle and its sine and cosine
  printf("The angle is: %d degrees\n", angle);
  printf("The sine of the angle is: %lf\n", sine);
  printf("The cosine of the angle is: %lf\n", cosine);
  
  // Generate another random angle in degrees
  int angle2 = rand() % 360;
  
  // Convert the angle to radians
  double angle2_rad = angle2 * M_PI / 180;
  
  // Calculate the tangent and cotangent of the angle
  double tangent = tan(angle2_rad);
  double cotangent = 1.0 / tan(angle2_rad);
  
  // Print the angle and its tangent and cotangent
  printf("The other angle is: %d degrees\n", angle2);
  printf("The tangent of the angle is: %lf\n", tangent);
  printf("The cotangent of the angle is: %lf\n", cotangent);
  
  return 0;
}