//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handleError(int errorNumber) {
  printf("Error code: %d\n", errorNumber);
  switch (errorNumber) {
    case EACCES:
      printf("Permission denied\n");
      break;
    case EIO:
      printf("Input/output error\n");
      break;
    case ENFILE:
      printf("Too many open files\n");
      break;
    default:
      printf("Unknown error occurred\n");
  }
}

int main() {
  FILE *file;
  char content[100];

  file = fopen("non_existent_file.txt", "r");
  if (file == NULL) {
    handleError(errno);
    exit(EXIT_FAILURE);
  }

  if (fgets(content, 100, file) == NULL) {
    handleError(errno);
    exit(EXIT_FAILURE);
  }

  printf("File content: %s", content);

  if (fclose(file) != 0) {
    handleError(errno);
    exit(EXIT_FAILURE);
  }

  return 0;
}