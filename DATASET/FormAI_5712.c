//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: creative
#include <stdio.h>

int main() {
  // Ask the user for input
  printf("Enter the path to the file you want to extract metadata from: ");
  char path[200];
  fgets(path, 200, stdin);

  // Open the file
  FILE *file = fopen(path, "r");
  if (!file) {
    printf("Failed to open file at path: %s", path);
    return 1;
  }

  // Extract metadata
  char metadata[100][200];
  int lineCount = 0;
  char line[200];
  while (fgets(line, 200, file) != NULL) {
    if (line[0] == '<') {
      strcpy(metadata[lineCount], line);
      lineCount++;
    }
  }

  // Print the extracted metadata
  printf("\nMetadata:\n\n");
  for (int i = 0; i < lineCount; i++) {
    printf("%s", metadata[i]);
  }

  // Close the file and exit
  fclose(file);
  return 0;
}