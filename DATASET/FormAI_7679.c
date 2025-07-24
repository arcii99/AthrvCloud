//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>

int main() {
  int n = 5;
  int sum = 0;

  // Initialize an array with random numbers
  int arr[] = {5, 3, 1, 9, 2};

  // Loop through the array and calculate the sum of numbers
  for(int i=0; i<n; i++) {
    sum += arr[i];
  }

  // Print the sum of numbers
  printf("The sum of numbers is: %d\n", sum);

  // Find the smallest number in the array
  int smallest = arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i] < smallest) {
      smallest = arr[i];
    }
  }

  // Print the smallest number in the array
  printf("The smallest number in the array is: %d\n", smallest);

  // Find the largest number in the array
  int largest = arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i] > largest) {
      largest = arr[i];
    }
  }

  // Print the largest number in the array
  printf("The largest number in the array is: %d\n", largest);

  return 0;
}