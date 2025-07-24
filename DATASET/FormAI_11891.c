//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>

int main() {

  int limit, sum = 0;

  printf("Enter the limit: ");
  scanf("%d", &limit);

  for(int i = 2; i <= limit; i += 2) {
    sum += i;
    if(sum > 100) {
      printf("Warning: Sum exceeds 100!\n");
    }
  }

  printf("The sum of all even numbers up to %d is %d.\n", limit, sum);

  return 0;
}