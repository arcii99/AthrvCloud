//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Welcome to the Memory Management program!\n");

  int mem_size;
  printf("Please enter the size of memory to allocate (in bytes): ");
  scanf("%d", &mem_size);

  char *memory = (char*) malloc(mem_size);

  if(memory == NULL){
    printf("Memory allocation failed! Exiting program...\n");
    exit(1);
  }

  printf("Memory allocation successful!\n");

  printf("Printing out original memory values...\n");
  for(int i = 0; i < mem_size; i++){
    printf("%d ", *(memory+i));
  }

  printf("\n");

  printf("Please enter the location and value to change in memory...\n");
  int loc, val;
  printf("Location (0 to %d): ", mem_size-1);
  scanf("%d", &loc);
  printf("Value (-128 to 127): ");
  scanf("%d", &val);

  *(memory+loc) = val;

  printf("Printing out updated memory values...\n");
  for(int i = 0; i < mem_size; i++){
    printf("%d ", *(memory+i));
  }

  printf("\n");

  printf("Freeing up memory...\n");
  free(memory);

  printf("Memory freed! Goodbye!\n");

  return 0;
}