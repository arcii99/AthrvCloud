//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* This program sanitizes URLs to prevent malicious code injection. */
int main() {
  char url[500]; // assume maximum URL length of 500 characters
  bool isValid = false; // flag to keep track of valid input

  printf("Enter a URL to sanitize:\n");    
  fgets(url, 500, stdin); // get user input

  /* Remove newline character from string */
  int len = strlen(url);
  if (url[len-1] == '\n') {
     url[len-1] = '\0';
  }

  /* Check if URL starts with "http://" or "https://" */
  if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
    /* URL is valid */
    isValid = true;
  } else {
    /* URL is invalid */
    printf("Invalid URL. URL must start with http:// or https://\n");
  }

  /* Check if URL contains any malicious characters */
  if (isValid) {
    char* mal_chars[] = {"<", ">", "'", "\"", "%3C", "%3E", "%27", "%22", ";", "(", ")", "&", "+", "%20", "%28", "%29", "%3B", "%26", "%2B"};
    for (int i = 0; i < sizeof(mal_chars) / sizeof(char*); i++) {
      if (strstr(url, mal_chars[i]) != NULL) {
        isValid = false; // URL contains malicious character
        printf("Invalid URL. URL contains a malicious character: %s\n", mal_chars[i]);
        break;
      }
    }
  }

  /* Print sanitized URL */
  if (isValid) {
    printf("Sanitized URL: %s\n", url);
  }

  return 0;
}