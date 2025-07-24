//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitizeURL(char* url) {
  int length = strlen(url);
  char* sanitizedURL = (char*) malloc(length);

  int j = 0;
  int isQuery = 0;
  int queryIndex = 0;

  for (int i = 0; i < length; i++) {
    if (url[i] == '?') {
      isQuery = 1;
      queryIndex = i;
      break;
    }
    sanitizedURL[j++] = tolower(url[i]);
  }

  if (isQuery) {
    sanitizedURL[j++] = '?';
    for (int i = queryIndex + 1; i < length; i++) {
      if (isalnum(url[i]) || url[i] == '&' || url[i] == '=') {
        sanitizedURL[j++] = url[i];
      }
    }
  }

  return sanitizedURL;
}

int main() {
  char url[1000];
  printf("Enter a URL: ");
  scanf("%[^\n]%*c", url);

  char* sanitizedURL = sanitizeURL(url);
  printf("Sanitized URL: %s\n", sanitizedURL);

  free(sanitizedURL);
  return 0;
}