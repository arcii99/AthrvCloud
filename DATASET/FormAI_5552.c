//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

int main() {
  int a = 5, b = 10;
  printf("The sum of %d and %d is %d\n", a, b, a + b);
  printf("The difference between %d and %d is %d\n", b, a, b - a);

  float c = 2.5, d = 7.8;
  printf("The product of %.2f and %.2f is %.2f\n", c, d, c * d);
  printf("The quotient when %.2f is divided by %.2f is %.2f\n", d, c, d / c);

  int arr[] = {12, 6, 8, 4, 3};
  int arr_len = sizeof(arr) / sizeof(int);
  int sum = 0;
  for(int i = 0; i < arr_len; i++) {
    sum += arr[i];
  }
  float average = (float) sum / arr_len;
  printf("The sum of elements in the array is %d\n", sum);
  printf("The average of elements in the array is %.2f\n", average);

  int factorial_num = 7;
  int factorial = 1;
  for(int i = 1; i <= factorial_num; i++) {
    factorial *= i;
  }
  printf("Factorial of %d is %d\n", factorial_num, factorial);

  int num = 15;
  printf("The binary representation of %d is ", num);
  for(int i = 31; i >= 0; i--) {
    if(num & (1 << i)) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");

  return 0;
}