//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INDENT "    "
#define TAG_TYPE_OPEN 1
#define TAG_TYPE_CLOSE 2
#define TAG_TYPE_SELF_CLOSING 3

char* beautify_html(char* input) {
  char* output = malloc(strlen(input) + 1);
  int length = strlen(input);
  int indent_level = 0;
  int tag_type = TAG_TYPE_OPEN;
  int in_tag = 0;
  int in_quotes = 0;

  // Loop through the input, character by character
  for (int i = 0; i < length; i++) {
    char c = input[i];

    // Handle quotes first
    if (c == '"' || c == '\'') {
      if (!in_quotes) {
        in_quotes = c;
      } else if (in_quotes == c) {
        in_quotes = 0;
      }
    }

    // Handle tags
    if (!in_quotes) {
      if (c == '<') {
        in_tag = 1;

        if (input[i+1] == '/') {
          tag_type = TAG_TYPE_CLOSE;
        } else if (input[i+1] == '!') {
          // Do nothing for comments
        } else if (input[i+1] == '?') {
          // Do nothing for processing instructions
        } else if (isspace(input[i+1]) || input[i+1] == '>') {
          tag_type = TAG_TYPE_SELF_CLOSING;
        } else {
          tag_type = TAG_TYPE_OPEN;
        }

        if (tag_type != TAG_TYPE_CLOSE) {
          printf("\n");
          for (int j = 0; j < indent_level; j++) {
            printf(INDENT);
          }
        }
      } else if (c == '>') {
        in_tag = 0;

        if (tag_type == TAG_TYPE_SELF_CLOSING) {
          printf("\n");
          for (int j = 0; j < indent_level; j++) {
            printf(INDENT);
          }
        }

        if (tag_type == TAG_TYPE_OPEN && input[i-1] != '/') {
          indent_level++;
        } else if (tag_type == TAG_TYPE_CLOSE) {
          indent_level--;
        }
      }
    }

    // Output the character
    printf("%c", c);
  }

  return output;
}

int main(int argc, char** argv) {
  char* input = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<p>This is an example paragraph.</p>\n</body>\n</html>";
  char* output = beautify_html(input);
  printf("\n\nOutput:\n\n%s", output);

  free(output);
  return 0;
}