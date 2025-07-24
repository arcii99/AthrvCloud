//FormAI DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void beautify(char* html_string);

int main() {
  // read HTML string from user
  char html_string[1000];
  printf("Enter your HTML string:\n");
  fgets(html_string, 1000, stdin);

  // call the beautify function
  beautify(html_string);

  // print the beautified HTML string
  printf("\nBeautified HTML string:\n%s", html_string);
  return 0;
}

void beautify(char* html_string) {
  char* beautified_string = malloc(strlen(html_string) * sizeof(char));
  int indent_level = 0;
  int i = 0, j = 0;
  while(html_string[i] != '\0') {
    if(html_string[i] == '<') {
      if(html_string[i+1] == '/') {
        indent_level--;
        j -= 2;
      }
      for(int k = 0; k < indent_level; k++) {
        beautified_string[j] = ' ';
        j++;
      }
      indent_level++;
    }
    beautified_string[j] = html_string[i];
    j++;
    if(html_string[i] == '>') {
      beautified_string[j] = '\n';
      j++;
    }
    i++;
  }
  beautified_string[j] = '\0';
  strcpy(html_string, beautified_string);
  free(beautified_string); 
}