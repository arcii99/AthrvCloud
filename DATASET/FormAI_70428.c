//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Greetings, adventurer! Welcome to the Metadata Extractor!\n");
  printf("Please input the name of thy file with metadata: ");
  char filename[50];
  scanf("%s", filename);
  
  // Open file
  FILE *fptr;
  fptr = fopen(filename, "r");
  
  // Find file type
  char *file_type = strrchr(filename, '.');
  if (file_type != NULL) {
    file_type++;
  } else {
    printf("I'm sorry adventurer, I could not extract the file type from the name thou provided.\n");
    return 0;
  }
  printf("The file type is: %s\n", file_type);
  
  // Find file size
  fseek(fptr, 0, SEEK_END);
  long int file_size = ftell(fptr);
  printf("The file size is: %ld bytes\n", file_size);
  
  // Find creator
  char *creator = "Unknown";
  char line[256];
  rewind(fptr);
  while (fgets(line, sizeof(line), fptr)) {
    if (strstr(line, "Creator: ")) {
      creator = strchr(line, ' ') + 1;
      break;
    }
  }
  printf("The creator of the file is: %s", creator);
  
  // Find creation date
  char *creation_date = "Unknown";
  rewind(fptr);
  while (fgets(line, sizeof(line), fptr)) {
    if (strstr(line, "Creation Date: ")) {
      creation_date = strchr(line, ' ') + 1;
      break;
    }
  }
  printf("The creation date of the file is: %s", creation_date);
  
  // Close file
  fclose(fptr);

  printf("Fare thee well, adventurer! Happy metadata extracting!\n");
  return 0;
}