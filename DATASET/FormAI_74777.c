//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 1000
#define MAX_SANITIZE_LEN 1000

char *sanitize(char *url); // function prototype

int main() {
  char url[MAX_URL_LEN];
  printf("Enter a URL to sanitize: ");
  fgets(url, MAX_URL_LEN, stdin);
  char *sanitized_url = sanitize(url);

  printf("\nOriginal URL: %s", url);
  printf("\nSanitized URL: %s", sanitized_url);

  return 0;
}


char *sanitize(char *url) {
  char sanitized_url[MAX_SANITIZE_LEN];
  int sanitized_url_index = 0;

  for (int i = 0; i < strlen(url); i++) {
    if (isalpha(url[i]) || isdigit(url[i])) {
      sanitized_url[sanitized_url_index] = url[i];
      sanitized_url_index++;
    }
    else if (url[i] == ':') {
      sanitized_url[sanitized_url_index] = url[i];
      sanitized_url_index++;
      sanitized_url[sanitized_url_index] = '/';
      sanitized_url_index++;
      sanitized_url[sanitized_url_index] = '/';
      sanitized_url_index++;
    }
  }

  sanitized_url[sanitized_url_index] = '\0';
  char *sanitized_url_ptr = sanitized_url;
  return sanitized_url_ptr;
}