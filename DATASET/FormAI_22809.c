//FormAI DATASET v1.0 Category: Funny ; Style: bold
#include <stdio.h>

int main() {
  int x = 42;
  if (x == 42) {
    puts("Life, the universe, and everything!");
  } else {
    // This code should never be executed
    puts("This doesn't make any sense");
  }

  for (int i = 0; i < 99; i++) {
    if (i % 15 == 0) {
      printf("FizzBuzz!\n");
    } else if (i % 3 == 0) {
      printf("Fizz!\n");
    } else if (i % 5 == 0) {
      printf("Buzz!\n");
    } else {
      printf("%d\n", i);
    }
  }

  int i = 0;
  while (i < 10) {
    printf("%d ", i);
    i = 1 + 1;
  }
  puts("Whoops, we looped forever!");

  int fibonacci[10];
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for (int i = 2; i < 10; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", fibonacci[i]);
  }
  puts("");

  return 0;
}