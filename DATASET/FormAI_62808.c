//FormAI DATASET v1.0 Category: Searching algorithm ; Style: curious
#include<stdio.h>
#include<stdlib.h>

// Function to perform searching on array of size n
int search(int arr[], int n, int key){
  int l = 0, r = n-1; // Set the leftmost and rightmost index of array

  // Perform searching while leftmost index is less than or equal to rightmost index
  while(l <= r){
    int mid = (l+r)/2; // Calculate the middle index
    if(arr[mid] == key){ // If the key is found at middle index, return its index
      return mid;
    }
    else if(arr[mid] < key){ // If the mid element is less than key, ignore the left part of array and search in right part
      l = mid+1;
    }
    else{ // If the mid element is greater than key, ignore the right part of array and search in left part
      r = mid-1;
    }
  }
  return -1; // Return -1 if key is not found
}

int main(){
  int n, key;
  printf("Enter the size of array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of array in ascending order: ");
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]); // Input the array elements
  }

  printf("Enter the key to search: ");
  scanf("%d", &key);

  int index = search(arr, n, key); // Perform binary search on array
  
  if(index == -1){ // If key is not found
    printf("Key not found in array!");
  }
  else{ // If key is found
    printf("Key found at index %d", index);
  }

  return 0;
}