//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Welcome to the C Searching Algorithm program!\n");
  
  //let's start by taking input from the user
  int n;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  
  //creating an array dynamically 
  int* arr = (int*)malloc(n*sizeof(int));
  
  //taking input for the array from the user
  printf("Enter the elements of the array:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  //sorting the array in ascending order
  printf("Sorting the array using Quick Sort Algorithm...\n");
  quickSort(arr,0,n-1);
  printf("Array sorted successfully!\n");
  
  //ask user for searching element
  int searchElement;
  printf("Enter the element you want to search for: ");
  scanf("%d",&searchElement);
  
  //performing binary search on the array
  printf("Performing Binary Search Algorithm...\n");
  int result = binarySearch(arr,0,n-1,searchElement);
  
  //printing the result
  if(result == -1){
    printf("The element is not present in the array.\n");
  }
  else{
    printf("The element is present at index %d.\n",result);
  }
  
  //free memory allocated for the array
  free(arr);
  
  printf("Thanks for using the C Searching Algorithm program! Keep exploring.\n");
  
  return 0;
}

//sorting the array using Quick Sort Algorithm
void quickSort(int arr[], int low, int high){
  if(low < high){
    int pivotIndex = quickSortPartition(arr,low,high);
    
    quickSort(arr,low,pivotIndex-1);
    quickSort(arr,pivotIndex+1,high);
  }
}

//partitioning step of Quick Sort Algorithm
int quickSortPartition(int arr[], int low, int high){
  int i = low-1;
  int pivotValue = arr[high];
  
  for(int j=low;j<=high-1;j++){
    if(arr[j]<=pivotValue){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return i+1;
}

//performing Binary Search Algorithm recursively
int binarySearch(int arr[], int low, int high, int searchElement){
  if(low<=high){
    int mid = (low+high)/2;
    if(arr[mid] == searchElement){
      return mid;
    }
    if(arr[mid] > searchElement){
      return binarySearch(arr,low,mid-1,searchElement);
    }
    else{
      return binarySearch(arr,mid+1,high,searchElement);
    }
  }
  return -1;
}

//swap two elements of an array
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}