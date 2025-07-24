//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include<stdio.h>

void main() {
  int n, i, j, temp;
  printf("Enter the number of elements to be sorted: ");
  scanf("%d", &n);
  int arr[n];
 
  // Reading the array elements
  printf("\nEnter the elements:\n");
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  // Sorting Begins
  printf("\nSorting is in progress. Please wait...\n\n");
  for(i=0; i<n-1; i++){
    for(j=0; j<n-i-1; j++){
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        printf("Wow, I sorted %d and %d successfully!\n",arr[j],arr[j+1]);
      }
    }
  }
  
  // Printing Remeinder
  printf("\nGreat! The sorted array is:\n");
  for(i=0; i<n; i++){
    printf("%d ", arr[i]);
    if(i==n-1) printf("\n\nCompleted Successfully\n");
  } 
}