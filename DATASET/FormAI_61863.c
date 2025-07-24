//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main(){

  //Allocate memory dynamically using malloc
  int *numArray = (int*)malloc(sizeof(int)*10);
  
  //check if allocation is successful
  if(numArray == NULL){
    printf("Memory allocation failed");
    exit(1);
  }
  
  printf("Memory allocated successfully using malloc\n");
  
  //store values into the array
  for(int i=0; i<10; i++){
    *(numArray+i) = i+1;
  }
  
  printf("Values stored into array dynamically:\n");
  
  //print values in the array
  for(int i=0; i<10; i++){
    printf("%d ", *(numArray+i));
  }

  //reallocate memory dynamically using realloc
  int *newNumArray = (int*)realloc(numArray, sizeof(int)*20);
  
  //check if reallocation is successful
  if(newNumArray == NULL){
    printf("\nMemory reallocation failed");
    exit(1);
  }
  
  printf("\n\nMemory reallocated successfully using realloc\n");
  
  //store more values into the array
  for(int i=10; i<20; i++){
    *(newNumArray+i) = i+1;
  }
  
  printf("Values stored into array dynamically after reallocation:\n");
  
  //print values in the array after reallocation
  for(int i=0; i<20; i++){
    printf("%d ", *(newNumArray+i));
  }
  
  //free the dynamically allocated memory
  free(newNumArray);
  
  return 0;
}