//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>

int main() {
  int num, i, flag;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num <= 1) {
    printf("%d is not a prime number", num);
    return 0;
  }

  printf("Prime numbers from 2 to %d are: ", num);

  for (i = 2; i <= num; i++) {
    flag = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      printf("%d ", i);
    }
  }

  return 0;
}