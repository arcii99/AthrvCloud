//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_virus(char *filename);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  char *filename = argv[1];

  if (is_virus(filename)) {
    printf("%s is a virus\n", filename);
  } else {
    printf("%s is safe\n", filename);
  }

  return 0;
}

bool is_virus(char *filename) {
  char *virus_signature = "BADC0DE";
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  char buffer[256];
  while (fgets(buffer, sizeof(buffer), file)) {
    if (strstr(buffer, virus_signature)) {
      fclose(file);
      return true;
    }
  }

  fclose(file);
  return false;
}