//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
/* A unique URL sanitizer program in Linus Torvalds style */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char url[1000]; // the input URL
  printf("Enter a URL to sanitize: ");
  fgets(url, sizeof(url), stdin); // get the input URL
  
  printf("\nSanitized URL:\n");

  int length = strlen(url);
  for(int i=0; i<length; i++) {
    if(isalpha(url[i])) { // if the character is alphabetic
      putchar(tolower(url[i])); // convert it to lowercase and print it
    } else if(url[i] == ':') { // if the character is a colon
      putchar(url[i]); // print it
      putchar('/'); // add two forward slashes after the colon
      putchar('/'); 
    } else if(url[i] == '/') { // if the character is a forward slash
      putchar(url[i]);
      if(i+1 < length && url[i+1] == '/') { // if the next character is also a forward slash
        i++; // skip the next character
      }
    }
  }
  putchar('\n'); // print a newline character
  return 0;
}