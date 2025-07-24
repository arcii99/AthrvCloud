//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fptr;
  char filename[100];
  char search_term[100];
  char line[100];
  int line_count = 0, match_count = 0;

  printf("Welcome to Sherlock Holmes' file search program\n");
  printf("Please enter the name of the file you would like to search: ");
  scanf("%s", filename);
  printf("Enter the term you would like to search for: ");
  scanf("%s", search_term);

  fptr = fopen(filename, "r");

  if (fptr == NULL) {
    printf("File does not exist\n");
    exit(1);
  }

  printf("File opened successfully!\n");

  while(fgets(line, 100, fptr)) {
    line_count++;
    if (strstr(line, search_term)) {
      printf("\nMatch found on line %d: %s", line_count, line);
      match_count++;
    }
  }

  if (match_count == 0) {
    printf("\nSorry, no matching lines were found.\n");
  } else {
    printf("\n%d matches found.\n", match_count);
  }

  fclose(fptr);

  return 0;
}