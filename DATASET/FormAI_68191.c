//FormAI DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
  FILE *fptr;
  char filename[20] = "example.txt";
  char ch;

  fptr = fopen(filename, "r");

  if(fptr == NULL){
    perror("Error"); // prints error message with the errno
    exit(EXIT_FAILURE); // exit the program with failure status
  }

  while((ch = fgetc(fptr)) != EOF){
    printf("%c",ch);
  }

  if(ferror(fptr)){ // ferror returns non-zero if any error occurred while reading the file
      perror("Error"); // prints error message with the errno
      exit(EXIT_FAILURE); 
  }

  fclose(fptr);
  return 0;
}