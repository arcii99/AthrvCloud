//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>

int main() {
  int n, i, j;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  // Sorting the array in increasing order using bubble sort
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  int sum = 0, count = 0;
  printf("Enter the target sum: ");
  int target_sum;
  scanf("%d", &target_sum);
  
  // Finding the elements whose sum is closest to target_sum using Greedy Algorithm
  for(i=0; i<n; i++) {
    if(sum+arr[i] > target_sum) {
      break;
    } else {
      sum += arr[i];
      count++;
    }
  }
  
  // Printing the elements whose sum is closest to target_sum
  printf("The elements whose sum is closest to the target sum are: ");
  for(i=0; i<count; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}