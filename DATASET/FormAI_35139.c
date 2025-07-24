//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>

int main() {
  int n, k, t;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  // Sort the array in non-decreasing order
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
  }
  
  // Calculate the sum of the first k elements
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  
  // Output the sum
  printf("%d", sum);
  return 0;
}