//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 512

void sanitize_url(char* url) {
  char tmp[MAX_URL_LENGTH];
  size_t len = strlen(url);
  int i, j;

  for (i = 0, j = 0; i < len; i++) {
    if (url[i] == ':' && url[i+1] == '/') {
      continue; // skip over the protocol
    } else if (url[i] == '/' && url[i+1] == '/') {
      i += 2; // move past the double slash
      continue;
    }

    tmp[j++] = url[i];
  }

  tmp[j] = '\0';
  strncpy(url, tmp, MAX_URL_LENGTH);
}

int main() {
  char url[MAX_URL_LENGTH];

  printf("Enter a URL to sanitize: ");
  fgets(url, MAX_URL_LENGTH, stdin);

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}