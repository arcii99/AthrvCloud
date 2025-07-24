//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>

// A function to display the contents of a memory block
void display_memory(char *ptr, int size){
  printf("The contents of the memory block:\n");
  for(int i=0;i<size;i++){
    printf("%c ",*(ptr+i));
  }
  printf("\n");
}

int main(){
  printf("Welcome to my unique C Memory Management example program!\n");

  // Allocating memory for a char array of size 10
  char *ptr = (char*) malloc(10*sizeof(char));

  // If memory allocation fails
  if(ptr == NULL){
    printf("Memory allocation failed, exiting the program.\n");
    exit(1);
  }

  // Filling the memory block with some data
  for(int i=0;i<10;i++){
    *(ptr+i) = 'A'+i;
  }

  // Displaying the contents of the memory block
  display_memory(ptr,10);

  // Reallocating memory for the char array to size 20
  ptr = (char*) realloc(ptr,20*sizeof(char));

  // If memory allocation fails
  if(ptr == NULL){
    printf("Memory reallocation failed, exiting the program.\n");
    exit(1);
  }

  // Filling the extended memory block with some data
  for(int i=10;i<20;i++){
    *(ptr+i) = 'A'+i;
  }

  // Displaying the contents of the memory block
  display_memory(ptr,20);

  // Freeing the allocated memory
  free(ptr);
  printf("Memory block freed successfully.\n");

  printf("Thanks for using my unique C Memory Management example program!\n");
  return 0;
}