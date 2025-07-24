//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include<stdio.h>

//Function to search for an element in an array using linear search algorithm
int linearSearch(int arr[], int size, int searchElement){
  for(int i=0; i<size; i++){
    if(arr[i] == searchElement){
      return i;
    }
  }
  return -1;
}

//Function to implement binary search algorithm
int binarySearch(int arr[], int left, int right, int searchElement){
  if(left <= right){
    int middle = (left + right) / 2;
    if(arr[middle] == searchElement){
      return middle;
    }else if(arr[middle] > searchElement){
      return binarySearch(arr, left, middle-1, searchElement);
    }else{
      return binarySearch(arr, middle+1, right, searchElement);
    }
  }else{
    return -1;
  }
}

int main(){
  int arr[10] = {2, 4, 7, 8, 12, 23, 34, 45, 56, 67};
  int size = sizeof(arr)/sizeof(arr[0]);
  int searchElement = 34;
  
  int index = linearSearch(arr, size, searchElement);
  if(index == -1){
    printf("Element not found in the array using linear search algorithm.\n");
  }else{
    printf("Element found at index %d in the array using linear search algorithm.\n", index);
  }
  
  index = binarySearch(arr, 0, size-1, searchElement);
  if(index == -1){
    printf("Element not found in the array using binary search algorithm.\n");
  }else{
    printf("Element found at index %d in the array using binary search algorithm.\n", index);
  }
  
  return 0;
}