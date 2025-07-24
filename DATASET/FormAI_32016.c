//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multivariable
#include <stdio.h>

int main() {
  int x, y, z;
  printf("Enter the value of x: ");
  scanf("%d", &x);
  printf("Enter the value of y: ");
  scanf("%d", &y);
  printf("Enter the value of z: ");
  scanf("%d", &z);
  
  int sum = x + y + z;
  float average = sum / 3.0;
  
  printf("Sum of x, y, and z is: %d\n", sum);
  printf("Average of x, y, and z is: %.2f\n", average);
  
  if(x > y) {
    if(x > z) {
      printf("x is the largest number\n");
    } else {
      printf("z is the largest number\n");
    }
  } else {
    if(y > z) {
      printf("y is the largest number\n");
    } else {
      printf("z is the largest number\n");
    }
  }
  
  return 0;
}