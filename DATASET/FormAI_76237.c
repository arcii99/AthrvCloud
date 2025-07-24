//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to our cheerful Memory Management Program!\n\n");
  
  int* ptr = (int*)malloc(5 * sizeof(int));
  
  if(ptr == NULL) {
    printf("Oops! Memory allocation failed!\n");
    exit(1);
  }
  
  printf("Memory allocation successful!\n\n");
  
  //Let's fill up the allocated memory with some cheerful values
  printf("Initializing cheerful values into memory...\n");
  
  for(int i = 0; i < 5; i++) {
    ptr[i] = i * 2 + 1;
  }
  
  //Now, let's print out the cheerful values stored in the memory
  printf("Printing out cheerful values...\n");
  
  for(int i = 0; i < 5; i++) {
    printf("%d ", ptr[i]);
  }
  
  //Let's release the memory allocated earlier, with a cheerful goodbye!
  printf("\n\nGoodbye cheerful memory! We are releasing you now!\n");
  free(ptr);
  
  return 0;
}