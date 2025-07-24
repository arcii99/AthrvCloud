//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <sys/time.h>

int main() {
  unsigned long long start_time, end_time, elapsed_time;
  int n = 100000000;

  /* Start Timer */
  struct timeval start;
  gettimeofday(&start, NULL);
  start_time = start.tv_sec * 1000000 + start.tv_usec;

  /* Performance-Critical Component */
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += i;
  }

  /* End Timer */
  struct timeval end;
  gettimeofday(&end, NULL);
  end_time = end.tv_sec * 1000000 + end.tv_usec;

  elapsed_time = end_time - start_time;

  /* Print Result */
  printf("Sum: %d \nElapsed Time: %lld microseconds\n", sum, elapsed_time);

  return 0;
}