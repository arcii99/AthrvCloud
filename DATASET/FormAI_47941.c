//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define MAX_LOGS 10

int main() {
  double logs[MAX_LOGS];

  // read logs from user
  printf("Enter %d logs:\n", MAX_LOGS);
  for (int i = 0; i < MAX_LOGS; i++) {
    printf("log%d: ", i + 1);
    scanf("%lf", &logs[i]);
  }

  // calculate geometric mean and standard deviation
  double sum = 0.0;
  double product = 1.0;
  for (int i = 0; i < MAX_LOGS; i++) {
    sum += logs[i];
    product *= logs[i];
  }
  double gm = exp(sum / MAX_LOGS);
  double sd = sqrt(product / exp(2 * sum / MAX_LOGS) - gm * gm);

  // print results
  printf("Geometric Mean: %g\n", gm);
  printf("Standard Deviation: %g\n", sd);

  return 0;
}