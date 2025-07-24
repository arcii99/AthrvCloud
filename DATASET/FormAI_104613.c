//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int main() {
  int a, b, c;
  
  printf("Welcome to the Visionary Calculator\n");
  printf("Please enter the first number: ");
  scanf("%d", &a);
  printf("Please enter the second number: ");
  scanf("%d", &b);
  
  printf("\nCalculating.....\n");
  
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  
  c = a - b;
  printf("Difference of %d and %d is %d\n", a, b, c);
  
  c = a * b;
  printf("Multiplication of %d and %d is %d\n", a, b, c);
  
  if (b != 0) {
    float d = (float)a / (float)b;
    printf("Division of %d and %d is %f\n", a, b, d);
  } else {
    printf("Division of %d and %d is undefined\n", a, b);
  }
  
  printf("\nThanks for using the Visionary Calculator\n");
  printf("Press any key to exit...");
  
  getchar();
  return 0;
}