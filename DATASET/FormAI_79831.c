//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include<stdio.h>

int main() {
  int n, i, j, temp;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  int arr[n];
  
  printf("Enter the array elements: ");
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  //Sorting the array elements in ascending order
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  //Printing the sorted array
  printf("The sorted array elements are: ");
  for(i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  
  //Finding the minimum absolute difference
  int minDiff = arr[1] - arr[0];
  for(i=2; i<n; i++) {
    if((arr[i] - arr[i-1]) < minDiff) {
      minDiff = arr[i] - arr[i-1];
    }
  }
  
  //Printing the minimum absolute difference
  printf("\n\nThe minimum absolute difference is: %d", minDiff);
  
  return 0;
}