//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url) {
  char *patterns[] = {"http://", "https://", "www.", ".com", ".org"}; // list of patterns to remove from the URL
  int num_patterns = 5; // number of patterns to remove
  for (int i = 0; i < num_patterns; i++) { // loop through each pattern
    char *match = strstr(url, patterns[i]); // find the first occurrence of the pattern in the URL
    if (match != NULL) { // if the pattern is found
      int pos = match - url; // get the position of the pattern
      memmove(&url[pos], &url[pos + strlen(patterns[i])], strlen(&url[pos + strlen(patterns[i])]) + 1); // remove the pattern from the URL
    }
  }
}

int main() {
  char url[1000];
  printf("Enter a URL to sanitize: ");
  fgets(url, 1000, stdin);
  sanitize_url(url);
  printf("Sanitized URL: %s", url);
  return 0;
}