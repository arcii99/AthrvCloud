//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYLEN 100
#define BUCKETSNUM 10

void printArray(int arr[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n-1) printf(", ");
  }
  printf("]\n");
}

void bucketSort(int arr[], int n) {
  int i, j, k;
  int* buckets[BUCKETSNUM];
  int bucketsInd[BUCKETSNUM] = {0};
  
  for (i = 0; i < BUCKETSNUM; i++) {
    buckets[i] = (int*) malloc(n * sizeof(int));
  }
  
  int maxVal = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  
  float divider = (float)(maxVal+1)/BUCKETSNUM;
  for (i = 0; i < n; i++) {
    int bucketIndex = (int)(arr[i]/divider);
    buckets[bucketIndex][bucketsInd[bucketIndex]] = arr[i];
    bucketsInd[bucketIndex]++;
  }
  
  int index = 0;
  for (i = 0; i < BUCKETSNUM; i++) {
    int bucketLen = bucketsInd[i];
    int* bucketArr = buckets[i];
    for (j = 0; j < bucketLen; j++) {
      arr[index] = bucketArr[j];
      index++;
    }
    free(bucketArr);
  }
}

int main() {
  srand(time(NULL));
  int arr[ARRAYLEN];
  for (int i = 0; i < ARRAYLEN; i++) {
    arr[i] = rand() % 100;
  }
  
  printf("Unsorted array: \n");
  printArray(arr, ARRAYLEN);
  
  bucketSort(arr, ARRAYLEN);
  
  printf("\nSorted array: \n");
  printArray(arr, ARRAYLEN);
  
  return 0;
}