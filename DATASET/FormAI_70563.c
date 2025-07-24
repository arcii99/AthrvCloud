//FormAI DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_indent(int num_spaces) {
  int i;
  for (i = 0; i < num_spaces; i++) {
    printf(" ");
  }
}

int main() {
  char* input_html = "<html><head><title>My website</title></head><body><div><p>Welcome to my site!</p></div></body></html>";
  char* output_html = malloc(strlen(input_html) * sizeof(char));
  int num_spaces = 0;

  int i;
  for (i = 0; i < strlen(input_html); i++) {
    if (input_html[i] == '<') {
      output_html[strlen(output_html)] = '\n';
      print_indent(num_spaces);
      output_html[strlen(output_html)] = '<';
      if (input_html[i + 1] != '/') {
        num_spaces += 2;
        output_html[strlen(output_html)] = '\n';
        print_indent(num_spaces);
      } else {
        num_spaces -= 2;
      }
    }
    output_html[strlen(output_html)] = input_html[i];
    if (input_html[i] == '>') {
      if (input_html[i - 1] != '/') {
        num_spaces += 2;
        output_html[strlen(output_html)] = '\n';
        print_indent(num_spaces);
      } else {
        output_html[strlen(output_html)] = '\n';
        print_indent(num_spaces);
      }
    }
  }

  printf("%s", output_html);

  free(output_html);

  return 0;
}