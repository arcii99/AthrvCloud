//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[10000];
  char output[10000];
  int indent_level = 0;
  int i = 0, j = 0;

  printf("Enter the HTML document to be beautified: ");
  fgets(input, sizeof(input), stdin);
  
  while(i<strlen(input)){
    if(input[i] == '<'){
      output[j++] = '\n';
      for(int k = 0; k < indent_level; k++){
        output[j++] = '\t';
      }
      output[j++] = input[i++];
      while(input[i] != '>'){
        output[j++] = input[i++];
      }
      output[j++] = input[i++];
      if(input[i] != '<' && input[i] != '\n'){
        output[j++] = '\n';
        for(int k = 0; k < indent_level+1; k++){
          output[j++] = '\t';
        }
        while(input[i] != '<' && input[i] != '\0'){
          output[j++] = input[i++];
        }
        output[j++] = '\n';
        i--;
      }
    }
    else{
      output[j++] = input[i++];
    }
    if(input[i] == '<' && input[i+1] == '/'){
      indent_level--;
    }
    if(input[i-1] == '<' && input[i] != '/'){
      indent_level++;
    }
  }
  
  output[j] = '\0';
  printf("\nThe beautified HTML document is:\n\n%s\n", output);

  return 0;
}