//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
/* C URL Sanitizer */
/* Code by Donald Knuth style */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sanitize(char *url) {
  char *sanitized_url = (char *)malloc(strlen(url) + 1);
  int i, j = 0;

  for (i = 0; i < strlen(url); i++) {
    if (isalnum(url[i])) {
      sanitized_url[j] = url[i];
      j++;
    } else if (url[i] == '.' && (i > 0 && isalnum(url[i-1])) && (i < strlen(url) - 1 && isalnum(url[i+1]))) {
      sanitized_url[j] = url[i];
      j++;
    } else if (url[i] == '/' && (i > 0 && url[i-1] != '/') && (i < strlen(url) - 1 && url[i+1] != '/')) {
      sanitized_url[j] = url[i];
      j++;
    } else if (url[i] == '_' || url[i] == '-') {
      sanitized_url[j] = url[i];
      j++;
    }
  }
  sanitized_url[j] = '\0';

  return sanitized_url;
}

int main() {
  char url[] = "http://wWw.example.com/my-file.html";
  printf("Original URL: %s\n", url);
  
  char *sanitized_url = sanitize(url);
  printf("Sanitized URL: %s\n", sanitized_url);

  free(sanitized_url);
  return 0;
}