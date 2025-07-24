//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, y, z;
  float f;
  
  printf("Enter two integers: ");
  scanf("%d %d", &x, &y);
  
  printf("x + y = %d\n", x + y);
  printf("x - y = %d\n", x - y);
  printf("x * y = %d\n", x * y);
  
  if (y != 0) {
    printf("x / y = %d\n", x / y);
    f = (float)x / (float)y;
    printf("x / y (float) = %f\n", f);
  } else {
    printf("Cannot divide by zero.\n");
  }
  
  printf("Enter an integer: ");
  scanf("%d", &z);
  
  printf("x + y + z = %d\n", x + y + z);
  
  return 0;
}