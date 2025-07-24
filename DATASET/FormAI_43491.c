//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  char output[1000];
  int tabCount = 0;
  
  printf("Enter your HTML code:\n");
  fgets(input, 1000, stdin);
  
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == '<') {
      output[i] = input[i];
      output[i+1] = '\n';
      tabCount++;
      for(int j = 0; j < tabCount; j++) {
        strcat(output, "\t");
      }
    }
    else if(input[i] == '>') {
      output[i] = '\n';
    }
    else {
      output[i] = input[i];
    }
  }
  
  printf("\nYour beautified HTML code:\n");
  printf("%s", output);
  
  return 0;
}