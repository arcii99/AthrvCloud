//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));

  printf("Hello there! I am a chatbot, and I will generate some random numbers for you.\n");
  printf("How many random numbers would you like to generate?\n");

  int n;
  scanf("%d", &n);

  printf("What is the range of the random numbers that you would like to generate? (Enter two integers separated by a space)\n");

  int a, b;
  scanf("%d %d", &a, &b);

  printf("Here are your %d random numbers within the range [%d, %d]:\n", n, a, b);

  int i;
  for (i = 0; i < n; i++) {
    int r = rand() % (b - a + 1) + a;
    printf("%d ", r);
  }

  printf("\nThank you for using my random number generator! Goodbye!\n");

  return 0;
}