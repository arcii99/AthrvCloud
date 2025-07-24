//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

void sanitize_url(char* url) {
  // check for empty or null url
  if (!url || strlen(url) == 0) {
    printf("Invalid URL\n");
    return;
  }

  // check for https protocol
  char* protocol = strstr(url, "https://");
  if (protocol == NULL) {
    // check for http protocol
    protocol = strstr(url, "http://");
    if (protocol == NULL) {
      printf("Invalid URL\n");
      return;
    }
    // replace http with https
    memmove(protocol + 6, protocol, strlen(protocol));
    memcpy(protocol, "https", 5);
  }

  // remove any trailing slashes
  int length = strlen(url);
  if (url[length - 1] == '/') {
    url[length - 1] = '\0';
  }

  // remove any query strings
  char* query_string = strstr(url, "?");
  if (query_string != NULL) {
    *query_string = '\0';
  }

  // remove any fragments
  char* fragment = strstr(url, "#");
  if (fragment != NULL) {
    *fragment = '\0';
  }

  printf("Sanitized URL: %s\n", url);
}

int main() {
  char url[MAX_URL_LENGTH] = "http://example.com/path/to/page.html?id=123#about";
  sanitize_url(url);

  char url2[MAX_URL_LENGTH] = "https://www.google.com/search?q=url+sanitizer&oq=url+sanitizer&aqs=chrome.0.0i131i433i512l2j0i131i433j0i512l5.1653j1j7&sourceid=chrome&ie=UTF-8#search/keyword";
  sanitize_url(url2);

  char url3[MAX_URL_LENGTH] = "";
  sanitize_url(url3);

  return 0;
}