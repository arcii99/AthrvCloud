//FormAI DATASET v1.0 Category: Scientific ; Style: portable
#include <stdio.h>

#define MAX_SIZE 100

int main() {
  int arr[MAX_SIZE], i, n, sum = 0;
  float average;

  printf("Enter the size of the array (up to %d): ", MAX_SIZE);
  scanf("%d", &n);

  printf("Enter the elements of the array:\n");
  for(i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Compute sum of elements
  for(i = 0; i < n; i++) {
    sum += arr[i];
  }

  // Compute average
  average = (float)sum / n;

  printf("The sum of the elements is %d.\n", sum);
  printf("The average of the elements is %.2f.\n", average);

  return 0;
}