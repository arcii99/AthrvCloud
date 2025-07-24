//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

bool is_special_prime(int m, int n, int current) {
  if (n == 1) {
    if (current == m) {
      return true;
    }
    return false;
  }

  if (current % n != 0) {
    return false;
  }

  return is_special_prime(m, n - 1, current / n);
}

void *check_special_primes(void *args) {
  int *range = (int *) args;
  int m = range[0];
  int n = range[1];

  for (int i = m; i <= n; i++) {
    if (is_special_prime(i, n, i)) {
      printf("%d is a special prime\n", i);
    }
  }

  pthread_exit(NULL);
}

int main() {
  int range1[2] = {1, 10};
  int range2[2] = {11, 20};
  int range3[2] = {21, 30};

  pthread_t thread1, thread2, thread3;

  pthread_create(&thread1, NULL, check_special_primes, (void *) range1);
  pthread_create(&thread2, NULL, check_special_primes, (void *) range2);
  pthread_create(&thread3, NULL, check_special_primes, (void *) range3);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  return 0;
}