//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
//Macro to set the size of the array
#define ARRAY_SIZE 1000000

//Declare the array
int arr[ARRAY_SIZE];

//Function to generate random numbers to fill the array
void initializeRandomArray(){
   for(int i=0;i<ARRAY_SIZE;i++){
      arr[i] = rand();
   }
}

//Function that returns true if the array is sorted and false if not
bool isSorted(){
   for(int i=0;i<ARRAY_SIZE-1;i++){
      if(arr[i]>arr[i+1]){
         return false;
      }
   }
   return true;
}

//Function to perform bubble sort on the array
void bubbleSort(){
   for(int i=0;i<ARRAY_SIZE-1;i++){
      for(int j=0;j<ARRAY_SIZE-i-1;j++){
         if(arr[j]>arr[j+1]){
            //Swap
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main(){
   //Initialize the random array
   initializeRandomArray();
   
   //Print the unsorted array
   printf("Unsorted array:\n");
   for(int i=0;i<ARRAY_SIZE;i++){
      printf("%d ",arr[i]);
   }
   printf("\n");
   
   //Get the start time
   clock_t start = clock();
   
   //Perform bubble sort
   bubbleSort();
   
   //Get the end time
   clock_t end = clock();
   
   //Print the sorted array
   printf("Sorted array:\n");
   for(int i=0;i<ARRAY_SIZE;i++){
      printf("%d ",arr[i]);
   }
   printf("\n");
   
   //Print the time taken
   printf("Time taken for bubble sort: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);
   
   //Check if the array is sorted
   if(isSorted()){
      printf("Array is sorted\n");
   }else{
      printf("Array is not sorted\n");
   }
   
   return 0;
}