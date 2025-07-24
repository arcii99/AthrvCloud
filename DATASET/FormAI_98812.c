//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  char output[1000];
  int indent = 0;
  
  printf("Welcome to the C HTML Beautifier!\n");
  
  // Get user input
  printf("Please enter the HTML code to beautify: ");
  fgets(input, sizeof(input), stdin);
  
  // Beautify the code
  int len = strlen(input);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (input[i] == '<') {
      // Increase the indent for the next line
      indent++;
      
      // Add a new line before the tag
      output[j++] = '\n';
      
      // Add spaces based on the current indent level
      for (int k = 0; k < indent; k++) {
        output[j++] = ' ';
      }
      
      // Copy the tag to the output
      output[j++] = input[i];
    } else if (input[i] == '>') {
      // Decrease the indent for the next line
      indent--;
      
      // Copy the tag to the output
      output[j++] = input[i];
      
      // Add a new line after the tag
      output[j++] = '\n';
    } else {
      // Copy the character to the output
      output[j++] = input[i];
    }
  }
  
  // Add a null terminator to the output
  output[j] = '\0';
  
  // Print the beautified code
  printf("\nHere's the beautified HTML code:\n%s\n", output);
  
  printf("Thanks for using the C HTML Beautifier! Have a great day!\n");

  return 0;
}