//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(const char* msg) {
  if(errno) {
    perror(msg);
  } else {
    fprintf(stderr, "Error: %s\n", msg);
  }
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  if(argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* file = fopen(argv[1], "r");
  if(!file) {
    handle_error("Failed to open file");
  }

  // Do some processing using the file

  if(ferror(file)) {
    handle_error("Error reading file");
  }

  int close_status = fclose(file);
  if(close_status != 0) {
    handle_error("Failed to close file");
  }

  return EXIT_SUCCESS;
}