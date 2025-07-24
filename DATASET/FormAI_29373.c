//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

/*
Title: C Pattern Printing Introspective Chatbot
Author: [Your Name]
Date: [Date]

Description: This program generates an interesting pattern using C language loops and conditionals.
*/

int main() {
  int n = 20;

  printf("Hello, let's generate a unique pattern using C!\n");

  // Begin generating the C pattern
  for (int i = 1; i <= n; i++) {

    // Print the first vertical bar
    printf("|");

    // Conditionally print a space or an asterisk based on the parity of i
    for (int j = 1; j <= n; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          printf("*");
        } else {
          printf(" ");
        }
      } else {
        if (j % 2 == 0) {
          printf(" ");
        } else {
          printf("*");
        }
      }
    }

    // Print the last vertical bar
    printf("|\n");
  }

  printf("Done!");

  return 0;
}