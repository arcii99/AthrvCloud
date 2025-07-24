//FormAI DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void recursive_func(int num) {
  if(num == 0) {
    printf("Paranoia is not always a bad thing!\n");
  } else {
    printf("Do not trust anyone!\n");
    recursive_func(num-1);
  }
}

int main() {
  int num_of_calls = 10;
  printf("You are being watched!\n");
  recursive_func(num_of_calls);
  printf("Stay vigilant!\n");
  return 0;
}