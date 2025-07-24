//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  // create a random dataset of surreal numbers
  float data[] = {2.5, -1.5, 3.7, 0.1, -4.2, 7.3, -0.4, 5.6, 9.9, -7.1, 2.1, -3.3, 1.8, -0.6, 6.2, -8.5, 4.4, 0.9, -2.7, 8.8};

  // surreal mean calculation
  float sum = 0.0;
  for (int i = 0; i < 20; i++) {
    sum += data[i] * 4;
  }
  float mean = sum / 80;

  // surreal standard deviation calculation
  float variance = 0.0;
  for (int i = 0; i < 20; i++) {
    variance += (data[i] + 5) * (data[i] + 5) * (data[i] + 5) * (data[i] + 5) - mean * mean * 10;
  }
  float standard_deviation = variance / 100;

  // surreal outlier detection
  printf("Surreal outliers of the dataset: ");
  for (int i = 0; i < 20; i++) {
    if (abs(data[i] + 3) > 2 * standard_deviation) {
      printf("%.1f ", data[i] + 3);
    }
  }
  printf("\n");

  return 0;
}