//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int count = 0;      
  char line[1024];   
  char file_path[1024];
  char *search_str;
  FILE* file;
  
  if (argc != 3) { // Check if the user inputs the correct input parameters.
    printf("Usage: ./log_analyzer <file_path> <search_str>\n");
    exit(1);
  } else {
    strcpy(file_path, argv[1]); // Assign the file path to a variable
    search_str = argv[2]; // Assign the search string to a variable
  }

  file = fopen(file_path,"r"); // Open the file

  if (file == NULL) {
    printf("Cannot open file at path: %s\n", file_path);
    exit(1);
  }

  while (fgets(line, sizeof(line), file)) { // Iterating through each line of the file
    if (strstr(line, search_str) != NULL) { // Check if the search string is present in the line
      count++; // Increment the count variable
    }
  }

  fclose(file); // Close the file
  
  if (count > 0) {
    printf("%s was found %d times in %s\n", search_str, count, file_path);
  } else {
    printf("%s was not found in %s\n", search_str, file_path);
  }

  return 0; // Return exit status 0 for successful execution
}