//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_code(char* code) {

  int indent_level = 0;
  int code_length = strlen(code);
  char* beautified_code = (char*)malloc((code_length + 1) * sizeof(char));

  for(int i = 0, j = 0; i < code_length; i++) {
    if (code[i] == '<' && code[i+1] == '/') {
      indent_level--;
      j -= 2;
    }
    for(int k = 0; k < indent_level; k++) {
      beautified_code[j+k] = '\t';
    }
    beautified_code[j] = code[i];
    j++;
    if (code[i] == '<' && code[i+1] != '/') {
      indent_level++;
      beautified_code[j] = '\n';
      j++;
    }
  }

  beautified_code[code_length] = '\0';
  strcpy(code, beautified_code);

  printf("\n\nBEAUTIFIED CODE:\n");
  printf("%s", code);
  free(beautified_code);

}

int main() {

  char* code = "<html><head><title>My Webpage</title></head><body><h1>Welcome to my webpage!</h1><p>Here's some text!</p></body></html>";
  printf("ORIGINAL CODE:\n");
  printf("%s", code);
  beautify_code(code);

  return 0;

}