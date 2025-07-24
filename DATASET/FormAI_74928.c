//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>

int main() {
  int num, i, j, flag;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &num);

  // 1 is not a prime number
  if (num >= 1) {
    printf("2\n");
  }
  for (i = 3; i <= num; i++) {
    flag = 0;
    for (j = 2; j <= (i / 2); j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}