//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define K 5

int main(void) {
  int i, j, k, n;
  double x[N], y[N], z[K][2], d[K], sum;
  int group[N];

  srand(0);
  for (i = 0; i < N; i++) {
    x[i] = (double)rand() / RAND_MAX * 10.0;
    y[i] = (double)rand() / RAND_MAX * 10.0;
  }

  for (i = 0; i < K; i++) {
    z[i][0] = (double)rand() / RAND_MAX * 10.0;
    z[i][1] = (double)rand() / RAND_MAX * 10.0;
  }

  for (n = 0; n < 100; n++) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < K; j++) {
        d[j] = sqrt(pow(x[i] - z[j][0], 2) + pow(y[i] - z[j][1], 2));
      }
      sum = d[0];
      group[i] = 0;
      for (j = 1; j < K; j++) {
        if (d[j] < sum) {
          sum = d[j];
          group[i] = j;
        }
      }
    }

    for (j = 0; j < K; j++) {
      sum = 0.0;
      k = 0;
      for (i = 0; i < N; i++) {
        if (group[i] == j) {
          sum += x[i];
          k++;
        }
      }
      if (k > 0) z[j][0] = sum / k;

      sum = 0.0;
      k = 0;
      for (i = 0; i < N; i++) {
        if (group[i] == j) {
          sum += y[i];
          k++;
        }
      }
      if (k > 0) z[j][1] = sum / k;
    }
  }

  for (i = 0; i < N; i++) {
    printf("%lf %lf %d\n", x[i], y[i], group[i]);
  }

  return 0;
}