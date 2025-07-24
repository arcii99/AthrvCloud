//FormAI DATASET v1.0 Category: Funny ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100
#define MIN 0

int main() {
  srand((unsigned) time(NULL)); // seed random number generator
  
  int arr[MAX];
  int freq[MAX - MIN + 1] = {0}; // initialize frequency array to all 0's
  
  // generate random numbers between MIN and MAX and populate array
  for(int i = 0; i < MAX; i++) {
    int num = rand() % (MAX - MIN + 1) + MIN;
    arr[i] = num;
  }
  
  // calculate frequencies of each number in the array
  for(int i = 0; i < MAX; i++) {
    int index = arr[i] - MIN;
    freq[index]++;
  }
  
  printf("\nHistogram:\n");
  
  // display histogram of frequencies
  for(int i = 0; i < MAX - MIN + 1; i++) {
    if(freq[i] > 0) {
      printf("%d: ", i + MIN);
      for(int j = 1; j <= freq[i]; j++) {
        printf("*");
      }
      printf("\n");
    }
  }
  
  return 0;
}