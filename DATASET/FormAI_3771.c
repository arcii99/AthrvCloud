//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include<stdio.h>
#include<stdlib.h>
#define MAX_MEMORY 1000 // Maximum amount of memory available for allocation

int memory[MAX_MEMORY]; //array to store the allocated memory
int num_allocated_blocks = 0; //number of allocated blocks of memory
int current_memory_start = 0; //starting point of the current memory block being allocated

/* Function to allocate memory */
void* allocateMemory(size_t size){
  void* p; //pointer to the allocated memory block

  //check if there's enough space to allocate
  if(num_allocated_blocks < MAX_MEMORY && current_memory_start+size <= MAX_MEMORY){
    p = &memory[current_memory_start]; //set pointer to the starting point of the block
    current_memory_start += size; //increment memory start
    num_allocated_blocks++; //increment number of allocated blocks
    return p; //return pointer to allocated memory
  }
  else{
    return NULL; //return NULL if there's not enough space to allocate
  }
}

/* Function to free memory */
void freeMemory(void* p){
  int i;
  int index = -1; //initialize index to -1

  //find the index of the memory block to be freed
  for(i=0; i<num_allocated_blocks; i++){
    if(&memory[i] == p){
      index = i;
      break;
    }
  }
  
  //if index is found, free the memory block
  if(index != -1){
    //move all the memory blocks after the freed memory block to fill the gap
    for(i=index+1; i<num_allocated_blocks; i++){
      memory[i-1] = memory[i];
    }
    num_allocated_blocks--; //decrement number of allocated blocks
    current_memory_start = index; //update current memory start
  }
}

int main(){
  int *a = NULL, *b = NULL, *c = NULL; //pointers to the allocated memory blocks

  //allocate the first block of memory
  a = (int*) allocateMemory(sizeof(int));
  if(a != NULL){
    *a = 5; //store a value in the allocated memory block
    printf("Memory Block a: %p - Value: %d\n", a, *a);
  }

  //allocate the second block of memory
  b = (int*) allocateMemory(sizeof(int));
  if(b != NULL){
    *b = 10; //store a value in the allocated memory block
    printf("Memory Block b: %p - Value: %d\n", b, *b);
  }

  //allocate the third block of memory
  c = (int*) allocateMemory(sizeof(int));
  if(c != NULL){
    *c = 15; //store a value in the allocated memory block
    printf("Memory Block c: %p - Value: %d\n", c, *c);
  }

  //free the second block of memory
  freeMemory(b);

  //allocate another block of memory
  b = (int*) allocateMemory(sizeof(int));
  if(b != NULL){
    *b = 20; //store a value in the allocated memory block
    printf("Memory Block b: %p - Value: %d\n", b, *b);
  }

  return 0; //Program completed successfully
}