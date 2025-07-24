//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(0));

  printf("Enter the number of elements in the array : ");
  int n;
  scanf("%d", &n);

  int arr[n];
  printf("Enter the array elements : ");
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int current_sum = 0, max_sum = 0;
  int start = 0, end = 0, current_start = 0;

  for(int i=0; i<n; i++) {
    current_sum += arr[i];

    if(current_sum < 0) {
      current_sum = 0;
      current_start = i+1;
    }

    if(current_sum > max_sum) {
      max_sum = current_sum;
      start = current_start;
      end = i;
    }
  }

  printf("The maximum sum subarray is : ");
  for(int i=start; i<=end; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nAnd the maximum sum is : %d", max_sum);

  return 0;
}