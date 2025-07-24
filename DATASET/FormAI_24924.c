//FormAI DATASET v1.0 Category: Scientific ; Style: content
#include <stdio.h>

/* Program to find the sum of the elements of an array */

int main() {
  int array[10], i, sum = 0;
  
  printf("Enter 10 integers: \n");
  
  for (i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }
  
  for (i = 0; i < 10; i++) {
    sum += array[i];
  }
  
  printf("The sum of the elements is: %d\n", sum);
  
  return 0;
}