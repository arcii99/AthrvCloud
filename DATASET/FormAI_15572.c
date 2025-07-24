//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

int main() {

  int a, b, c, d, result;
 
  printf("Let's do some math!\n");
  printf("Please enter the first number: ");
  scanf("%d", &a);
  printf("Please enter the second number: ");
  scanf("%d", &b);
  printf("Please enter the third number: ");
  scanf("%d", &c);
  printf("Please enter the fourth number: ");
  scanf("%d", &d);

  result = (a + b) * (c - d);
  
  printf("The result is: %d\n", result);
  printf("Wow, that was a fun calculation!\n");

  return 0;
}