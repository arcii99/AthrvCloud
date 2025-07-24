//FormAI DATASET v1.0 Category: Bitwise operations ; Style: romantic
#include <stdio.h>

int main() {
  int x = 110;
  int y = 3;
  int z = x ^ y; // XOR operation
  
  printf("You are %d years old\n", x);
  printf("I am %d years old\n", y);
  printf("Our love is %d years old\n", z);
  
  if (z == 109) {
    printf("I am sorry, our love is not old enough yet.\n");
  } else if (z > 100 && z < 120) {
    printf("Our love is strong and vibrant!\n");
  } else if (z <= 100) {
    printf("Our love is young and fresh!\n");
  } else {
    printf("Our love is eternal!\n");
  }

  return 0;
}