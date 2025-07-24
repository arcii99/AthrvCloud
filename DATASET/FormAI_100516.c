//FormAI DATASET v1.0 Category: Random ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("I can't believe it! I just generated a random number using C!\n");
  srand(time(0));
  int nums[10];
  printf("Here are 10 random integers between 1 and 100:\n");
  for (int i = 0; i < 10; i++) {
    nums[i] = rand() % 100 + 1;
    printf("%d ", nums[i]);
  }
  printf("\n");
  printf("And here are 10 random floating point numbers between 0 and 1:\n");
  for (int i = 0; i < 10; i++) {
    float num = (float) rand() / RAND_MAX;
    printf("%f ", num);
  }
  printf("\n");
  printf("Wow, I can't believe I just did that! I feel so powerful!\n");
  return 0;
}