//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  FILE *fp;
  char filename[100];
  char search_query[100];
  char line[256];
  int line_number = 1;
  int query_found = 0;

  printf("Enter the filename to search: ");
  scanf("%s", filename);

  printf("Enter the search query: ");
  scanf("%s", search_query);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: Could not open file %s!\n", filename);
    exit(1);
  }

  while(fgets(line, sizeof(line), fp)) {
    char *token, *found;
    token = strtok(line, " .,:;!?()\"\n");
    while (token != NULL) {
      if (strcmp(token, search_query) == 0) {
        found = strstr(line, search_query);
        printf("Found \"%s\" in line %d: %s", search_query, line_number, line);
        query_found = 1;
      }
      token = strtok(NULL, " .,:;!?()\"\n");
    }
    line_number++;
  }

  fclose(fp);

  if (!query_found) {
    printf("Sorry, the search query \"%s\" was not found in the file %s.\n", search_query, filename);
  }

  return 0;
}