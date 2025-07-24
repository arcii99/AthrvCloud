//FormAI DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file_pointer;
  char file_name[100];
  char file_contents[1000];
  int file_size, i;
  
  printf("Enter the name of the file you want to recover: ");
  scanf("%s", file_name);
  
  file_pointer = fopen(file_name, "r");
  
  if (file_pointer == NULL) {
    printf("ERROR: Unable to open file\n");
    return 1;
  }
  
  fseek(file_pointer, 0L, SEEK_END);  // set the file position to the end of the file
  file_size = ftell(file_pointer);  // get the size of the file
  fseek(file_pointer, 0L, SEEK_SET);  // set the file position back to the beginning
  
  printf("File size is %d bytes\n", file_size);
  
  for (i = 0; i < file_size; i++) {  // read character by character
    file_contents[i] = fgetc(file_pointer);
  }
  
  printf("File contents:\n%s", file_contents);
  
  fclose(file_pointer);
  
  return 0;
}