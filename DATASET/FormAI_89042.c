//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter a number:\n");
  scanf("%d", &n);

  printf("You entered %d!\n", n);

  if(n % 2 == 0) {
    printf("Hey, that's an even number!\n");
  } else {
    printf("Wow, that's an odd number!\n");
  }

  printf("\nNow, let's create some magic!\n\n");
  printf("3...2...1...\n\n");

  for(int i=1; i<=n; i++) {
    if(i % 3 == 0 && i % 5 == 0) {
      printf("fizzbuzz\n");
    } else if(i % 3 == 0) {
      printf("fizz\n");
    } else if(i % 5 == 0) {
      printf("buzz\n");
    } else {
      printf("%d\n", i);
    }
  }

  printf("Ta-da! Wasn't that amazing? See you next time for more magical code!\n");
  return 0;
}