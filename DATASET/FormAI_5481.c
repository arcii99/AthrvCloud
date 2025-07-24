//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char url[1000], new_url[1000], valid_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~!$&'()*+,;=:@/?";
  int i, j, len, skip = 0;

  printf("Welcome to the C URL Sanitizer! Please enter the URL you'd like to sanitize:\n");
  fgets(url, 1000, stdin);
  len = strlen(url);

  for (i = 0, j = 0; i < len; i++) {
    if (url[i] == '/') {
      skip = 0;
    }
    if (skip == 0 && strchr(valid_chars, url[i]) != NULL) {
      new_url[j++] = url[i];
    } else {
      skip = 1;
    }
  }
  new_url[j] = '\0';

  printf("The sanitized URL is: %s\n", new_url);

  return 0;
}