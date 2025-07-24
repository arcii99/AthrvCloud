//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>

int main() {

  int n, m, flag, count = 0;

  printf("Enter two numbers (n, m) to find all prime numbers between n and m: \n");
  scanf("%d %d", &n, &m);

  printf("Prime numbers between %d and %d are: \n", n, m);

  for (int i = n; i <= m; i++) {
    if (i == 1 || i == 0)
      continue;

    flag = 1;

    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }

    if (flag == 1) {
      count++;
      printf("%d\n", i);
    }
  }

  if (count == 0)
    printf("There are no prime numbers between %d and %d.\n", n, m);

  return 0;

}