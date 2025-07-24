//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to sanitize a URL
void sanitize_url(char* url) {
  
  // Remove unnecessary characters
  char* bad_chars = "<>|[]{}\\\"";
  int len = strlen(bad_chars);
  for (int i = 0; i < len; i++) {
    char* pos = strchr(url, bad_chars[i]);
    if (pos != NULL) {
      memmove(pos, pos + 1, strlen(pos));
      len--;
    }
  }
  
  // Remove leading and trailing whitespaces
  len = strlen(url);
  while (len > 0 && isspace(url[len - 1]))
    len--;
  url[len] = '\0';
  while (*url && isspace(*url))
    url++;
  
  // Make sure the protocol is valid
  char* prefixes[] = {"http://", "https://", "ftp://"};
  int num_prefixes = sizeof(prefixes) / sizeof(prefixes[0]);
  int i;
  for (i = 0; i < num_prefixes && strncmp(url, prefixes[i], strlen(prefixes[i])) != 0; i++);
  
  if (i >= num_prefixes) {
    fprintf(stderr, "Invalid protocol\n");
    return;
  }
  
  // Make sure there are no repeated slashes in the path
  char* path = strchr(url, '/');
  while (path != NULL) {
    char* next_slash = strchr(path + 1, '/');
    if (next_slash != NULL && *(next_slash - 1) == '/')
      memmove(next_slash - 1, next_slash, strlen(next_slash) + 1);
    else
      path = next_slash;
  }
  
  // Remove any embedded whitespace
  char* p = url;
  while (*p) {
    if (isspace(*p)) {
      memmove(p, p + 1, strlen(p));
    } else {
      p++;
    }
  }
}

int main() {
  char url[1024];
  printf("Enter a URL: ");
  fgets(url, 1024, stdin);
  
  // Remove newline character
  url[strcspn(url, "\n")] = '\0';
  
  sanitize_url(url);
  printf("Sanitized URL is: %s\n", url);
  
  return 0;
}