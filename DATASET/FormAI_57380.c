//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void extract_metadata(char * filename) {
  FILE * fp;
  char line[MAX_LEN];

  fp = fopen(filename, "r");
  if (!fp) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }

  while (fgets(line, MAX_LEN, fp)) {
    if (strchr(line, ':')) {
      char * metadata_value = strstr(line, ":") + 1;
      printf("%s", metadata_value);
    }
  }

  fclose(fp);
}

int main(int argc, char * argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  extract_metadata(argv[1]);
  return 0;
}