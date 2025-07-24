//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
  float x, y, z, result;
  
  printf("Enter the value of x: ");
  scanf("%f", &x);
  
  printf("Enter the value of y: ");
  scanf("%f", &y);
  
  printf("Enter the value of z: ");
  scanf("%f", &z);
  
  result = (sqrt(pow(x, 3)) * pow(y, 2)) / (pow(z, 3/2));
  
  printf("The result is %f", result);
  
  return 0;
}