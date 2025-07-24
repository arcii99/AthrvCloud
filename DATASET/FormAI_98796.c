//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Define a stack to store XML tags
char stack[MAX_STACK_SIZE];
int top = -1;

// Helper function to push a tag onto the stack
void push(char tag) {
  if (top == MAX_STACK_SIZE - 1) {
    printf("Stack overflow!\n");
    exit(1);
  }
  stack[++top] = tag;
}

// Helper function to pop a tag from the stack
char pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return stack[top--];
}

int main() {
  char xml[] = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
  int len = strlen(xml);
  int i = 0;
  bool inside_tag = false;
  bool inside_closing_tag = false;
  bool inside_body = false;
  char currentTag[MAX_STACK_SIZE] = "";
  char c;

  // Loop over the XML string
  while (i < len) {
    c = xml[i++];

    // If we are inside a tag
    if (inside_tag) {
      // If the current character is '>'
      if (c == '>') {
        inside_tag = false;

        // If this is a closing tag
        if (inside_closing_tag) {
          inside_closing_tag = false;

          // Pop the top tag from the stack and compare with the closing tag
          char topTag = pop();
          if (strcmp(topTag, currentTag) != 0) {
            printf("Error: Invalid XML structure!\n");
            exit(1);
          }
        }
        // If this is an opening tag
        else {
          // Push the tag onto the stack and reset the currentTag buffer
          push(currentTag);
          memset(currentTag, 0, MAX_STACK_SIZE);
        }
      }
      // If the current character is '/', this is a closing tag
      else if (c == '/') {
        inside_closing_tag = true;
      }
      // Otherwise, add the character to the currentTag buffer
      else {
        strncat(currentTag, &c, 1);
      }
    }
    // If we are inside the body of the XML document
    else if (inside_body) {
      // Do nothing
    }
    // Otherwise, we are outside the body and an opening tag must be coming next
    else {
      if (c == '<') {
        inside_tag = true;
      }
      // Otherwise, the document is invalid
      else {
        printf("Error: Invalid XML structure!\n");
        exit(1);
      }
    }
  }

  // If the stack is not empty, the document is invalid
  if (top != -1) {
    printf("Error: Invalid XML structure!\n");
    exit(1);
  }

  printf("XML document parsed successfully!\n");
  return 0;
}