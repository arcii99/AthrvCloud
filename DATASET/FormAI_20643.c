//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: excited
/*Wooohooo! I am thrilled to share with you my unique C Performance-Critical Component example program!*/

#include <stdio.h>

#define SIZE 100000

int main(){
  int arr[SIZE], i, j, temp; //declaring the array, variables and temp variable

  //Populating the array with random values for testing
  for (i = 0; i < SIZE; i++){
    arr[i] = rand()%1000;
  }

  printf("Unsorted array is:\n");

  //Printing array before sorting
  for(i=0;i<SIZE;i++){
    printf("%d ",arr[i]);
  }

  //Bubble sort algorithm to sort array
  for(i=0;i<SIZE-1;i++){
    for(j=0;j<SIZE-i-1;j++){
      if(arr[j]>arr[j+1]){
        //Swapping elements
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("\n\nSorted array is:\n");

  //Printing array after sorting
  for(i=0;i<SIZE;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}