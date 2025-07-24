//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sanitize(char* url) {
  // Step 0: Check if the url is NULL
  if (url == NULL) {
    printf("The url is NULL\n");
    return "";
  }

  // Step 1: Convert the url to lowercase
  int len = strlen(url);
  for (int i = 0; i < len; i++) {
    url[i] = tolower(url[i]);
  }

  // Step 2: Remove any trailing slashes
  if (url[len - 1] == '/') {
    url[len - 1] = '\0';
    len--;
  }

  // Step 3: Replace any space characters with %20
  for (int i = 0; i < len; i++) {
    if (url[i] == ' ') {
      url[i] = '%';
      url[i + 1] = '2';
      url[i + 2] = '0';
      len += 2;
    }
  }

  // Step 4: Remove any leading "./" strings
  if (strncmp(url, "./", 2) == 0) {
    memmove(&url[0], &url[2], len - 2);
    len -= 2;
  }

  // Step 5: Remove any leading "/" characters
  if (url[0] == '/') {
    memmove(&url[0], &url[1], len - 1);
    len--;
  }

  // Step 6: Remove any duplicate "/" characters
  for (int i = 0; i < len - 1; i++) {
    if (url[i] == '/' && url[i + 1] == '/') {
      memmove(&url[i], &url[i + 1], len - i);
      len--;
      i--;
    }
  }

  // Step 7: Remove any trailing "/." strings
  if (strncmp(&url[len - 2], "/.", 2) == 0) {
    url[len - 2] = '\0';
    len -= 2;
  }

  return url;
}

int main() {
  char url[] = "htTps://WWW.exaMPLE.com:80/hELLO%20%20world/%2e%2f%2ebase/";
  printf("Before sanitization: %s\n", url);

  char* sanitized_url = sanitize(url);
  printf("After sanitization: %s\n", sanitized_url);

  return 0;
}