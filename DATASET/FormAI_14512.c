//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  printf("Initializing C Resume Parsing system...\n");

  // Set up variables and data structures
  int numEntries = 0;
  char input[50];

  // Get user input
  printf("Enter number of resumes to parse: ");
  fgets(input, 50, stdin);
  numEntries = atoi(input);

  // Allocate memory for resumes
  char** resumes = (char**) malloc(numEntries * sizeof(char*));
  for (int i = 0; i < numEntries; i++) {
    resumes[i] = (char*) malloc(500 * sizeof(char));
  }

  // Parse each resume
  printf("Enter each resume followed by a blank line:\n");
  for (int i = 0; i < numEntries; i++) {
    fgets(resumes[i], 500, stdin);
    while (strcmp(resumes[i], "\n") != 0) {
      strcat(resumes[i], "\n");
      fgets(input, 50, stdin);
      strcat(resumes[i], input);
    }
  }

  // Print parsed resumes
  printf("\nParsed Resumes:\n");
  for (int i = 0; i < numEntries; i++) {
    printf("%s\n", resumes[i]);
  }

  // Free memory
  for (int i = 0; i < numEntries; i++) {
    free(resumes[i]);
  }
  free(resumes);

  return 0;
}