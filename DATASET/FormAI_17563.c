//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* file = fopen("example.txt", "w");
  if (!file) {
    perror("Failed to create file");
    exit(EXIT_FAILURE);
  }

  fputs("Hello, world!", file);
  fclose(file);

  file = fopen("example.txt", "r");
  if (file) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
      printf("%s", buffer);
    }
    fclose(file);
  }

  return 0;
}