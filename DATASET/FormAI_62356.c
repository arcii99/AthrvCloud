//FormAI DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

//This is a sorting program
//It sorts the given array of integers using the Bubble Sort Algorithm

int main() {
  int arr[10], temp, i, j;

  printf("Enter 10 integers: ");

  for(i=0 ; i<10 ; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nList before sorting: ");

  for(i=0 ; i<10 ; i++) {
    printf("%d ", arr[i]);
  }

  for(i=0 ; i<9 ; i++) {
    for(j=0 ; j<9-i ; j++) {
      if(arr[j]>arr[j+1]) {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }

  printf("\nList after sorting: ");

  for(i=0 ; i<10 ; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}