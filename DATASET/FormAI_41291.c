//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  int n;
  double x, y;
  int count = 0;

  srand(time(NULL));

  printf("Enter the number of points to use in the simulation:\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;

    if (x * x + y * y <= 1.0) {
      count++;
    }
  }

  double pi = 4.0 * count / n;

  printf("The value of pi is approximately %f\n", pi);

  return 0;
}