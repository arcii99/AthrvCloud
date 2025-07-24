//FormAI DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv){
  if(argc < 2){
    printf("Error: Please provide a valid file\n");
    exit(1);
  }

  int input_file = open(argv[1], O_RDONLY);
  if(input_file < 0){
    printf("Error: Could not read file %s\n", argv[1]);
    exit(1);
  }
  
  int output_file = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
  if(output_file < 0){
    printf("Error: Could not create temporary file\n");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  int read_bytes = 0;
  
  while(read_bytes = read(input_file, buffer, BUFFER_SIZE)){
    if(read_bytes < 0){
      printf("Error: Could not read from file %s\n", argv[1]);
      exit(1);
    }
    
    int write_bytes = write(output_file, buffer, read_bytes);
    if(write_bytes < 0){
      printf("Error: Could not write to temporary file\n");
      exit(1);
    }
  }

  if(close(input_file) < 0){
    printf("Error: Could not close input file\n");
    exit(1);
  }
  
  if(close(output_file) < 0){
    printf("Error: Could not close temporary file\n");
    exit(1);
  }
  
  if(chmod("temp.txt", 0777) < 0){
    printf("Error: Could not change file permissions\n");
    exit(1);
  }
  
  if(rename("temp.txt", argv[1]) < 0){
    printf("Error: Could not rename temporary file\n");
    exit(1);
  }

  printf("File %s optimized successfully!\n", argv[1]);
  
  return 0;
}