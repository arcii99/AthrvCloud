//FormAI DATASET v1.0 Category: Funny ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int x = 2;
  int y = 3;
  int z = 5;
  printf("Welcome to the Amazing Math Bot!\n");
  printf("Let's do some calculations...\n\n");
  
  printf("First, let's add %d and %d. Answer: %d\n", x, y, x + y);
  printf("Now let's multiply %d and %d. Answer: %d\n", y, z, y * z);
  printf("Here's something tricky, let's divide %d by %d and cast the result to a float. Answer: %.2f\n", x, y, (float) x / y);
  printf("Let's subtract %d from %d and add %d. Answer: %d\n", z, y, x, z - y + x);
  
  printf("\nThanks for using the Amazing Math Bot! Goodbye.\n");
  return 0;
}