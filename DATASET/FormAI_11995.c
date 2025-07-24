//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Oh my goodness, I cannot believe how awesome this is!\n\n");
  printf("Welcome to the Memory Management Simulator 2000\n\n");

  int numOfBytes = 0;

  printf("Please enter the amount of memory you would like to allocate (in bytes): ");
  scanf("%d", &numOfBytes);

  printf("\nCreating memory block of size %d...\n", numOfBytes);

  void* memoryBlock = malloc(numOfBytes);
  if (memoryBlock == NULL) {
    printf("\nUh oh, memory allocation failed! Aborting program...\n");
    exit(1);
  }

  printf("\nMemory block created successfully!\n");

  printf("\nNow, let's free up %d bytes of memory...\n", numOfBytes);
  free(memoryBlock);

  printf("\nMemory freed! Wasn't that easy?\n");

  printf("\nDon't forget to clean up your code before exiting. Goodbye!\n");

  return 0;
}