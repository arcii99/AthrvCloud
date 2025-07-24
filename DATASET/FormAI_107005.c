//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize_url(char *url) {
  char *scheme_end = strstr(url, "://");
  if (scheme_end == NULL) {
    return;
  }

  char *url_start = scheme_end + 3;
  char *query_start = strchr(url_start, '?');
  if (query_start == NULL) {
    query_start = url + strlen(url);
  }

  char *p = url_start;
  char *q = url_start;

  while (*p != '\0' && p < query_start) {
    if (!isalnum(*p) && *p != '-' && *p != '_' && *p != '.') {
      p++;
      continue;
    }

    *q = tolower(*p);
    p++;
    q++;
  }

  *q = '\0';
  memmove(url, url_start, strlen(url_start) + 1); // move the sanitized url to the beginning

  // remove trailing '/'
  if (url[strlen(url) - 1] == '/') {
    url[strlen(url) - 1] = '\0';
  }
}

int main() {
  char urls[5][100] = {
    "https://www.example.com/path/to/page?foo=1&bar=2",
    "ftp://ftp.example.com/path/to/folder/file.txt",
    "http://example.com",
    "https://www.example.com/path/?=to/page",
    "https://www.example.com/path/to/?@page=1"
  };

  for (int i = 0; i < 5; i++) {
    char url[100];
    strcpy(url, urls[i]);

    printf("Original Url: %s\n", url);
    sanitize_url(url);
    printf("Sanitized Url: %s\n\n", url);
  }

  return 0;
}