//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <errno.h>
#include <string.h>

void checkFile(FILE *file) {
  if (file == NULL) {
    int err = errno;
    fprintf(stderr, "Error opening file: %s\n", strerror(err));
    exit(err);
  }
}

int main() {
  FILE *file = fopen("non_existent_file.txt", "r");
  checkFile(file);

  char buffer[100];
  if (fgets(buffer, 100, file) == NULL) {
    int err = errno;
    fprintf(stderr, "Error reading file: %s\n", strerror(err));
    exit(err);
  }

  fclose(file);
  printf("%s", buffer);
  return 0;
}