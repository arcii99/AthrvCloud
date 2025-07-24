//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char *url) {
  // Remove whitespace from the beginning and end of the URL
  char *start = url;
  char *end = url + strlen(url) - 1;

  while (isspace(*start)) start++;
  while (isspace(*end)) end--;

  // Replace any non-alphanumeric characters with a dash
  int i;
  for (i = 0; i < strlen(url); i++) {
    if (!isalnum(url[i]))
      url[i] = '-';
  }

  // Make the URL lowercase
  for (i = 0; i < strlen(url); i++) {
    url[i] = tolower(url[i]);
  }
}

int main() {
  char *url = "   HTTP://WWW.EXAMPLE.COM/SOME-DIR/    ";
  printf("Original URL: %s\n", url);
  sanitize_url(url);
  printf("Sanitized URL: %s\n", url);
  return 0;
}