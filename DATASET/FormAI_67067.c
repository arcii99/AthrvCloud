//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mind-bending C Antivirus Scanner Example Program

int main(void) {

  printf("==== Welcome to Mind-Bending C Antivirus Scanner ====\n");

  // Start scanning process
  char *filename = NULL;
  char *virusSignature = "int virus"; // Example virus signature
  char *fileContent = NULL;
  size_t len = 0;
  ssize_t read;
  int infected = 0;

  printf("\nEnter the name of the file to scan: ");
  getline(&filename, &len, stdin);

  // Open the file
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  // Read file content
  while ((read = getline(&fileContent, &len, file)) != -1) {
    if (strstr(fileContent, virusSignature) != NULL) {
      printf("The file \"%s\" is infected with a virus!\n", filename);
      infected = 1;
      break;
    }
  }

  // Close the file
  fclose(file);

  if (!infected) {
    printf("The file \"%s\" is safe from viruses! :)\n", filename);
  }

  return 0;
}