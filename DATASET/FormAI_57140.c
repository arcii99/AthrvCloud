//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a file is infected
int isInfected(char *filename) {
  FILE *f = fopen(filename, "rb");
  int infected = 0;

  if (f != NULL) {
    // Read the first 10 bytes of the file
    unsigned char buffer[10];
    fread(buffer, sizeof(unsigned char), 10, f);

    // Check if the file matches known virus signatures
    if (memcmp(buffer, "VIRUS", 5) == 0 || memcmp(buffer, "INFECT", 6) == 0) {
      infected = 1;
    }

    fclose(f);
  }

  return infected;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    // No filename provided, exit
    printf("Usage: %s filename\n", argv[0]);
    exit(1);
  }
  
  // Check if the file is infected
  if (isInfected(argv[1])) {
    printf("The file %s is infected with a virus.\n", argv[1]);
  } else {
    printf("The file %s is not infected with a virus.\n", argv[1]);
  }

  return 0;
}