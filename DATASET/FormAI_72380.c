//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
  char url[100];
  printf("Enter URL: ");
  scanf("%s", url);
  
  // Removing http or https prefix
  if(strncmp(url, "http://", 7) == 0) {
    memmove(url, url+7, strlen(url)-6);
  } else if(strncmp(url, "https://", 8) == 0) {
    memmove(url, url+8, strlen(url)-7);
  }

  // Removing query parameters
  char *questionMark = strchr(url, '?');
  if(questionMark != NULL) {
    *questionMark = '\0';
  }

  // Removing trailing slash
  int len = strlen(url);
  if(url[len-1] == '/') {
    url[len-1] = '\0';
  }

  printf("Sanitized URL: %s\n", url);
  return 0;
}