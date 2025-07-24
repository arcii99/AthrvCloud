//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, j, k;
  int n = 1000000;
  int iterations = 1000;

  clock_t start, end;
  double time_taken;

  int* a = (int*) malloc(sizeof(int) * n);
  int* b = (int*) malloc(sizeof(int) * n);
  int* c = (int*) malloc(sizeof(int) * n);

  // populate input arrays with random values
  srand(time(0));
  for (i = 0; i < n; i++) {
    a[i] = rand() % n;
    b[i] = rand() % n;    
  }

  // initialize output array to 0
  for (i = 0; i < n; i++) {
    c[i] = 0;
  }

  // perform iterations of benchmarking code
  for (k = 0; k < iterations; k++) {
    start = clock();
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        c[i] += a[j] * b[i - j];
      }
    }
    end = clock();

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iteration %d: Time taken: %f seconds\n", k, time_taken);
  }

  // free memory allocated for arrays
  free(a);
  free(b);
  free(c);

  return 0;
}