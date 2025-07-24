//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("nonexistent_file.txt", "r");
  
  if(file == NULL) {
    fprintf(stderr, "Error: Could not open file.\n");
    exit(1);
  }
  
  char buffer[100];
  int result = fscanf(file, "%s", buffer);
  
  if(result != 1) {
    fprintf(stderr, "Error: Could not read input from file.\n");
    exit(1);
  }
  
  printf("Contents of file: %s\n", buffer);
  
  int* ptr = malloc(sizeof(int));
  
  if(ptr == NULL) {
    fprintf(stderr, "Error: Out of memory.\n");
    exit(1);
  }
  
  *ptr = 42;
  printf("Value of ptr: %d\n", *ptr);
  
  free(ptr);
  
  char* str = "Hello, world!";
  
  if(str == NULL) {
    fprintf(stderr, "Error: String is null.\n");
    exit(1);
  }
  
  printf("%s\n", str);
  
  return 0;
}