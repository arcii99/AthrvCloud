//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int signal[1024];
  int result[1024];
  int i, j, k;
  int alpha, beta, gamma;

  srand(time(NULL));

  printf("Generating signal...\n");

  for (i = 0; i < 1024; i++) {
    signal[i] = rand() % 100;
  }

  printf("Calculating result...\n");

  for (i = 0; i < 1024; i++) {
    alpha = beta = gamma = 0;

    for (j = i; j < i + 64; j++) {
      alpha += signal[j];
    }

    for (j = i; j < i + 32; j++) {
      beta += signal[j];
    }

    for (j = i; j < i + 16; j++) {
      gamma += signal[j];
    }

    result[i] = alpha / 64 + beta / 32 + gamma / 16;
  }

  printf("Printing result...\n");

  for (i = 0; i < 1024; i++) {
    printf("%d ", result[i]);
  }

  return 0;
}