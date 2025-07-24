//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n-1);
}

int fibonacci(int n) {
  if (n <= 1)
    return n;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

void print_array(int arr[], int n) {
  if (n == 1)
    printf("%d\n", arr[0]);
  else {
    print_array(arr, n-1);
    printf("%d\n", arr[n-1]);
  }
}

void merge(int arr1[], int arr2[], int m, int n, int arr3[]) {
  if (m == 0) {
    for (int i = 0; i < n; i++)
      arr3[i] = arr2[i];
    return;
  }
  else if (n == 0) {
    for (int i = 0; i < m; i++)
      arr3[i] = arr1[i];
    return;
  }
  else {
    if (arr1[0] < arr2[0]) {
      arr3[0] = arr1[0];
      merge(arr1+1, arr2, m-1, n, arr3+1);
    }
    else {
      arr3[0] = arr2[0];
      merge(arr1, arr2+1, m, n-1, arr3+1);
    }
  }
}

int main() {
  printf("Factorial of 5: %d\n", factorial(5));
  
  printf("Fibonacci sequence up to 10: ");
  for (int i = 0; i < 10; i++)
    printf("%d ", fibonacci(i));
  printf("\n");
  
  int arr[] = {1, 2, 3, 4, 5};
  printf("Printing array: \n");
  print_array(arr, 5);
  
  int arr1[] = {1, 3, 5, 7, 9};
  int arr2[] = {2, 4, 6, 8, 10};
  int arr3[10];
  
  printf("Merging 2 sorted arrays: \n");
  merge(arr1, arr2, 5, 5, arr3);
  print_array(arr3, 10);
  
  return 0;
}