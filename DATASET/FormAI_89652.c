//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define variables
  int n, i, j, count, sum;
  float avg;
  
  // Prompt user for input
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  
  // Create dynamic array
  int* arr = (int*) malloc(n * sizeof(int));
  
  // Prompt user for array elements and calculate sum
  printf("Enter the elements of the array: ");
  sum = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  
  // Calculate average
  avg = (float) sum / n;
  
  // Calculate number of elements above average
  count = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] > avg) {
      count++;
    }
  }
  
  // Print results
  printf("The sum of the array elements is: %d\n", sum);
  printf("The average of the array elements is: %.2f\n", avg);
  printf("%d elements in the array are above the average.\n", count);
  
  // Free dynamic array
  free(arr);
  
  return 0;
}