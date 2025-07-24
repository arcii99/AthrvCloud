//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

char* sanitize_url(char url[]) {
  char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
  int url_length = strlen(url);
  int i, j = 0;
  for (i = 0; i < url_length; i++) {
    if (isalnum(url[i]) || url[i] == ' ' || url[i] == '-' || url[i] == '_') {
      sanitized_url[j++] = url[i];
    } else if (url[i] == '%') {
      if (i + 2 < url_length && isxdigit(url[i + 1]) && isxdigit(url[i + 2])) {
        sanitized_url[j++] = url[i++];
        sanitized_url[j++] = url[i++];
        sanitized_url[j++] = url[i];
      } else {
        sanitized_url[j++] = '%';
      }
    } else if (url[i] == '+') {
      sanitized_url[j++] = ' ';
    } else if (url[i] == '?') {
      sanitized_url[j++] = url[i];
      break;
    }
  }
  return sanitized_url;
}

int main() {
  char url[MAX_URL_LENGTH];
  printf("Enter a URL to sanitize:\n");
  fgets(url, MAX_URL_LENGTH, stdin);
  char* sanitized_url = sanitize_url(url);
  printf("Sanitized URL:\n%s\n", sanitized_url);
  free(sanitized_url);
  return 0;
}