//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_file(char filename[]);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s [file1] [file2] ... [fileN]\n", argv[0]);
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    scan_file(argv[i]);
  }
  
  printf("Scanning complete.\n");

  return 0;
}

void scan_file(char filename[]) {
  FILE *fptr = fopen(filename, "r");
  char buffer[1024];
  size_t bytes_read;
  int virus_count = 0;

  if (fptr != NULL) {

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fptr)) > 0) {

      // Check buffer for virus signature
      if (strstr(buffer, "virus")) {
        virus_count++;
        printf("Virus detected in file: %s\n", filename);
        break;
      }

    }

    fclose(fptr);

    if (virus_count == 0) {
      printf("No virus detected in file: %s\n", filename);
    }

  } else {
    printf("Could not open file: %s\n", filename);
  }

}