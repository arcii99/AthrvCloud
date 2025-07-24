//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // set random seed
  int array[1000]; // declare array to store random numbers
  int i, j, temp; // declare variables for loop and swapping
  
  // fill array with random numbers
  for(i=0; i<1000; i++) {
    array[i] = rand() % 1000 + 1; // generate random number between 1 and 1000
  }
  
  // bubble sort algorithm to sort array in descending order
  for(i=0; i<1000; i++) {
    for(j=i+1; j<1000; j++) {
      if(array[i] < array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  
  // print the sorted array
  printf("Sorted array in descending order:\n");
  for(i=0; i<1000; i++) {
    printf("%d ", array[i]);
  }
  
  // calculate average of array elements
  int sum = 0;
  float average;
  for(i=0; i<1000; i++) {
    sum += array[i];
  }
  average = (float) sum / 1000;
  
  // print the average value
  printf("\n\nAverage value of the array elements: %.2f", average);
  
  return 0;
}