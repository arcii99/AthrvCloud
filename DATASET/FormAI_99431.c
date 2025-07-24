//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
// Energy Recursion program
#include <stdio.h>

int count(int n) {
  if (n == 0) {
    printf("Boom!\n");  // display the message
    return 0;
  } else {
    printf("%d..\n", n);
    return count(n-1);  // recursive call
  }
}

int main() {
  printf("Energy countdown program\n");
  count(10); // starting number
  return 0;
}