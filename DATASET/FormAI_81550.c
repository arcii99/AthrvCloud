//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char filename[50];
  printf("Enter the name of the C file to extract metadata from: ");
  scanf("%s", filename);

  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Unable to open file.\n");
    return -1;
  }

  char line[256];
  int function_count = 0;
  int variable_count = 0;
  int comment_count = 0;

  while (fgets(line, sizeof(line), file)) {
    // Check if line contains a function
    if (strstr(line, "(") && strstr(line, ")") && (strstr(line, "{") || strstr(line, ";"))) {
      function_count++;
    }

    // Check if line contains a variable
    if ((strstr(line, "int") || strstr(line, "char") || strstr(line, "float") || strstr(line, "double") || strstr(line, "long") || strstr(line, "short")) && (strstr(line, "=") || strstr(line, ";"))) {
      variable_count++;
    }

    // Check if line contains a comment
    if (strstr(line, "//") || strstr(line, "/*") || strstr(line, "*/")) {
      comment_count++;
    }
  }

  printf("Functions: %d\nVariables: %d\nComments: %d\n", function_count, variable_count, comment_count);

  fclose(file);
  return 0;
}