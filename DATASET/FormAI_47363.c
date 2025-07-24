//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include<stdio.h>
#include<stdlib.h>

//function to display the contents of the memory block
void display(int *arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}

int main(){
  int *arr;

  //allocate memory for 5 integers
  arr = (int*)malloc(5*sizeof(int));

  //check if the memory is allocated successfully or not
  if(arr == NULL){
    printf("Memory allocation failed");
    exit(0);
  }

  //store some data in the memory block
  for(int i = 0; i < 5; i++){
    arr[i] = i;
  }

  //display the contents of the memory block
  printf("Memory block contents: ");
  display(arr, 5);

  //reallocate memory for 10 integers
  arr = (int*)realloc(arr, 10*sizeof(int));

  //check if the memory is reallocated successfully or not
  if(arr == NULL){
    printf("Memory reallocation failed");
    exit(0);
  }

  //store some more data in the memory block
  for(int i = 5; i < 10; i++){
    arr[i] = i;
  }

  //display the contents of the memory block
  printf("\n\nMemory block contents: ");
  display(arr, 10);

  //free the memory block
  free(arr);
  arr = NULL;

  return 0;
}