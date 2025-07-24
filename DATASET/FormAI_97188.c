//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

  int fibo[20] = {0, 1}; // creating an array of Fibonacci sequence with 20 elements 
  int i, n;

  printf("Detective, please enter a number to see the Fibonacci sequence up to that point: ");
  scanf("%d", &n);

  printf("\nThe mysterious Fibonacci sequence up to %d: ", n);

  // For loop to generate the Fibonacci sequence and print it out
  for(i=2; i < n; i++){
      fibo[i] = fibo[i-1] + fibo[i-2]; // calculate the next number in sequence
      if(fibo[i] % 2 == 0){
          printf("%d, ", fibo[i]); // print out even number in the sequence
      }
      else if(fibo[i] % 2 != 0){
          printf("? "); // When the element in the array is odd, we print out a question mark instead of number because it is a mystery
      }
  }

  printf("\nThe work is done!");
  return 0;
}