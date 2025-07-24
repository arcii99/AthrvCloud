//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>

/* Function to calculate the sum of array using synchronous programming */
int synchronous_sum(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

/* Function to calculate the product of array using synchronous programming */
int synchronous_product(int arr[], int size) {
  int product = 1;
  for (int i = 0; i < size; i++) {
    product *= arr[i];
  }
  return product;
}

/* Function to calculate the average of array using synchronous programming */
float synchronous_average(int arr[], int size) {
  float sum = synchronous_sum(arr, size);
  return sum / size;
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  int size = sizeof(arr)/sizeof(arr[0]); // calculating the length of the array

  printf("The sum of the array is %d.\n", synchronous_sum(arr, size));

  printf("The product of the array is %d.\n", synchronous_product(arr, size));

  printf("The average of the array is %.2f.\n", synchronous_average(arr, size));

  return 0;
}