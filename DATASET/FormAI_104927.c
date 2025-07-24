//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char html[5000]; // Assumes input HTML will be less than 5000 chars
  char out[5000]; // To store the beautified HTML
  char tag[100]; // To store the current tag being parsed
  int i, j, k, l, n, o, p, q, r, s;
  int indent = 0; // To keep track of the current indentation level
  int is_open_tag;
  int skip_next_char = 0;
  int tag_count = 0; // To keep track of the number of tags encountered
  int line_count = 1; // To keep track of the current line number
  printf("Enter HTML to be beautified:\n");
  fgets(html, sizeof(html), stdin); // Reads input from user

  // Loop through input HTML character by character
  for (i = 0; i < strlen(html); i++) {
    is_open_tag = 0;
    // Check if the current character is the start of a new tag
    if (html[i] == '<' && html[i+1] != '/' && !skip_next_char) {
      j = i+1;
      // Find closing bracket to determine the end of the tag name
      while (html[j] != '>') {
        j++;
      }
      k = j;
      while (html[k] != '<') {
        k++;
      }
      l = k;
      // Check if the tag is a self-closing tag
      if (html[j-1] == '/') {
        j--;
        is_open_tag = 1;
      }
      // Copy the tag name to the tag array
      for (n = 0; n < j-i-1; n++) {
        tag[n] = html[i+n+1];
      }
      tag[n] = '\0';

      // Add indentation before the tag if it's not the first tag
      if (tag_count > 0) {
        for (o = 0; o < indent; o++) {
          out[strlen(out)] = ' ';
        }
      }
      // Append the tag to the output HTML
      for (p = 0; p < j-i+1; p++) {
        out[strlen(out)] = html[i+p];
      }
      i = j;

      // Check if the tag is self-closing
      if (is_open_tag) {
        // Do nothing because there is no closing tag to worry about
      } else {
        // Look for the closing tag for this opening tag
        while (1) {
          // Check if the next tag is the current tag's closing tag
          if (html[i+1] == '/' && html[i+2] == tag[0] && html[i+3] == tag[1]) {
            // Add a newline after the opening tag and before the closing tag
            out[strlen(out)] = '\n';
            for (q = 0; q < indent+2; q++) {
              out[strlen(out)] = ' ';
            }
            // Add the closing tag to the output HTML
            for (r = i+1; r < k+2; r++) {
              out[strlen(out)] = html[r];
            }
            i = k+2;
            break;
          } else {
            // Check if the next character indicates a nested tag
            if (html[i+1] == '<' && html[i+2] != '/') {
              indent += 2;
              tag_count++;
              // Add a newline after the opening tag and before the nested tag
              out[strlen(out)] = '\n';
              for (s = 0; s < indent; s++) {
                out[strlen(out)] = ' ';
              }
              break;
            } else if (html[i+1] == '<' && html[i+2] == '/') {
              // Add a newline after the opening tag and before the closing tag
              out[strlen(out)] = '\n';
              for (q = 0; q < indent+2; q++) {
                out[strlen(out)] = ' ';
              }
              // Add the closing tag to the output HTML
              for (r = i+1; r < k+2; r++) {
                out[strlen(out)] = html[r];
              }
              i = k+2;
              indent -= 2;
              break;
            } else {
              // Add the next character to the output HTML without any changes
              out[strlen(out)] = html[i+1];
              i++;
            }
          }
        }
      }
    } else if (html[i] == '<' && html[i+1] == '/') {
      // Closing tag encountered - decrement the indentation level
      indent -= 2;
      // Add a newline before the closing tag
      out[strlen(out)] = '\n';
      for (q = 0; q < indent; q++) {
        out[strlen(out)] = ' ';
      }
    } else if (html[i] == '\n') {
      // Newline encountered - increment line count
      line_count++;
    } else if (html[i] == '!' && html[i+1] == '-' && html[i+2] == '-') {
      // Comment tag encountered
      j = i+1;
      // Find the end of the comment tag
      while (html[j] != '-' || html[j+1] != '-' || html[j+2] != '>') {
        j++;
      }
      // Append the comment tag to the output HTML
      for (p = i; p < j+3; p++) {
        out[strlen(out)] = html[p];
      }
      i = j+2;
    } else {
      // Any other character should just be added to the output HTML
      if (!skip_next_char) {
        out[strlen(out)] = html[i];
      } else {
        // Skip this character if it's part of an HTML entity
        skip_next_char = 0;
      }
      // Check if this character is the start of an HTML entity
      if (html[i] == '&') {
        j = i+1;
        // Find the end of the HTML entity
        while (html[j] != ';') {
          j++;
        }
        // Append the HTML entity to the output HTML
        for (p = i; p < j+1; p++) {
          out[strlen(out)] = html[p];
        }
        i = j;
        skip_next_char = 1;
      }
    }
  }

  // Print the beautified HTML to the console
  printf("%s", out);

  return 0;
}