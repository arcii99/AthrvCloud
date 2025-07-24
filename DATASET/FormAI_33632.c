//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Alan Touring
// Alan Turing-inspired C Antivirus Scanner

#include <stdio.h>

int main() {
  
  printf("Welcome to the C Antivirus Scanner!\n\n");

  // Prompt user for file to scan
  char filename[100];
  printf("Please enter the name of the file to scan: ");
  scanf("%s", filename);

  // Open file for scanning
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Unable to open file.\n");
    return 0;
  }

  // Start scanning
  printf("Scanning file...\n\n");

  // Read file character by character
  char c;
  int virus_count = 0;
  while ((c = fgetc(file)) != EOF) {
    // Check if character is part of a virus signature
    if (c == 'v' || c == 'i' || c == 'r' || c == 'u' || c == 's') {
      virus_count++;
    }
  }

  // Close file
  fclose(file);

  // Print results
  if (virus_count > 0) {
    printf("Warning: Virus detected! (%d occurrences)\n", virus_count);
  } else {
    printf("File is clean.\n");
  }

  return 0;
}