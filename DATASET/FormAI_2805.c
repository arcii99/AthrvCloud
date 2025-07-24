//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>

// Custom implementation of Bucket Sort in C
void bucketSort(int arr[], int n) {

  // Defining a bucket of size 10
  int bucket[10][n];

  // Counting the sets of each digit in the given array and storing it in the bucket
  int max_val = arr[0];
  for(int i=1; i<n; i++) {
    if(max_val < arr[i]) {
      max_val = arr[i];
    }
  }
  int sets_count = 0;
  while(max_val != 0) {
    max_val /= 10;
    sets_count++;
  }

  int remainder;
  int divisor = 1;
  for(int i=0; i<sets_count; i++) {
    for(int j=0; j<n; j++) {
      remainder = (arr[j] / divisor) % 10;
      bucket[remainder][j] = arr[j];
    }

    int index = 0;
    for(int k=0; k<10; k++) {
      for(int l=0; l<n; l++) {
        if(bucket[k][l] != 0) {
          arr[index++] = bucket[k][l];
          bucket[k][l] = 0;
        }
      }
    }

    divisor *= 10;
  }

}

// Main function to test the Bucket Sort function
int main() {

  printf("Welcome to Bucket Sort in C\n");

  int arr[] = {21, 43, 23, 56, 34, 67, 35, 78, 12, 79, 45, 98, 87, 64, 31, 16, 29};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("Original array: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  bucketSort(arr, n);

  printf("\nSorted array: ");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\nBucket Sort is an amazing sorting algorithm that can quickly and efficiently sort a large set of data with a relatively small number of comparisons. I hope this program helps you understand how this algorithm works and how it can be implemented in C.");
  
  return 0;
}