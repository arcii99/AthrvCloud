//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitize_url(char *url);

int main() {
  char url[100];
  printf("Enter a URL: ");
  fgets(url, sizeof(url), stdin);
  printf("Sanitized URL: %s\n", sanitize_url(url));
  return 0;
}

char *sanitize_url(char *url) {
  int length = strlen(url);
  char *sanitized = (char *) malloc(sizeof(char) * (length + 1));
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_') {
      sanitized[j] = url[i];
      j++;
    }
  }
  sanitized[j] = '\0';
  return sanitized;
}