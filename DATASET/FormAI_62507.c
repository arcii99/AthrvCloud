//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

//Our Recursive function
void countdown(int num) {
  printf("%d...\n", num);
  if(num == 0) {
    printf("Blastoff!\n");
    return;
  }
  countdown(num - 1);
}

int main() {
  printf("Get ready for takeoff!\n");
  countdown(5);
  printf("We have liftoff!\n");
  return 0;
}