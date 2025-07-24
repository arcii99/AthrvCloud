//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void beautify(char *fileName, char *config) {
  FILE *fPtr;
  char buffer[1000], *strPtr, *tempPtr;
  int indentLevel = 0, configSize = strlen(config), i;

  // Open file for reading
  fPtr = fopen(fileName, "r");

  // Check if file exists
  if(fPtr == NULL) {
    printf("Unable to open file!");
    exit(1);
  }

  // Read file line by line
  while(fgets(buffer, sizeof(buffer), fPtr)) {
    strPtr = buffer;

    // Remove leading whitespace
    while(*strPtr == ' ' || *strPtr == '\t') {
      printf("%c", *strPtr);
      strPtr++;
    }

    // Increase indent level if opening tag is found
    if(strstr(strPtr, "<") != NULL && strstr(strPtr, "</") == NULL) {
      for(i = 0; i < indentLevel * configSize; i++)
        printf("%c", config[i % configSize]);
      indentLevel++;
    }

    // Decrease indent level if closing tag is found
    if(strstr(strPtr, "</") != NULL) {
      indentLevel--;
      for(i = 0; i < indentLevel * configSize; i++)
        printf("%c", config[i % configSize]);
    }

    // Print the rest of the line
    printf("%s", strPtr);
  }

  // Close file
  fclose(fPtr);
}

int main() {
  char fileName[] = "example.html";
  char config[] = "\t"; // Configurable style, here we use a tab character

  // Call the function to beautify HTML file
  beautify(fileName, config);

  return 0;
}