//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
/* Alan Turing style URL sanitizer */

#include <stdio.h>
#include <string.h>

int main() {

  printf("Welcome to the Alan Turing URL sanitizer!\n");

  char url[1000]; // our input URL string
  char newUrl[1000]; // our sanitized URL string
  int i = 0; // counter for our loop through input URL
  int j = 0; // counter for our loop through sanitized URL

  printf("\nEnter an URL with potential unallowed characters: ");
  scanf("%s", url);

  while (url[i]) { // loop through input URL string

    char c = url[i]; // get current character in loop

    if (c == '\n') {
      break; // exit loop if newline is found
    }
    else if (c == ' ') {
      newUrl[j] = '+'; // replace spaces with '+'
    }
    else if (c == '\"' || c == '\'' || c == '<' || c == '>' || c == '\\') {
      // remove unallowed characters
    }
    else { // add any other character to sanitized URL
      newUrl[j] = c;
    }
    i++;
    j++;
  }

  newUrl[j] = '\0'; // terminate sanitized URL string

  printf("\nYour original URL: %s", url);
  printf("\nYour sanitized URL: %s\n", newUrl);

  return 0;
}