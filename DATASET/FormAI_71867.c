//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a file
char* extract_metadata(char* file_path) {
  // Open the file
  FILE* file = fopen(file_path, "r");
  
  // Check if the file opened successfully
  if (file == NULL) {
    printf("Error opening file for metadata extraction");
    return NULL;
  }
  
  // Allocate memory for the metadata string
  char* metadata = (char*)malloc(sizeof(char) * 256);
  
  // Read the first line of the file and store it as metadata
  fgets(metadata, 256, file);
  
  // Close the file
  fclose(file);
  
  // Return the metadata string
  return metadata;
}

int main() {
  // Let's extract metadata from a fun file
  char* file_path = "fun.txt";
  
  // Extract the metadata from the file
  char* metadata = extract_metadata(file_path);
  
  // Print the metadata to the console
  printf("The metadata of %s is: %s", file_path, metadata);
  
  // Free the memory allocated for the metadata string
  free(metadata);
  
  // Return a happy 0 to indicate success
  return 0;
}