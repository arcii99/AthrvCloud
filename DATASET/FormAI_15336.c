//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char url[500]; // Maximum URL length is 500 characters
  char sanitizedUrl[500]; // Sanitized URL will be stored here
  int i, j = 0;

  // Prompt user for URL input
  printf("Enter a URL to sanitize: ");
  fgets(url, 500, stdin); // Gets input including spaces

  // Replace potentially harmful characters with HTML entities
  for (i = 0; url[i] != '\0'; i++) {
    switch (url[i]) {
      case '&':
        strcat(sanitizedUrl, "&amp;");
        j = j + 5; // Update index to account for addition of HTML entity
        break;
      case '<':
        strcat(sanitizedUrl, "&lt;");
        j = j + 4;
        break;
      case '>':
        strcat(sanitizedUrl, "&gt;");
        j = j + 4;
        break;
      case '"':
        strcat(sanitizedUrl, "&quot;");
        j = j + 6;
        break;
      case '\'':
        strcat(sanitizedUrl, "&#39;");
        j = j + 5;
        break;
      default:
        sanitizedUrl[j++] = url[i]; // Copy character to sanitized URL
    }
  }

  // Add null terminator to end of sanitized URL
  sanitizedUrl[j] = '\0';

  // Print sanitized URL
  printf("Sanitized URL:\n%s", sanitizedUrl);

  return 0;
}