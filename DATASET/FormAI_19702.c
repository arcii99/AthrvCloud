//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  srand(time(NULL));  //Seed the random number generator

  int arr[100];       //Declare an array of size 100

  printf("Welcome to the Sorting Surprise!\n\n");

  printf("Generating a random array of 100 integers...\n");
  
  //Fill the array with random integers
  for(int i=0; i<100; i++){
    arr[i]=rand()%1000;
  }
  
  printf("The unsorted array is: \n");
  
  //Print the unsorted array
  for(int i=0; i<100; i++){
    printf("%d ", arr[i]);
  }

  //Selection Sort
  for(int i=0; i<100-1; i++){
    int min_idx=i;
    for(int j=i+1; j<100; j++){
      if(arr[j]<arr[min_idx]){
        min_idx=j;
      }
    }
    int temp=arr[min_idx];
    arr[min_idx]=arr[i];
    arr[i]=temp;
  }

  printf("\n\nWow, the array is now sorted in ascending order using Selection Sort!\n");

  printf("The sorted array is: \n");

  //Print the sorted array
  for(int i=0; i<100; i++){
    printf("%d ", arr[i]);
  }
  
  return 0;
}