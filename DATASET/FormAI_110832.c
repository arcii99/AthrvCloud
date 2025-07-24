//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//initializing constants
#define SIZE 10
#define MAX_VALUE 100

//function to generate random numbers
int generateRandomNumber() {
  return rand()%MAX_VALUE;
}

int main() {
  int array[SIZE], i, j, temp;

  //seeding random number generator
  srand(time(0));

  //generate random array elements
  for(i=0; i<SIZE; i++) {
    array[i] = generateRandomNumber();
  }

  //printing random array
  printf("Original Array: ");
  for(i=0; i<SIZE; i++) {
    printf("%d ", array[i]);
  }

  //bubble sort algorithm implementation
  for(i=0; i<SIZE-1; i++) {
    for(j=0; j<SIZE-i-1; j++) {
      if(array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  //printing sorted array
  printf("\nSorted Array: ");
  for(i=0; i<SIZE; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}