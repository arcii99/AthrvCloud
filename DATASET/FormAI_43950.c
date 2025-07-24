//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int arr[5], sum = 0, prod = 1;
  srand(time(0));

  printf("Welcome to the math exercise program!\n\n");

  // Fill the array with random numbers from 1 to 10
  for(int i = 0; i < 5; i++) {
    arr[i] = rand() % 10 + 1;
    printf("Number %d: %d\n", i+1, arr[i]);
  }

  // Add all the numbers in the array
  for(int i = 0; i < 5; i++) {
    sum += arr[i];
  }
  printf("\nSum of all the numbers: %d\n", sum);

  // Multiply all the numbers in the array
  for(int i = 0; i < 5; i++) {
    prod *= arr[i];
  }
  printf("\nProduct of all the numbers: %d\n", prod);

  // Calculate the average of all the numbers in the array
  float avg = (float) sum / 5;
  printf("\nAverage of all the numbers: %.2f\n", avg);

  // Calculate the factorial of the smallest number in the array
  int min = 10;
  for(int i = 0; i < 5; i++) {
    if(arr[i] < min) {
      min = arr[i];
    }
  }

  int fact = 1;
  for(int i = 2; i <= min; i++) {
    fact *= i;
  }
  printf("\nFactorial of the smallest number (%d): %d\n", min, fact);

  printf("\nThank you for using the math exercise program!");
  
  return 0;
}