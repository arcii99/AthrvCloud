//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int safe_divide(int numerator, int denominator) {
  if (denominator == 0) {
    printf("Error: division by zero\n");
    return 0;
  } else {
    return numerator / denominator;
  }
}

float recursive_average(int* numbers, int size, int index, float sum) {
  if (index == size) {
    if (size == 0) {
      printf("Error: cannot compute average of an empty array\n");
      exit(1);
    } else {
      return sum / size;
    }
  } else if (index < size) {
    int current_number = numbers[index];
    float new_sum = sum + current_number;
    return recursive_average(numbers, size, index + 1, new_sum);
  } else {
    printf("Error: invalid index\n");
    exit(1);
  }
}

float calculate_average(int* numbers, int size) {
  return recursive_average(numbers, size, 0, 0.0);
}

int main() {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[3] = {10, 20, 30};
  int arr3[0] = {};

  printf("Average of arr1: %.2f\n", calculate_average(arr1, 5));

  printf("Average of arr2: %.2f\n", calculate_average(arr2, 3));

  printf("Average of arr3: %.2f\n", calculate_average(arr3, 0)); 

  int a = 10;
  int b = 0;
  int result = safe_divide(a, b); 

  printf("Result of %d/%d = %d\n", a, b, result);

  return 0;
}