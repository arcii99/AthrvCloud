//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char file[50];
  printf("Enter file name to scan: ");
  fgets(file, 50, stdin);

  // check if file extension is .c
  char *extension = strrchr(file, '.');
  if (extension == NULL || strcmp(extension, ".c") != 0) {
    printf("Invalid file type. Please select a C file.\n");
    exit(1);
  }

  // open file
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    printf("Unable to open file.\n");
    exit(1);
  }

  char line[1000];
  int line_num = 0;

  // loop through each line in file
  while (fgets(line, 1000, fp) != NULL) {
    line_num++;

    // check for potential viruses
    if (strstr(line, "system(") != NULL || strstr(line, "malloc(") != NULL) {
      printf("Potential virus found on line %d: %s", line_num, line);
    }
  }

  fclose(fp);
  printf("Scan complete.\n");

  return 0;
}