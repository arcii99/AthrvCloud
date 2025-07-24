//FormAI DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>

int main() {
  FILE *fp;
  char buffer[255];

  fp = fopen("data.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  while (fgets(buffer, 255, fp) != NULL) {
    printf("%s", buffer);
  }

  fclose(fp);

  return 0;
}