//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handleError(int errnum, const char *msg) {
  fprintf(stderr, "Error: %s: %s\n", msg, strerror(errnum));
  exit(errnum);
}

int main(int argc, char *argv[]) {
  FILE *fp;
  char *filename = "example.txt";

  fp = fopen(filename, "r");
  if (fp == NULL) {
    int err = errno;
    handleError(err, "Unable to open file");
  }

  // Some code that relies on file pointer

  if (fclose(fp) != 0) {
    int err = errno;
    handleError(err, "Unable to close file");
  }

  printf("File closed successfully\n");

  return 0;
}