//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the mean of an array
float mean(int arr[], int n) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  float mean = ((float) sum) / n;
  return mean;
}

// Function to calculate the standard deviation of an array
float standardDeviation(int arr[], int n) {
  float meanValue = mean(arr, n);
  float squaredDiff = 0;
  for(int i = 0; i < n; i++) {
    squaredDiff += ((float)arr[i] - meanValue) * ((float)arr[i] - meanValue);
  }
  float variance = squaredDiff / n;
  float standardDeviation = sqrt(variance);
  return standardDeviation;
}

int main() {
  int arrSize;
  printf("Enter the size of the array: ");
  scanf("%d", &arrSize);
  
  int *arr = malloc(arrSize * sizeof(int));
  if(arr == NULL) {
    printf("Memory allocation failed");
    return 1;
  }

  printf("Enter the elements of the array:\n");
  for(int i = 0; i < arrSize; i++) {
    scanf("%d", &arr[i]);
  }

  float stdDev = standardDeviation(arr, arrSize);
  printf("Standard deviation of the array is %.2f\n", stdDev);

  free(arr);
  return 0;
}