//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

void sanitizeUrl(char *url) {
  // Remove any trailing whitespace
  int len = strlen(url);
  while (len > 0 && isspace(url[len-1])) {
    len--;
    url[len] = '\0';
  }

  // Check if the url starts with "http://" or "https://"
  if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
    printf("Invalid URL format. Please add 'http://' or 'https://' to the beginning of the URL.");
    return;
  }

  // Remove any leading or trailing '/', and replace any multiple '/'s with a single one
  char *newUrl = url;
  int lastChar = strlen(url) - 1;
  if (newUrl[lastChar] == '/') {
    newUrl[lastChar] = '\0';
  }
  while (*newUrl == '/') {
    newUrl++;
  }
  char *lastSlash = newUrl;
  char *curr = newUrl;
  while (*curr != '\0') {
    if (*curr == '/') {
      if (curr != lastSlash) {
        lastSlash++;
        *lastSlash = '/';
      }
    } else {
      lastSlash++;
      *lastSlash = *curr;
    }
    curr++;
  }
  lastSlash++;
  *lastSlash = '\0';
  printf("Sanitized URL: %s", newUrl);
}

int main() {
  char url[100];
  printf("Enter a URL to sanitize: ");
  fgets(url, sizeof(url), stdin);
  sanitizeUrl(url);
  return 0;
}