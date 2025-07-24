//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the C Metadata Extractor!\n");
  
  // Open file
  FILE *file = fopen("example.c", "r");
  if (file == NULL) {
    printf("Could not open file.\n");
    return 0;
  }
  
  // Read file line by line
  char line[100];
  while (fgets(line, 100, file)) {
    // Check for metadata
    if (line[0] == '#' && line[1] == 'm') {
      printf("Metadata found: %s", line);
      
      // Parse metadata
      char metadataType[10];
      char metadataValue[50];
      sscanf(line, "#m %s %s", metadataType, metadataValue);
      
      // Display metadata type and value
      printf("Metadata Type: %s\n", metadataType);
      printf("Metadata Value: %s\n\n", metadataValue);
    }
  }
  
  // Close file
  fclose(file);
  printf("Program complete!\n");
  return 0;
}