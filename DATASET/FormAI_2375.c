//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to my cheerful C syntax parsing example program!\n");
  
  // Here's a sample program for us to parse
  char* sampleProgram = "int main() {\n  printf(\"Hello world!\\n\");\n  return 0;\n}";
  
  printf("Parsing the following program:\n%s\n", sampleProgram);
  
  // Let's count the number of opening and closing braces
  int countOpenBraces = 0;
  int countCloseBraces = 0;
  
  // Let's also check if there are any missing semicolons
  int semicolonMissing = 0;
  
  for (int i = 0; sampleProgram[i] != '\0'; i++) {
    if (sampleProgram[i] == '{') {
      countOpenBraces++;
    } else if (sampleProgram[i] == '}') {
      countCloseBraces++;
    } else if (sampleProgram[i] == ';') {
      if (i > 0 && sampleProgram[i-1] == '}') {
        // This semicolon is missing
        semicolonMissing = 1;
      }
    }
  }
  
  printf("Number of opening braces: %d\n", countOpenBraces);
  printf("Number of closing braces: %d\n", countCloseBraces);
  
  if (countOpenBraces == countCloseBraces) {
    printf("Braces are balanced. Hooray!\n");
  } else {
    printf("Braces are not balanced. :(\n");
  }
  
  if (semicolonMissing) {
    printf("Whoops! There's a missing semicolon after the closing brace!\n");
  } else {
    printf("No missing semicolons. Great job!\n");
  }
  
  printf("Thanks for using my program! Have a cheerful day!\n");
  
  return 0;
}