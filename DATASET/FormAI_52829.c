//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
  int x = 10;
  printf("The original value of x is %d\n", x);
  
  // Adding 5 to x
  x += 5;
  printf("After adding 5, x is now %d\n", x);

  // Subtracting 2 from x
  x -= 2;
  printf("After subtracting 2, x is now %d\n", x);

  // Multipling x by 3
  x *= 3;
  printf("After multiplying with 3, x is now %d\n", x);

  // Dividing x by 4
  x /= 4;
  printf("After dividing by 4, x is now %d\n", x);

  // Finding the remainder when x is divided by 3
  int remainder = x % 3;
  printf("The remainder when x is divided by 3 is %d\n", remainder);

  // Incrementing x by 1
  x++;
  printf("After incrementing by 1, x is now %d\n", x);

  // Decrementing x by 1
  x--;
  printf("After decrementing by 1, x is now %d\n", x);

  return 0;
}