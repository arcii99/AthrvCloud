//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>

// Function to compute the minimum of two numbers
int min(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

// Function to compute the maximum of two numbers
int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

// Function to compute the mean of an array of numbers
double mean(int *a, int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}

// Function to compute the variance of an array of numbers
double var(int *a, int n) {
  double m = mean(a, n);
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += (a[i] - m) * (a[i] - m);
  }
  return sum / (n - 1);
}

int main() {
  // Define the sample data
  int data[] = {10, 12, 15, 18, 20};
  int n = sizeof(data) / sizeof(int);

  // Compute the summary statistics
  double mean_val = mean(data, n);
  double var_val = var(data, n);
  int min_val = data[0];
  int max_val = data[0];

  for (int i = 1; i < n; i++) {
    min_val = min(min_val, data[i]);
    max_val = max(max_val, data[i]);
  }

  // Print the results
  printf("Mean value: %f\n", mean_val);
  printf("Variance: %f\n", var_val);
  printf("Minimum value: %d\n", min_val);
  printf("Maximum value: %d\n", max_val);

  return 0;
}