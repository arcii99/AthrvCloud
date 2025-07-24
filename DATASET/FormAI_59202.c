//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>

int main() {

  int num_list[10]={8,2,3,5,7,1,9,4,6,10}; //creating an integer array and initializing it
  printf("Original list: "); //printing original list
  for(int i=0; i<10; i++) {
    printf("%d ", num_list[i]);
  }
  
  for(int i=0; i<10; i++) {         //Outer loop for iterating through each item 
    for(int j=0; j<9; j++) {       //Inner loop for iterating through the list and sorting in ascending order
      if(num_list[j]>num_list[j+1]) {
        int temp=num_list[j];
        num_list[j]=num_list[j+1];
        num_list[j+1]=temp;
      }
    }
  }
  
  printf("\nSorted list: "); //printing sorted list
  for(int i=0; i<10; i++) {
    printf("%d ", num_list[i]);
  }
  
  return 0;
}